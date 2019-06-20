/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file xe_barrier.cpp
 *
 * @brief C++ wrapper of Intel 'One API' Level-Zero APIs for Barrier
 *
 * @cond DEV
 * DO NOT EDIT: generated from /scripts/core/barrier.yml
 * @endcond
 *
 */
#include "xe_lib.h"

extern "C" {

///////////////////////////////////////////////////////////////////////////////
/// @brief Appends an execution and global memory barrier into a command list.
/// 
/// @details
///     - If numWaitEvents is zero, then all previous commands are completed
///       prior to the execution of the barrier.
///     - If numWaitEvents is non-zero, then then all phWaitEvents must be
///       signalled prior to the execution of the barrier.
///     - This command blocks all following commands from beginning until the
///       execution of the barrier completes.
///     - Memory and cache hierarchies are flushed and invalidated sufficient
///       for device and host access.
///     - The application may **not** call this function from simultaneous
///       threads with the same command list handle.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - **vkCmdPipelineBarrier**
///     - clEnqueueBarrierWithWaitList
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hCommandList
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeCommandListAppendBarrier(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of the command list
    xe_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
    uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before executing barrier
    xe_event_handle_t* phWaitEvents                 ///< [in][optional][range(0, numWaitEvents)] handle of the events to wait
                                                    ///< on before executing barrier
    )
{
    auto pfnAppendBarrier = xe_lib::context.ddiTable.CommandList.pfnAppendBarrier;
    if( nullptr == pfnAppendBarrier )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnAppendBarrier( hCommandList, hSignalEvent, numWaitEvents, phWaitEvents );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Appends a global memory ranges barrier into a command list.
/// 
/// @details
///     - If numWaitEvents is zero, then all previous commands are completed
///       prior to the execution of the barrier.
///     - If numWaitEvents is non-zero, then then all phWaitEvents must be
///       signalled prior to the execution of the barrier.
///     - This command blocks all following commands from beginning until the
///       execution of the barrier completes.
///     - Memory and cache hierarchies are flushed and invalidated sufficient
///       for device and host access.
///     - The application may **not** call this function from simultaneous
///       threads with the same command list handle.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hCommandList
///         + nullptr == pRangeSizes
///         + nullptr == pRanges
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeCommandListAppendMemoryRangesBarrier(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of the command list
    uint32_t numRanges,                             ///< [in] number of memory ranges
    const size_t* pRangeSizes,                      ///< [in][range(0, numRanges)] array of sizes of memory range
    const void** pRanges,                           ///< [in][range(0, numRanges)] array of memory ranges
    xe_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
    uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before executing barrier
    xe_event_handle_t* phWaitEvents                 ///< [in][optional][range(0, numWaitEvents)] handle of the events to wait
                                                    ///< on before executing barrier
    )
{
    auto pfnAppendMemoryRangesBarrier = xe_lib::context.ddiTable.CommandList.pfnAppendMemoryRangesBarrier;
    if( nullptr == pfnAppendMemoryRangesBarrier )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnAppendMemoryRangesBarrier( hCommandList, numRanges, pRangeSizes, pRanges, hSignalEvent, numWaitEvents, phWaitEvents );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Ensures in-bound writes to the device are globally observable.
/// 
/// @details
///     - This is a special-case system level barrier that can be used to ensure
///       global observability of writes; typically needed after a producer
///       (e.g., NIC) performs direct writes to the device's memory (e.g.,
///       Direct RDMA writes).  This is typically required when the memory
///       corresponding to the writes is subsequently accessed from a remote
///       device.
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hDevice
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeDeviceSystemBarrier(
    xe_device_handle_t hDevice                      ///< [in] handle of the device
    )
{
    auto pfnSystemBarrier = xe_lib::context.ddiTable.Device.pfnSystemBarrier;
    if( nullptr == pfnSystemBarrier )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnSystemBarrier( hDevice );
}

} // extern "C"

namespace xe
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Appends an execution and global memory barrier into a command list.
    /// 
    /// @details
    ///     - If numWaitEvents is zero, then all previous commands are completed
    ///       prior to the execution of the barrier.
    ///     - If numWaitEvents is non-zero, then then all phWaitEvents must be
    ///       signalled prior to the execution of the barrier.
    ///     - This command blocks all following commands from beginning until the
    ///       execution of the barrier completes.
    ///     - Memory and cache hierarchies are flushed and invalidated sufficient
    ///       for device and host access.
    ///     - The application may **not** call this function from simultaneous
    ///       threads with the same command list handle.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - **vkCmdPipelineBarrier**
    ///     - clEnqueueBarrierWithWaitList
    /// 
    /// @throws result_t
    void __xecall
    CommandList::AppendBarrier(
        Event* pSignalEvent,                            ///< [in][optional] pointer to the event to signal on completion
        uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before executing barrier
        Event** ppWaitEvents                            ///< [in][optional][range(0, numWaitEvents)] pointer to the events to wait
                                                        ///< on before executing barrier
        )
    {
        thread_local std::vector<xe_event_handle_t> hWaitEvents;
        hWaitEvents.resize( 0 );
        hWaitEvents.reserve( numWaitEvents );
        for( uint32_t i = 0; i < numWaitEvents; ++i )
            hWaitEvents.emplace_back( ( ppWaitEvents ) ? reinterpret_cast<xe_event_handle_t>( ppWaitEvents[ i ]->getHandle() ) : nullptr );

        auto result = static_cast<result_t>( ::xeCommandListAppendBarrier(
            reinterpret_cast<xe_command_list_handle_t>( getHandle() ),
            ( pSignalEvent ) ? reinterpret_cast<xe_event_handle_t>( pSignalEvent->getHandle() ) : nullptr,
            numWaitEvents,
            hWaitEvents.data() ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xe::CommandList::AppendBarrier" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Appends a global memory ranges barrier into a command list.
    /// 
    /// @details
    ///     - If numWaitEvents is zero, then all previous commands are completed
    ///       prior to the execution of the barrier.
    ///     - If numWaitEvents is non-zero, then then all phWaitEvents must be
    ///       signalled prior to the execution of the barrier.
    ///     - This command blocks all following commands from beginning until the
    ///       execution of the barrier completes.
    ///     - Memory and cache hierarchies are flushed and invalidated sufficient
    ///       for device and host access.
    ///     - The application may **not** call this function from simultaneous
    ///       threads with the same command list handle.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    CommandList::AppendMemoryRangesBarrier(
        uint32_t numRanges,                             ///< [in] number of memory ranges
        const size_t* pRangeSizes,                      ///< [in][range(0, numRanges)] array of sizes of memory range
        const void** pRanges,                           ///< [in][range(0, numRanges)] array of memory ranges
        Event* pSignalEvent,                            ///< [in][optional] pointer to the event to signal on completion
        uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before executing barrier
        Event** ppWaitEvents                            ///< [in][optional][range(0, numWaitEvents)] pointer to the events to wait
                                                        ///< on before executing barrier
        )
    {
        thread_local std::vector<xe_event_handle_t> hWaitEvents;
        hWaitEvents.resize( 0 );
        hWaitEvents.reserve( numWaitEvents );
        for( uint32_t i = 0; i < numWaitEvents; ++i )
            hWaitEvents.emplace_back( ( ppWaitEvents ) ? reinterpret_cast<xe_event_handle_t>( ppWaitEvents[ i ]->getHandle() ) : nullptr );

        auto result = static_cast<result_t>( ::xeCommandListAppendMemoryRangesBarrier(
            reinterpret_cast<xe_command_list_handle_t>( getHandle() ),
            numRanges,
            pRangeSizes,
            pRanges,
            ( pSignalEvent ) ? reinterpret_cast<xe_event_handle_t>( pSignalEvent->getHandle() ) : nullptr,
            numWaitEvents,
            hWaitEvents.data() ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xe::CommandList::AppendMemoryRangesBarrier" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Ensures in-bound writes to the device are globally observable.
    /// 
    /// @details
    ///     - This is a special-case system level barrier that can be used to ensure
    ///       global observability of writes; typically needed after a producer
    ///       (e.g., NIC) performs direct writes to the device's memory (e.g.,
    ///       Direct RDMA writes).  This is typically required when the memory
    ///       corresponding to the writes is subsequently accessed from a remote
    ///       device.
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Device::SystemBarrier(
        void
        )
    {
        auto result = static_cast<result_t>( ::xeDeviceSystemBarrier(
            reinterpret_cast<xe_device_handle_t>( getHandle() ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xe::Device::SystemBarrier" );
    }

} // namespace xe

namespace xe
{
} // namespace xe
