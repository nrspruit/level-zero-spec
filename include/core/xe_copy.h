/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file xe_copy.h
 *
 * @brief Intel 'One API' Level-Zero APIs for Copies
 *
 * @cond DEV
 * DO NOT EDIT: generated from /scripts/core/copy.yml
 * @endcond
 *
 */
#ifndef _XE_COPY_H
#define _XE_COPY_H
#if defined(__cplusplus)
#pragma once
#endif
#if !defined(_XE_API_H)
#pragma message("warning: this file is not intended to be included directly")
#endif

#if defined(__cplusplus)
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
/// @brief Copies host, device, or shared memory.
/// 
/// @details
///     - The memory pointed to by both srcptr and dstptr must be accessible by
///       the device on which the command list is created.
///     - The application may **not** call this function from simultaneous
///       threads with the same command list handle.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - **clEnqueueCopyBuffer**
///     - **clEnqueueReadBuffer**
///     - **clEnqueueWriteBuffer**
///     - **clEnqueueSVMMemcpy**
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hCommandList
///         + nullptr == dstptr
///         + nullptr == srcptr
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeCommandListAppendMemoryCopy(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of command list
    void* dstptr,                                   ///< [in] pointer to destination memory to copy to
    const void* srcptr,                             ///< [in] pointer to source memory to copy from
    size_t size,                                    ///< [in] size in bytes to copy
    xe_event_handle_t hEvent                        ///< [in][optional] handle of the event to signal on completion
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Initializes host, device, or shared memory.
/// 
/// @details
///     - The memory pointed to by dstptr must be accessible by the device on
///       which the command list is created.
///     - The value to initialize memory to is interpreted as an 8-bit unsigned
///       char; the upper 24-bits are ignored.
///     - The application may **not** call this function from simultaneous
///       threads with the same command list handle.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - **clEnqueueFillBuffer**
///     - **clEnqueueSVMMemFill**
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hCommandList
///         + nullptr == ptr
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeCommandListAppendMemorySet(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of command list
    void* ptr,                                      ///< [in] pointer to memory to initialize
    int value,                                      ///< [in] value to initialize memory to
    size_t size,                                    ///< [in] size in bytes to initailize
    xe_event_handle_t hEvent                        ///< [in][optional] handle of the event to signal on completion
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Copy region descriptor
typedef struct _xe_copy_region_t
{
    uint32_t originX;                               ///< [in] The origin x offset for region in bytes
    uint32_t originY;                               ///< [in] The origin y offset for region in rows
    uint32_t width;                                 ///< [in] The region width relative to origin in bytes
    uint32_t height;                                ///< [in] The region height relative to origin in rows

} xe_copy_region_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Copies a region from a 2D array of host, device, or shared memory.
/// 
/// @details
///     - The memory pointed to by both srcptr and dstptr must be accessible by
///       the device on which the command list is created.
///     - The region width and height for both src and dst must be same. The
///       origins can be different.
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
///         + nullptr == dstptr
///         + nullptr == dstRegion
///         + nullptr == srcptr
///         + nullptr == srcRegion
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeCommandListAppendMemoryCopyRegion(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of command list
    void* dstptr,                                   ///< [in] pointer to destination memory to copy to
    const xe_copy_region_t* dstRegion,              ///< [in] pointer to destination region to copy to
    uint32_t dstPitch,                              ///< [in] destination pitch in bytes
    const void* srcptr,                             ///< [in] pointer to source memory to copy from
    const xe_copy_region_t* srcRegion,              ///< [in] pointer to source region to copy from
    uint32_t srcPitch,                              ///< [in] source pitch in bytes
    xe_event_handle_t hEvent                        ///< [in][optional] handle of the event to signal on completion
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Copies a image.
/// 
/// @details
///     - The application may **not** call this function from simultaneous
///       threads with the same command list handle.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - **clEnqueueCopyImage**
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hCommandList
///         + nullptr == hDstImage
///         + nullptr == hSrcImage
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeCommandListAppendImageCopy(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of command list
    xe_image_handle_t hDstImage,                    ///< [in] handle of destination image to copy to
    xe_image_handle_t hSrcImage,                    ///< [in] handle of source image to copy from
    xe_event_handle_t hEvent                        ///< [in][optional] handle of the event to signal on completion
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Region descriptor
typedef struct _xe_image_region_t
{
    uint32_t originX;                               ///< [in] The origin x offset for region in pixels
    uint32_t originY;                               ///< [in] The origin y offset for region in pixels
    uint32_t originZ;                               ///< [in] The origin z offset for region in pixels
    uint32_t width;                                 ///< [in] The region width relative to origin in pixels
    uint32_t height;                                ///< [in] The region height relative to origin in pixels
    uint32_t depth;                                 ///< [in] The region depth relative to origin. For 1D or 2D images, set
                                                    ///< this to 1.

} xe_image_region_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Copies a region of a image to another image.
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
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hCommandList
///         + nullptr == hDstImage
///         + nullptr == hSrcImage
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeCommandListAppendImageCopyRegion(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of command list
    xe_image_handle_t hDstImage,                    ///< [in] handle of destination image to copy to
    xe_image_handle_t hSrcImage,                    ///< [in] handle of source image to copy from
    const xe_image_region_t* pDstRegion,            ///< [in][optional] destination region descriptor
    const xe_image_region_t* pSrcRegion,            ///< [in][optional] source region descriptor
    xe_event_handle_t hEvent                        ///< [in][optional] handle of the event to signal on completion
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Copies from a image to device or shared memory.
/// 
/// @details
///     - The memory pointed to by dstptr must be accessible by the device on
///       which the command list is created.
///     - The application may **not** call this function from simultaneous
///       threads with the same command list handle.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - clEnqueueReadImage
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hCommandList
///         + nullptr == dstptr
///         + nullptr == hSrcImage
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeCommandListAppendImageCopyToMemory(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of command list
    void* dstptr,                                   ///< [in] pointer to destination memory to copy to
    xe_image_handle_t hSrcImage,                    ///< [in] handle of source image to copy from
    const xe_image_region_t* pSrcRegion,            ///< [in][optional] source region descriptor
    xe_event_handle_t hEvent                        ///< [in][optional] handle of the event to signal on completion
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Copies to a image from device or shared memory.
/// 
/// @details
///     - The memory pointed to by srcptr must be accessible by the device on
///       which the command list is created.
///     - The application may **not** call this function from simultaneous
///       threads with the same command list handle.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - clEnqueueWriteImage
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hCommandList
///         + nullptr == hDstImage
///         + nullptr == srcptr
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeCommandListAppendImageCopyFromMemory(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of command list
    xe_image_handle_t hDstImage,                    ///< [in] handle of destination image to copy to
    const void* srcptr,                             ///< [in] pointer to source memory to copy from
    const xe_image_region_t* pDstRegion,            ///< [in][optional] destination region descriptor
    xe_event_handle_t hEvent                        ///< [in][optional] handle of the event to signal on completion
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Asynchronously prefetches shared memory to the device associated with
///        the specified command list
/// 
/// @details
///     - This is a hint to improve performance only and is not required for
///       correctness.
///     - Only prefetching to the device associated with the specified command
///       list is supported.
///       Prefetching to the host or to a peer device is not supported.
///     - Prefetching may not be supported for all allocation types for all devices.
///       If memory prefetching is not supported for the specified memory range
///       the prefetch hint may be ignored.
///     - Prefetching may only be supported at a device-specific granularity,
///       such as at a page boundary.
///       In this case, the memory range may be expanded such that the start and
///       end of the range satisfy granularity requirements.
///     - The application may **not** call this function from simultaneous
///       threads with the same command list handle.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - cudaMemPrefetchAsync
///     - clEnqueueSVMMigrateMem
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hCommandList
///         + nullptr == ptr
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeCommandListAppendMemoryPrefetch(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of command list
    const void* ptr,                                ///< [in] pointer to start of the memory range to prefetch
    size_t size                                     ///< [in] size in bytes of the memory range to prefetch
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Supported memory advice hints
typedef enum _xe_memory_advice_t
{
    XE_MEMORY_ADVICE_SET_READ_MOSTLY = 0,           ///< hint that memory will be read from frequently and written to rarely
    XE_MEMORY_ADVICE_CLEAR_READ_MOSTLY,             ///< removes the affect of ::XE_MEMORY_ADVICE_SET_READ_MOSTLY
    XE_MEMORY_ADVICE_SET_PREFERRED_LOCATION,        ///< hint that the preferred memory location is the specified device
    XE_MEMORY_ADVICE_CLEAR_PREFERRED_LOCATION,      ///< removes the affect of ::XE_MEMORY_ADVICE_SET_PREFERRED_LOCATION
    XE_MEMORY_ADVICE_SET_ACCESSED_BY,               ///< hint that memory will be accessed by the specified device
    XE_MEMORY_ADVICE_CLEAR_ACCESSED_BY,             ///< removes the affect of ::XE_MEMORY_ADVICE_SET_ACCESSED_BY
    XE_MEMORY_ADVICE_SET_NON_ATOMIC_MOSTLY,         ///< hints that memory will mostly be accessed non-atomically
    XE_MEMORY_ADVICE_CLEAR_NON_ATOMIC_MOSTLY,       ///< removes the affect of ::XE_MEMORY_ADVICE_SET_NON_ATOMIC_MOSTLY
    XE_MEMORY_ADVICE_BIAS_CACHED,                   ///< hints that memory should be cached
    XE_MEMORY_ADVICE_BIAS_UNCACHED,                 ///< hints that memory should be not be cached

} xe_memory_advice_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief Provides advice about the use of a shared memory range
/// 
/// @details
///     - Memory advice is a performance hint only and is not required for
///       functional correctness.
///     - Memory advice can be used to override driver heuristics to explicitly
///       control shared memory behavior.
///     - Not all memory advice hints may be supported for all allocation types
///       for all devices.
///       If a memory advice hint is not supported by the device it will be ignored.
///     - Memory advice may only be supported at a device-specific granularity,
///       such as at a page boundary.
///       In this case, the memory range may be expanded such that the start and
///       end of the range satisfy granularity requirements.
///     - The application may **not** call this function from simultaneous
///       threads with the same command list handle.
///     - The implementation of this function should be lock-free.
/// 
/// @remarks
///   _Analogues_
///     - **cudaMemAdvise**
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hCommandList
///         + nullptr == hDevice
///         + nullptr == ptr
///         + invalid value for advice
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xeCommandListAppendMemAdvise(
    xe_command_list_handle_t hCommandList,          ///< [in] handle of command list
    xe_device_handle_t hDevice,                     ///< [in] device associated with the memory advice
    const void* ptr,                                ///< [in] Pointer to the start of the memory range
    size_t size,                                    ///< [in] Size in bytes of the memory range
    xe_memory_advice_t advice                       ///< [in] Memory advice for the memory range
    );

#if defined(__cplusplus)
} // extern "C"
#endif

#endif // _XE_COPY_H
