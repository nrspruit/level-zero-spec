/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file zex_cmdlist.cpp
 *
 * @brief C++ wrapper of Intel 'One API' Level-Zero Experimental APIs for Command List
 *
 * @cond DEV
 * DO NOT EDIT: generated from /scripts/experimental/cmdlist.yml
 * @endcond
 *
 */
#include "zex_lib.h"

extern "C" {

///////////////////////////////////////////////////////////////////////////////
/// @brief Reserve a section of contiguous command buffer space within the
///        command list.
/// 
/// @details
///     - The pointer returned is valid for both Host and device access.
///     - The application may **not** call this function from simultaneous
///       threads with the same command list handle.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_DEVICE_LOST
///     - ::ZE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hCommandList
///         + nullptr == ptr
///         + 0 for size
///     - ::ZE_RESULT_ERROR_UNSUPPORTED
ze_result_t __zecall
zexCommandListReserveSpace(
    zex_command_list_handle_t hCommandList,         ///< [in] handle of the command list
    size_t size,                                    ///< [in] size (in bytes) to reserve
    void** ptr                                      ///< [out] pointer to command buffer space reserved
    )
{
    auto pfnReserveSpace = zex_lib::context.ddiTable.CommandList.pfnReserveSpace;
    if( nullptr == pfnReserveSpace )
        return ZE_RESULT_ERROR_UNSUPPORTED;

    return pfnReserveSpace( hCommandList, size, ptr );
}

} // extern "C"

namespace zex
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Reserve a section of contiguous command buffer space within the
    ///        command list.
    /// 
    /// @details
    ///     - The pointer returned is valid for both Host and device access.
    ///     - The application may **not** call this function from simultaneous
    ///       threads with the same command list handle.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @returns
    ///     - void*: pointer to command buffer space reserved
    /// 
    /// @throws result_t
    void* __zecall
    CommandList::ReserveSpace(
        size_t size                                     ///< [in] size (in bytes) to reserve
        )
    {
        void* ptr;

        auto result = static_cast<result_t>( ::zexCommandListReserveSpace(
            reinterpret_cast<zex_command_list_handle_t>( getHandle() ),
            size,
            &ptr ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "zex::CommandList::ReserveSpace" );

        return ptr;
    }

} // namespace zex

namespace zex
{
} // namespace zex