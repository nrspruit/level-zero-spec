/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file xex_ddi.h
 *
 * @cond DEV
 * DO NOT EDIT: generated from /scripts/experimental
 * @endcond
 *
 */
#ifndef _XEX_DDI_H
#define _XEX_DDI_H
#if defined(__cplusplus)
#pragma once
#endif
#include "xex_api.h"

#if defined(__cplusplus)
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for xexInit 
typedef xe_result_t (__xecall *xex_pfnInit_t)(
    xe_init_flag_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of Global functions pointers
typedef struct _xex_global_dditable_t
{
    xex_pfnInit_t                                               pfnInit;
} xex_global_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Global table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + invalid value for version
///         + nullptr for pDdiTable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xexGetGlobalProcAddrTable(
    xe_api_version_t version,                       ///< [in] API version requested
    xex_global_dditable_t* pDdiTable                ///< [in,out] pointer to table of DDI function pointers
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for xexGetGlobalProcAddrTable
typedef xe_result_t (__xecall *xex_pfnGetGlobalProcAddrTable_t)(
    xe_api_version_t,
    xex_global_dditable_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for xexCommandListReserveSpace 
typedef xe_result_t (__xecall *xex_pfnCommandListReserveSpace_t)(
    xex_command_list_handle_t,
    size_t,
    void**
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of CommandList functions pointers
typedef struct _xex_command_list_dditable_t
{
    xex_pfnCommandListReserveSpace_t                            pfnReserveSpace;
} xex_command_list_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's CommandList table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + invalid value for version
///         + nullptr for pDdiTable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xexGetCommandListProcAddrTable(
    xe_api_version_t version,                       ///< [in] API version requested
    xex_command_list_dditable_t* pDdiTable          ///< [in,out] pointer to table of DDI function pointers
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for xexGetCommandListProcAddrTable
typedef xe_result_t (__xecall *xex_pfnGetCommandListProcAddrTable_t)(
    xe_api_version_t,
    xex_command_list_dditable_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for xexCommandGraphCreate 
typedef xe_result_t (__xecall *xex_pfnCommandGraphCreate_t)(
    xe_device_handle_t,
    const xex_command_graph_desc_t*,
    xex_command_graph_handle_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for xexCommandGraphDestroy 
typedef xe_result_t (__xecall *xex_pfnCommandGraphDestroy_t)(
    xex_command_graph_handle_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for xexCommandGraphClose 
typedef xe_result_t (__xecall *xex_pfnCommandGraphClose_t)(
    xex_command_graph_handle_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of CommandGraph functions pointers
typedef struct _xex_command_graph_dditable_t
{
    xex_pfnCommandGraphCreate_t                                 pfnCreate;
    xex_pfnCommandGraphDestroy_t                                pfnDestroy;
    xex_pfnCommandGraphClose_t                                  pfnClose;
} xex_command_graph_dditable_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's CommandGraph table
///        with current process' addresses
///
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + invalid value for version
///         + nullptr for pDdiTable
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__xedllexport xe_result_t __xecall
xexGetCommandGraphProcAddrTable(
    xe_api_version_t version,                       ///< [in] API version requested
    xex_command_graph_dditable_t* pDdiTable         ///< [in,out] pointer to table of DDI function pointers
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for xexGetCommandGraphProcAddrTable
typedef xe_result_t (__xecall *xex_pfnGetCommandGraphProcAddrTable_t)(
    xe_api_version_t,
    xex_command_graph_dditable_t*
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Container for all DDI tables
typedef struct _xex_dditable_t
{
    xex_global_dditable_t               Global;
    xex_command_list_dditable_t         CommandList;
    xex_command_graph_dditable_t        CommandGraph;
} xex_dditable_t;

#if defined(__cplusplus)
} // extern "C"
#endif

#endif // _XEX_DDI_H