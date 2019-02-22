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
* @file xe_common.h
*
* @brief Intel Xe Driver API common types
*
* @cond DEV
* DO NOT EDIT: generated from /scripts/<type>/common.yml
* @endcond
*
******************************************************************************/
#ifndef _XE_COMMON_H
#define _XE_COMMON_H
#if defined(__cplusplus)
#pragma once
#endif
#include <stdint.h>
#include <string.h>

#if defined(__cplusplus)
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
/// @brief Generates generic Xe API versions
#define XE_MAKE_VERSION( _major, _minor )  (( _major << 16 )|( _minor & 0x0000ffff))

///////////////////////////////////////////////////////////////////////////////
/// @brief Extracts Xe API major version
#define XE_MAJOR_VERSION( _ver )  ( _ver >> 16 )

///////////////////////////////////////////////////////////////////////////////
/// @brief Extracts Xe API minor version
#define XE_MINOR_VERSION( _ver )  ( _ver & 0x0000ffff )

///////////////////////////////////////////////////////////////////////////////
/// @brief Current header file version
#define XE_API_HEADER_VERSION  XE_MAKE_VERSION( 1, 0 )

///////////////////////////////////////////////////////////////////////////////
#if defined(_WIN32)
/// @brief Calling convention for all API functions
#define __xecall  __cdecl
#else
#define __xecall  
#endif // defined(_WIN32)

///////////////////////////////////////////////////////////////////////////////
#if !defined(XE_ENABLE_OCL_INTEROP)
/// @brief Disable OpenCL interoperability functions if not explicitly defined
#define XE_ENABLE_OCL_INTEROP  0
#endif // !defined(XE_ENABLE_OCL_INTEROP)

///////////////////////////////////////////////////////////////////////////////
/// @brief naming consistency
typedef float float_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief naming consistency
typedef double double_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle of driver's device object
typedef struct _xe_device_handle_t *xe_device_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle of driver's command queue object
typedef struct _xe_command_queue_handle_t *xe_command_queue_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle of driver's command list object
typedef struct _xe_command_list_handle_t *xe_command_list_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle of driver's command graph object
typedef struct _xe_command_graph_handle_t *xe_command_graph_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle of driver's fence object
typedef struct _xe_fence_handle_t *xe_fence_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle of driver's semaphore object
typedef struct _xe_semaphore_handle_t *xe_semaphore_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle of driver's event object
typedef struct _xe_event_handle_t *xe_event_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle of driver's image object
typedef struct _xe_image_handle_t *xe_image_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle of driver's module object
typedef struct _xe_module_handle_t *xe_module_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle of module's build log object
typedef struct _xe_module_build_log_handle_t *xe_module_build_log_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle of driver's function object
typedef struct _xe_function_handle_t *xe_function_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Handle of driver's function args object
typedef struct _xe_function_args_handle_t *xe_function_args_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief IPC handle to a memory allocation
typedef struct _xe_ipc_mem_handle_t *xe_ipc_mem_handle_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Generic macro for enumerator bit masks
#define XE_BIT( _i )  ( 1 << _i )

///////////////////////////////////////////////////////////////////////////////
/// @brief Defines Return/Error codes
/// 
/// @remarks
///   _Analogues_
///     - **CUresult**
typedef enum _xe_result_t
{
    XE_RESULT_SUCCESS = 0,                          ///< success
    XE_RESULT_NOT_READY = 1,                        ///< synchronization primitive not signaled
    XE_RESULT_ERROR_UNINITIALIZED,                  ///< driver is not initialized
    XE_RESULT_ERROR_DEVICE_LOST,                    ///< device hung, reset, was removed, or driver update occurred
    XE_RESULT_ERROR_UNSUPPORTED,                    ///< device does not support feature requested
    XE_RESULT_ERROR_INVALID_PARAMETER,              ///< invalid parameter provided
    XE_RESULT_ERROR_OUT_OF_HOST_MEMORY,             ///< insufficient host memory to satisfy call
    XE_RESULT_ERROR_OUT_OF_DEVICE_MEMORY,           ///< insufficient device memory to satisfy call
    XE_RESULT_ERROR_MODULE_BUILD_FAILURE,           ///< error in building module
    XE_RESULT_ERROR_UNKNOWN = 0x7fffffff,           ///< unknown or internal error

} xe_result_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Supported synchronization modes
typedef enum _xe_synchronization_mode_t
{
    XE_SYNCHRONIZATION_MODE_POLL,                   ///< poll on Host until device signals; lowest latency (default)
    XE_SYNCHRONIZATION_MODE_SLEEP,                  ///< put Host thread to sleep until device signals

} xe_synchronization_mode_t;

#if defined(__cplusplus)
} // extern "C"
#endif

#endif // _XE_COMMON_H
