/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file ze_experimental_layer.cpp
 *
 * @cond DEV
 * DO NOT EDIT: generated from /scripts/templates/valddi.cpp.mako
 * @endcond
 *
 */
#include "ze_layer.h"

namespace layer
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zexInit
    ze_result_t __zecall
    zexInit(
        ze_init_flag_t flags                            ///< [in] initialization flags
        )
    {
        auto pfnInit = context.zexDdiTable.Global.pfnInit;

        if( nullptr == pfnInit )
            return ZE_RESULT_ERROR_UNSUPPORTED;

        if( context.enableParameterValidation )
        {
        }

        return pfnInit( flags );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zexCommandListReserveSpace
    ze_result_t __zecall
    zexCommandListReserveSpace(
        zex_command_list_handle_t hCommandList,         ///< [in] handle of the command list
        size_t size,                                    ///< [in] size (in bytes) to reserve
        void** ptr                                      ///< [out] pointer to command buffer space reserved
        )
    {
        auto pfnReserveSpace = context.zexDdiTable.CommandList.pfnReserveSpace;

        if( nullptr == pfnReserveSpace )
            return ZE_RESULT_ERROR_UNSUPPORTED;

        if( context.enableParameterValidation )
        {
            if( nullptr == hCommandList )
                return ZE_RESULT_ERROR_INVALID_ARGUMENT;

            if( nullptr == ptr )
                return ZE_RESULT_ERROR_INVALID_ARGUMENT;

        }

        return pfnReserveSpace( hCommandList, size, ptr );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zexCommandGraphCreate
    ze_result_t __zecall
    zexCommandGraphCreate(
        ze_device_handle_t hDevice,                     ///< [in] handle of the device object
        const zex_command_graph_desc_t* desc,           ///< [in] pointer to command graph descriptor
        zex_command_graph_handle_t* phCommandGraph      ///< [out] pointer to handle of command graph object created
        )
    {
        auto pfnCreate = context.zexDdiTable.CommandGraph.pfnCreate;

        if( nullptr == pfnCreate )
            return ZE_RESULT_ERROR_UNSUPPORTED;

        if( context.enableParameterValidation )
        {
            if( nullptr == hDevice )
                return ZE_RESULT_ERROR_INVALID_ARGUMENT;

            if( nullptr == desc )
                return ZE_RESULT_ERROR_INVALID_ARGUMENT;

            if( nullptr == phCommandGraph )
                return ZE_RESULT_ERROR_INVALID_ARGUMENT;

            if( ZEX_COMMAND_GRAPH_DESC_VERSION_CURRENT < desc->version )
                return ZE_RESULT_ERROR_UNSUPPORTED;

        }

        return pfnCreate( hDevice, desc, phCommandGraph );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zexCommandGraphDestroy
    ze_result_t __zecall
    zexCommandGraphDestroy(
        zex_command_graph_handle_t hCommandGraph        ///< [in][release] handle of command graph object to destroy
        )
    {
        auto pfnDestroy = context.zexDdiTable.CommandGraph.pfnDestroy;

        if( nullptr == pfnDestroy )
            return ZE_RESULT_ERROR_UNSUPPORTED;

        if( context.enableParameterValidation )
        {
            if( nullptr == hCommandGraph )
                return ZE_RESULT_ERROR_INVALID_ARGUMENT;

        }

        return pfnDestroy( hCommandGraph );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zexCommandGraphClose
    ze_result_t __zecall
    zexCommandGraphClose(
        zex_command_graph_handle_t hCommandGraph        ///< [in] handle of command graph object to close
        )
    {
        auto pfnClose = context.zexDdiTable.CommandGraph.pfnClose;

        if( nullptr == pfnClose )
            return ZE_RESULT_ERROR_UNSUPPORTED;

        if( context.enableParameterValidation )
        {
            if( nullptr == hCommandGraph )
                return ZE_RESULT_ERROR_INVALID_ARGUMENT;

        }

        return pfnClose( hCommandGraph );
    }

} // namespace layer

#if defined(__cplusplus)
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Global table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_ARGUMENT
///         + invalid value for version
///         + nullptr for pDdiTable
///     - ::ZE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__zedllexport ze_result_t __zecall
zexGetGlobalProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zex_global_dditable_t* pDdiTable                ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = layer::context.zexDdiTable.Global;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_ARGUMENT;

    if( layer::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnInit                                     = pDdiTable->pfnInit;
    pDdiTable->pfnInit                                   = layer::zexInit;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's CommandList table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_ARGUMENT
///         + invalid value for version
///         + nullptr for pDdiTable
///     - ::ZE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__zedllexport ze_result_t __zecall
zexGetCommandListProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zex_command_list_dditable_t* pDdiTable          ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = layer::context.zexDdiTable.CommandList;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_ARGUMENT;

    if( layer::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnReserveSpace                             = pDdiTable->pfnReserveSpace;
    pDdiTable->pfnReserveSpace                           = layer::zexCommandListReserveSpace;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's CommandGraph table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_ARGUMENT
///         + invalid value for version
///         + nullptr for pDdiTable
///     - ::ZE_RESULT_ERROR_UNSUPPORTED
///         + version not supported
__zedllexport ze_result_t __zecall
zexGetCommandGraphProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zex_command_graph_dditable_t* pDdiTable         ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = layer::context.zexDdiTable.CommandGraph;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_ARGUMENT;

    if( layer::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnCreate                                   = pDdiTable->pfnCreate;
    pDdiTable->pfnCreate                                 = layer::zexCommandGraphCreate;

    dditable.pfnDestroy                                  = pDdiTable->pfnDestroy;
    pDdiTable->pfnDestroy                                = layer::zexCommandGraphDestroy;

    dditable.pfnClose                                    = pDdiTable->pfnClose;
    pDdiTable->pfnClose                                  = layer::zexCommandGraphClose;

    return result;
}

#if defined(__cplusplus)
};
#endif