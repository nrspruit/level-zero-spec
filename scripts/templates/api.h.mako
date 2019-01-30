<%!
import re

def sub(repl, string, tag=False):
    string = re.sub(r"\$Xx", repl.title(), string)
    repl = "::"+repl if tag else repl
    string = re.sub(r"\$x", repl, string)
    string = re.sub(r"\$X", repl.upper(), string)
    return string

def append(string, count):
    while len(string) > count:
        count = count + 4
    string = '{str: <{width}}'.format(str=string, width=count)
    return string

def split_line(line, ch_count):
    if not line:
        return []
    words           = line.split(" ")
    lines           = []
    word_list       = []
    for word in words:
        if re.match(r"(.*)\n", word):
            word_list.append(re.sub(r"(.*)\n",r"\1",word))
            lines.append(" ".join(word_list))
            word_list = []
        elif sum(map(len, word_list)) + len(word_list) + len(word) <= ch_count:
            word_list.append(word)
        else:
            lines.append(" ".join(word_list))
            word_list = [word]
    if len(word_list):
        lines.append(" ".join(word_list))
    return lines

def make_line(lformat, rformat, repl, a, b, c):
    rhalf = lformat%(sub(repl,a), sub(repl,b))
    lhalf = rformat%(sub(repl,c,True))
    return "%s%s"%(append(rhalf, 48), lhalf)

def eline(repl, item):
    if 'value' in item:
        return make_line("%s = %s,", "///< %s", repl, item['name'], item['value'], item['desc'])
    else:
        return make_line("%s%s,", "///< %s", repl, item['name'], "", item['desc'])

def mline(repl, item):
    return make_line("%s %s;", "///< %s", repl, item['type'], item['name'], item['desc'])

def pline(repl, item, more):
    lformat = "%s %s," if more else "%s %s"
    return make_line(lformat, "///< %s", repl, item['type'], item['name'], item['desc'])

%>/**************************************************************************//**
*
* INTEL CONFIDENTIAL
* Copyright 2019
* Intel Corporation All Rights Reserved.
*
* The source code contained or described herein and all documents related to the
* source code ("Material") are owned by Intel Corporation or its suppliers or
* licensors. Title to the Material remains with Intel Corporation or its suppliers
* and licensors. The Material contains trade secrets and proprietary and confidential
* information of Intel or its suppliers and licensors. The Material is protected by
* worldwide copyright and trade secret laws and treaty provisions. No part of the
* Material may be used, copied, reproduced, modified, published, uploaded, posted
* transmitted, distributed, or disclosed in any way without Intel's prior express
* written permission.
*
* No license under any patent, copyright, trade secret or other intellectual
* property right is granted to or conferred upon you by disclosure or delivery
* of the Materials, either expressly, by implication, inducement, estoppel
* or otherwise. Any license under such intellectual property rights must be
* express and approved by Intel in writing.
*
* @file ${x}_${name}.h
*
* @brief ${sub(x, header['desc'])}
*
* @cond DEV
* DO NOT EDIT: generated from /scripts/<type>/${name}.yml
* @endcond
*
******************************************************************************/
#ifndef _${X}_${name.upper()}_H
#define _${X}_${name.upper()}_H
#if defined(__cplusplus)
#pragma once
#endif
%if re.match(r"common", name):
#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
typedef float  float_t;
typedef double double_t;

%else:
#include "${x}_common.h"

%endif
%for obj in objects:
///////////////////////////////////////////////////////////////////////////////
%if 'condition' in obj:
#if ${sub(x,obj['condition'])}
%endif
%for line in split_line(sub(x, obj['desc'], True), 70):
    %if loop.index < 1:
/// @brief ${line}
    %else:
///        ${line}
    %endif
%endfor
%if 'details' in obj:
/// 
/// @details
%for item in obj['details']:
    %for line in split_line(sub(x, item, True), 70):
        %if loop.index < 1:
///     - ${line}
        %else:
///       ${line}
        %endif
    %endfor
%endfor
%endif
%if 'analogue' in obj:
/// 
/// @remarks
///   _Analogues_
    %for line in obj['analogue']:
///     - ${line}
    %endfor
%endif
%if re.match(r"macro", obj['type']):
#define ${sub(x, obj['name'])}  ${sub(x, obj['value'])}
%if 'altvalue' in obj:
#else
#define ${sub(x, obj['name'])}  ${sub(x, obj['altvalue'])}
%endif
%elif re.match(r"typedef", obj['type']):
typedef ${sub(x, obj['value'])} ${sub(x, obj['name'])};
%elif re.match(r"enum", obj['type']):
typedef enum _${sub(x, obj['name'])}
{
    %for etor in obj['etors']:
    ${eline(x, etor)}
    %endfor

} ${sub(x, obj['name'])};
%elif re.match(r"struct", obj['type']):
typedef struct _${sub(x, obj['name'])}
{
    %for member in obj['members']:
    ${mline(x, member)}
    %endfor

} ${sub(x, obj['name'])};
%elif re.match(r"function", obj['type']):
/// 
/// @returns
///     - ::${X}_RESULT_SUCCESS
///     - ::${X}_RESULT_ERROR_UNINITIALIZED
%for item in obj['returns']:
    %if isinstance(item, dict):
    %for key, values in item.items():
///     - ${sub(x, key, True)}
        %for val in values:
///         + ${sub(x, val, True)}
        %endfor
    %endfor
    %else:
///     - ${sub(x, item, True)}
    %endif
%endfor
${x}_result_t __${x}call
  ${sub(x, obj['name'])}(
    %for param in obj['params']:
    ${pline(x, param, loop.index < len(obj['params'])-1)}
    %endfor
    );
%elif re.match(r"handle", obj['type']):
#if defined( __cplusplus )
struct ${sub(x, obj['name'])}
{
    void* pDriverData;

    ${sub(x, obj['name'])}( void ) : pDriverData( nullptr ) {}        ///< default constructor
    explicit ${sub(x, obj['name'])}( void* p ) : pDriverData( p ) {}  ///< initialize from pointer

    inline bool operator==( const ${sub(x, obj['name'])}& other ) const   ///< is equal to other
    { return pDriverData == other.pDriverData; }
    inline bool operator!=( const ${sub(x, obj['name'])}& other ) const   ///< not equal to other
    { return pDriverData != other.pDriverData; }

};
#else
typedef void* ${sub(x, obj['name'])};
#endif // defined( __cplusplus )
%endif
%if 'condition' in obj:
#endif // ${sub(x,obj['condition'])}
%endif

%endfor
#endif // _${X}_${name.upper()}_H
