"""
 Copyright (C) 2019 Intel Corporation

 SPDX-License-Identifier: MIT

"""
import argparse
import util
import parse_specs
import generate_code
import generate_docs
import os, sys
import time
import subprocess

"""
    helper for adding mutually-exclusive boolean arguments "--name" and "--!name"
"""
def add_argument(parser, name, help, default=False):
    group = parser.add_mutually_exclusive_group(required=False)
    group.add_argument("--" + name, dest=name, help="Enable "+help, action="store_true")
    group.add_argument("--!" + name, dest=name, help="Disable "+help, action="store_false")
    parser.set_defaults(**{name:default})

"""
    helper for cleaning previously generated files
"""
def clean():
    util.removeFile(util.jsonRead("generated.json"))
    util.removePath("../include")
    util.makePath("../include")
    util.removePath("../build")
    util.makePath("../build")

"""
    help for updating spec documentation
"""
def update_spec(target):
    inc = "%s/source/elements/l0/include" % target
    src = "%s/source/elements/l0/source" % target
    util.copyTree("../include", inc)
    util.copyTree("../docs/source", src)
    util.removePath("%s/experimental" % inc)
    util.removePath("%s/experimental" % src)


"""
    helper for running cmake windows build
"""
def build():
    result = os.system('cmake -B ../build/ -S .. -G "Visual Studio 16 2019" -A x64')
    if result == 0:
        result = os.system('cmake --build ../build --clean-first')
    return result == 0

"""
    helper for getting revision number from git repository
    revision is number of commits since tag 'v0'
"""
def revision():
    result = subprocess.run(['git', 'describe', '--tags', '--dirty'], cwd=os.path.dirname(os.path.abspath(__file__)), stdout=subprocess.PIPE)
    if result.returncode:
        print('ERROR: Could not get revision number from git', file=sys.stderr)
        return '0'

    items = result.stdout.decode().strip().split('-')
    tag = items[0][1:] # remove 'v'
    count = int(items[1])

    # Bump count if any local files are dirty.  
    # Keeps the count the same after doing a commit (assuming all dirty files are committed)
    if 'dirty' in items[-1]:
        count += 1
    return '%s.%s'%(tag, count)


"""
Main entry:
    Do everything...
"""
def main():
    # parse cmdline arguments
    configParser = util.configRead("config.ini")

    # define cmdline arguments
    parser = argparse.ArgumentParser()
    for section in configParser.sections():
        add_argument(parser, section, "generation of C/C++ '%s' files."%section, True)
    add_argument(parser, "clean", "cleaning previous generated files.")
    add_argument(parser, "lib", "generation of lib files.", True)
    add_argument(parser, "loader", "generation of loader files.", True)
    add_argument(parser, "layers", "generation of validation layer files.", True)
    add_argument(parser, "drivers", "generation of null driver files.", True)
    add_argument(parser, "wrapper", "generation of c++ wrapper files.", True)
    add_argument(parser, "build", "running cmake to generate and build projects.")
    add_argument(parser, "debug", "dump intermediate data to disk.")
    add_argument(parser, "html", "generation of HTML files.", True)
    add_argument(parser, "pdf", "generation of PDF file.")
    add_argument(parser, "rst", "generation of reStructuredText files.", True)
    parser.add_argument("--update_spec", type=str, help="root of integrated spec directory to update")
    parser.add_argument("--ver", type=str, default="1.0", required=False, help="specification version to generate.")
    args = vars(parser.parse_args())
    args['rev'] = revision()

    start = time.time()

    if args['clean']:
        clean()

    specs = None

    srcpath = os.path.join("../source/")
    docpath = os.path.join("../docs/")

    generate_docs.prepare(docpath, args['rst'], args['html'], args['ver'])

    # generate code
    for idx, section in enumerate(configParser.sections()):
        namespace = configParser.get(section,'namespace')
        tags={}
        for key in configParser.get(section,'tags').split(","):
            tags['$'+key] = configParser.get(section,key)

        ymlpath = os.path.join("./", section)
        incpath = os.path.join("../include/")
        rstpath = os.path.join(docpath, "source", section)

        if args[section] and util.exists(ymlpath):
            if specs:
                specs = parse_specs.parse(ymlpath, args['ver'], tags, specs[1], specs[2])
            else:
                specs = parse_specs.parse(ymlpath, args['ver'], tags)

            if len(specs) > 0:
                if args['debug']:
                    util.jsonWrite(os.path.join(ymlpath, "specs.json"), specs[0])
                    util.jsonWrite(os.path.join(ymlpath, "meta.json"), specs[1])

                generate_code.generate_api(incpath, namespace, tags, args['ver'], args['rev'], specs[0], specs[1])

                if args['lib']:
                    generate_code.generate_lib(srcpath, section, namespace, tags, args['ver'], args['rev'], specs[0], specs[1])

                if args['loader']:
                    generate_code.generate_loader(srcpath, section, namespace, tags, args['ver'], args['rev'], specs[0], specs[1])

                if args['layers']:
                    generate_code.generate_layers(srcpath, section, namespace, tags, args['ver'], args['rev'], specs[0], specs[1])

                if args['drivers']:
                    generate_code.generate_drivers(srcpath, section, namespace, tags, args['ver'], args['rev'], specs[0], specs[1])

                if args['wrapper']:
                    generate_code.generate_wrapper(srcpath, section, namespace, tags, args['ver'], args['rev'], specs[0], specs[1])

            if args['rst']:
                generate_docs.generate_rst(ymlpath, rstpath, tags, args['ver'], args['rev'], specs[1], specs[0])

    if util.makeErrorCount():
        print("\n%s Errors found during generation, stopping execution!"%util.makeErrorCount())
        return

    if args['debug']:
        util.makoFileListWrite("generated.json")

    if specs:
        generate_docs.generate_ref(docpath, specs[2])

    # build code
    if args['build']:
        if not build():
            print("\nBuild failed, stopping execution!")
            return

    # generate documentation
    if args['html']:
        generate_docs.generate_html(docpath, configParser.sections(), args['ver'], args['rev'])

    if args['pdf']:
        generate_docs.generate_pdf(docpath)

    if args['update_spec']:
        update_spec(args['update_spec'])

    print("\nCompleted in %.1f seconds!"%(time.time() - start))

if __name__ == '__main__':
    main()
# END OF FILE
