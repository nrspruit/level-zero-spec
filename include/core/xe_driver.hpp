/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file xe_driver.hpp
 *
 * @brief C++ wrapper of Intel 'One API' Level-Zero APIs
 *
 * @cond DEV
 * DO NOT EDIT: generated from /scripts/core/driver.yml
 * @endcond
 *
 */
#ifndef _XE_DRIVER_HPP
#define _XE_DRIVER_HPP
#if defined(__cplusplus)
#pragma once
#if !defined(_XE_API_HPP)
#pragma message("warning: this file is not intended to be included directly")
#endif

namespace xe
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Supported initialization flags
    enum class init_flag_t
    {
        NONE = 0,                                       ///< default behavior
        GPU_ONLY = XE_BIT(0),                           ///< only initialize GPU drivers

    };

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Initialize the 'One API' driver and must be called before any other
    ///        API function.
    /// 
    /// @details
    ///     - If this function is not called then all other functions will return
    ///       ::XE_RESULT_ERROR_UNINITIALIZED.
    ///     - Only one instance of a driver per process will be initialized.
    ///     - This function is thread-safe for scenarios where multiple libraries
    ///       may initialize the driver simultaneously.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - **cuInit**
    /// 
    /// @throws result_t
    void __xecall
    Init(
        init_flag_t flags                               ///< [in] initialization flags
        );

} // namespace xe

namespace xe
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts init_flag_t to std::string
    std::string to_string( const init_flag_t val );

} // namespace xe
#endif // defined(__cplusplus)
#endif // _XE_DRIVER_HPP
