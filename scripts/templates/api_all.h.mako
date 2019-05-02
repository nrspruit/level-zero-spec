<%
import re
from templates import helper as th
%><%
    n=namespace
    N=n.upper()
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
* @file ${n}_all.h
*
* @cond DEV
* DO NOT EDIT: generated from /scripts/templates/api_all.h.mako
* @endcond
*
******************************************************************************/
#ifndef _${N}_ALL_H
#define _${N}_ALL_H
#if defined(__cplusplus)
#pragma once
#endif

%for f in files:
%if not re.match(r"\w+_common", f):
#include "${f}"
%endif
%endfor

///////////////////////////////////////////////////////////////////////////////
typedef struct _${n}_apitable_t
{
    %for obj in th.extract_objs(specs, r"function"):
    %if 'condition' in obj:
    #if ${th.subt(n, tags, obj['condition'])}
    %endif
    ${n}_${th.append_ws(th.make_pfn_name(n, tags, obj)+"_t", 47)} ${th.make_pfn_name(n, tags, obj)};
    %if 'condition' in obj:
    #endif // ${th.subt(n, tags, obj['condition'])}
    %endif
    %endfor
} ${n}_apitable_t;

#endif // _${N}_ALL_H