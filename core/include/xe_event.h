/**************************************************************************//**
* INTEL CONFIDENTIAL  
* Copyright 2019  
* Intel Corporation All Rights Reserved.  
*
* @cond DEV
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
* @endcond
*
* @file xe_event.h
*
* @brief Intel Xe Driver APIs for Event
*
* @cond DEV
* DO NOT EDIT: generated from /scripts/core/event.yml
* @endcond
*
******************************************************************************/
#ifndef _XE_EVENT_H
#define _XE_EVENT_H
#if defined(__cplusplus)
#pragma once
#endif
#include "xe_common.h"

#if defined(__cplusplus)
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
/// @brief API version of ::xe_event_desc_t
typedef enum _xe_event_desc_version_t
{
    XE_EVENT_DESC_VERSION_CURRENT = XE_MAKE_VERSION( 1, 0 ),///< version 1.0

} xe_event_desc_version_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Supported event creation flags
typedef enum _xe_event_flag_t
{
    XE_EVENT_FLAG_NONE = 0,                         ///< signals and waits only within the same device
    XE_EVENT_FLAG_HOST_TO_DEVICE = XE_BIT(0),       ///< signals from host, waits on device
    XE_EVENT_FLAG_DEVICE_TO_HOST = XE_BIT(1),       ///< signals from device, waits on host
    XE_EVENT_FLAG_DEVICE_TO_DEVICE = XE_BIT(2),     ///< signals from device, waits on another device
    XE_EVENT_FLAG_IPC = XE_BIT(3),                  ///< signals and waits may occur across processes
    XE_EVENT_FLAG_TIMESTAMP = XE_BIT(4),            ///< supports time-based queries
    XE_EVENT_FLAG_PERFORMANCE_METRICS = XE_BIT(5),  ///< supports performance metrics (MDAPI)

} xe_event_flag_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Event descriptor
typedef struct _xe_event_desc_t
{
    xe_event_desc_version_t version;                ///< [in] ::XE_EVENT_DESC_VERSION_CURRENT
    xe_event_flag_t flags;                          ///< [in] creation flags

} xe_event_desc_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Creates an event object on the device.
/// 
/// @details
///     - This function may be called from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - **clCreateUserEvent**
///     - vkCreateEvent
///     - cuEventCreate
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hDevice
///         + nullptr == desc
///         + nullptr == phEvent
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + ::XE_EVENT_DESC_VERSION_CURRENT < desc->version
///     - ::XE_RESULT_ERROR_OUT_OF_HOST_MEMORY
///     - ::XE_RESULT_ERROR_OUT_OF_DEVICE_MEMORY
__xedllport xe_result_t __xecall
xeDeviceCreateEvent(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device
    const xe_event_desc_t* desc,                    ///< [in] pointer to event descriptor
    xe_event_handle_t* phEvent                      ///< [out] pointer to handle of event object created
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Creates an event object on the device from existing memory.
/// 
/// @details
///     - This function is intended for sharing fences with peer devices or
///       across processes
///     - This function may be called from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hDevice
///         + nullptr == desc
///         + nullptr == ptr
///         + nullptr == phEvent
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + ::XE_EVENT_DESC_VERSION_CURRENT < desc->version
///     - ::XE_RESULT_ERROR_OUT_OF_HOST_MEMORY
__xedllport xe_result_t __xecall
xeDevicePlaceEvent(
    xe_device_handle_t hDevice,                     ///< [in] handle of the device
    const xe_event_desc_t* desc,                    ///< [in] pointer to event descriptor
    void* ptr,                                      ///< [in] pointer to the device pointer where the event should be placed
    xe_event_handle_t* phEvent                      ///< [out] pointer to handle of event object created
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Deletes an event object.
/// 
/// @details
///     - The application is responsible for making sure the GPU is not
///       currently referencing the event before it is deleted
///     - The implementation of this function will immediately free all Host and
///       Device allocations associated with this event
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - **clReleaseEvent**
///     - vkDestroyEvent
///     - cuEventDestroy
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hEvent
///     - ::XE_RESULT_ERROR_UNSUPPORTED
__xedllport xe_result_t __xecall
xeEventDestroy(
    xe_event_handle_t hEvent                        ///< [in] handle of event object to destroy
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Appends a signal of the event from the device into a command list.
/// 
/// @details
///     - The application may **not** call this function from simultaneous
///       threads with the same command list handle.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - **clSetUserEventStatus**
///     - cuEventRecord
///     - vkCmdSetEvent
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hCommandList
///         + nullptr == hEvent
///     - ::XE_RESULT_ERROR_UNSUPPORTED
__xedllport xe_result_t __xecall
xeCommandListAppendSignalEvent(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of the command list
    xe_event_handle_t hEvent                        ///< [in] handle of the event
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Appends a wait on event from a host signal into a command list.
/// 
/// @details
///     - The application may **not** call this function from simultaneous
///       threads with the same command list handle.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hCommandList
///         + nullptr == hEvent
///     - ::XE_RESULT_ERROR_UNSUPPORTED
__xedllport xe_result_t __xecall
xeCommandListAppendWaitOnEvent(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of the command list
    xe_event_handle_t hEvent                        ///< [in] handle of the event
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Signals a event from host.
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - clSetUserEventStatus
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hEvent
///     - ::XE_RESULT_ERROR_UNSUPPORTED
__xedllport xe_result_t __xecall
xeEventHostSignal(
    xe_event_handle_t hEvent                        ///< [in] handle of the event
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief The current host thread waits on an event from a device signal.
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - clWaitForEvents
///     - cuEventSynchronize
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hEvent
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///     - ::XE_RESULT_NOT_READY
///         + timeout expired
__xedllport xe_result_t __xecall
xeEventHostSynchronize(
    xe_event_handle_t hEvent,                       ///< [in] handle of the event
    uint32_t timeout                                ///< [in] if non-zero, then indicates the maximum time to yield before
                                                    ///< returning ::XE_RESULT_SUCCESS or ::XE_RESULT_NOT_READY; if zero, then
                                                    ///< operates exactly like ::xeEventQueryStatus; if MAX_UINT32, then
                                                    ///< function will not return until complete or device is lost.
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Queries an event object's status.
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - **clGetEventInfo**
///     - vkGetEventStatus
///     - cuEventQuery
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hEvent
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///     - ::XE_RESULT_NOT_READY
///         + not signaled
__xedllport xe_result_t __xecall
xeEventQueryStatus(
    xe_event_handle_t hEvent                        ///< [in] handle of the event
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Queries the elapsed time between two device-signaled events.
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - **cuEventElapsedTime**
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hEventBegin
///         + nullptr == hEventEnd
///         + nullptr == pTime
///         + either event not signaled by device
///         + either event not created with ::XE_EVENT_FLAG_TIMESTAMP
///     - ::XE_RESULT_ERROR_UNSUPPORTED
__xedllport xe_result_t __xecall
xeEventQueryElapsedTime(
    xe_event_handle_t hEventBegin,                  ///< [in] handle of the begin event
    xe_event_handle_t hEventEnd,                    ///< [in] handle of the end event
    double* pTime                                   ///< [out] time in milliseconds
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Queries performance metrics between two device-signaled events.
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hEventStart
///         + nullptr == hEventEnd
///         + nullptr == pReportData
///         + either event not signaled by device
///         + either event not created with ::XE_EVENT_FLAG_PERFORMANCE_METRICS
///         + report size too small
///     - ::XE_RESULT_ERROR_UNSUPPORTED
__xedllport xe_result_t __xecall
xeEventQueryMetricsData(
    xe_event_handle_t hEventStart,                  ///< [in] handle of the start event
    xe_event_handle_t hEventEnd,                    ///< [in] handle of the end event
    size_t reportSize,                              ///< [in] size of the report data buffer in bytes
    uint32_t* pReportData                           ///< [out] report data buffer
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Reset an event back to not signaled state
/// 
/// @details
///     - The application may **not** call this function from simultaneous
///       threads.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - vkResetEvent
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hCommandList
///         + nullptr == hEvent
///     - ::XE_RESULT_ERROR_UNSUPPORTED
__xedllport xe_result_t __xecall
xeCommandListAppendEventReset(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of the command list
    xe_event_handle_t hEvent                        ///< [in] handle of the event
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Reset an event back to not signaled state
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - vkResetEvent
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_PARAMETER
///         + nullptr == hEvent
///     - ::XE_RESULT_ERROR_UNSUPPORTED
__xedllport xe_result_t __xecall
xeEventReset(
    xe_event_handle_t hEvent                        ///< [in] handle of the event
    );

#if defined(__cplusplus)
} // extern "C"
#endif

#endif // _XE_EVENT_H
