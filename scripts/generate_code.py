import os
import re
import util

"""
    generates c/c++ files from the specification documents
"""
def mako_spec_cpp(path, namespace, tags, specs, meta, ext):
    loc = 0
    template = "spec%s.mako"%ext
    fin = os.path.join("templates", template)

    files = []
    for s in specs:
        filename = "%s_%s%s"%(namespace, s['name'], ext)
        files.append(filename)
        fout = os.path.join(path, filename)

        print("Generating %s..."%fout)
        loc += util.makoWrite(
            fin, fout,
            name = s['name'],
            header = s['header'],
            objects = s['objects'],
            section=os.path.basename(path),
            namespace=namespace,
            tags=tags,
            specs=specs,
            meta = meta)
    return loc, files

"""
    generates c/c++ files from the specification documents
"""
def mako_api_cpp(path, namespace, tags, specs, meta, files, ext):
    template = "api%s.mako"%ext
    fin = os.path.join("templates", template)

    filename = "%s_api%s"%(namespace,ext)
    fout = os.path.join(path, filename)

    print("Generating %s..."%fout)
    return util.makoWrite(
        fin, fout,
        section=os.path.basename(path),
        namespace=namespace,
        tags=tags,
        specs=specs,
        meta=meta,
        files=files)

"""
    generates c/c++ files from the specification documents
"""
def mako_lib_cpp(path, namespace, tags, specs, meta):
    loc = 0
    template = "lib.cpp.mako"
    fin = os.path.join("templates", template)

    files = []
    for s in specs:
        filename = "%s_%s.cpp"%(namespace, s['name'])
        files.append(filename)
        fout = os.path.join(path, filename)

        print("Generating %s..."%fout)
        loc += util.makoWrite(
            fin, fout,
            name = s['name'],
            header = s['header'],
            objects = s['objects'],
            section=os.path.basename(path),
            namespace=namespace,
            tags=tags,
            specs=specs,
            meta = meta)
    return loc, files

"""
    generates c/c++ files from the specification documents
"""
def mako_cmake_cpp(path, namespace, files):
    template = "lib.cmake.mako"
    fin = os.path.join("templates", template)

    filename = "CMakeLists.txt"
    fout = os.path.join(path, filename)

    print("Generating %s..."%fout)
    return util.makoWrite(
        fin, fout,
        n=namespace,
        files=files)

"""
    generates c/c++ files from the specification documents
"""
def mako_loader_cpp(path, section, namespace, tags, specs, meta):
    template = "loader.cpp.mako"
    fin = os.path.join("templates", template)

    name = "%s_loader"%section
    filename = "%s.cpp"%(name)
    fout = os.path.join(path, filename)

    print("Generating %s..."%fout)
    return util.makoWrite(
        fin, fout,
        name=name,
        namespace=namespace,
        tags=tags,
        specs=specs,
        meta=meta)

"""
    generates c/c++ files from the specification documents
"""
def mako_validation_layer_cpp(path, section, namespace, tags, specs, meta):
    dstpath = os.path.join(path, "validation")
    template = "validation.cpp.mako"
    fin = os.path.join("templates", template)

    name = "%s_layer"%section
    filename = "%s.cpp"%(name)
    fout = os.path.join(dstpath, filename)

    print("Generating %s..."%fout)
    return util.makoWrite(
        fin, fout,
        name=name,
        namespace=namespace,
        tags=tags,
        specs=specs,
        meta=meta)

"""
    generates c/c++ files from the specification documents
"""
def generate_api_cpp(path, namespace, tags, specs, meta):
    util.makePath(path)
    util.removeFiles(path, "*.h")
    util.removeFiles(path, "*.hpp")
    util.removeFiles(path, "*.inl")

    hloc, hfiles = mako_spec_cpp(path, namespace, tags, specs, meta, ".h")
    hpploc, hppfiles = mako_spec_cpp(path, namespace, tags, specs, meta, ".hpp")

    hloc += mako_api_cpp(path, namespace, tags, specs, meta, hfiles, ".h")
    hpploc += mako_api_cpp(path, namespace, tags, specs, meta, hppfiles, ".hpp")

    return hloc + hpploc

"""
    generates c/c++ files from the specification documents
"""
def generate_lib_cpp(path, namespace, tags, specs, meta):
    util.makePath(path)
    util.removeFiles(path, "*.cpp")

    loc, files = mako_lib_cpp(path, namespace, tags, specs, meta)

    mako_cmake_cpp(path, namespace, files)

    return loc

"""
Entry-point:
    generates api code
"""
def generate_api(path, namespace, tags, specs, meta):
    loc = 0
    loc += generate_api_cpp(path, namespace, tags, specs, meta)
    print("Generated %s lines of code.\n"%loc)

"""
Entry-point:
    generates lib code
"""
def generate_lib(path, namespace, tags, specs, meta):
    loc = 0
    loc += generate_lib_cpp(path, namespace, tags, specs, meta)
    print("Generated %s lines of code.\n"%loc)

"""
Entry-point:
    generates loader for level_zero driver
"""
def generate_loader(path, section, namespace, tags, specs, meta):
    dstpath = os.path.join(path, "loader")
    util.makePath(dstpath)

    loc = 0
    loc += mako_loader_cpp(dstpath, section, namespace, tags, specs, meta)
    return loc

"""
Entry-point:
    generates validation layer for level_zero driver
"""
def generate_layers(path, section, namespace, tags, specs, meta):
    dstpath = os.path.join(path, "layers")
    util.makePath(dstpath)

    loc = 0
    loc += mako_validation_layer_cpp(dstpath, section, namespace, tags, specs, meta)
    return loc
