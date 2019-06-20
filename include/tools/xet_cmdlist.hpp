/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file xet_cmdlist.hpp
 *
 * @brief C++ wrapper of Intel 'One API' Level-Zero Tool APIs for Command List
 *
 * @cond DEV
 * DO NOT EDIT: generated from /scripts/tools/cmdlist.yml
 * @endcond
 *
 */
#ifndef _XET_CMDLIST_HPP
#define _XET_CMDLIST_HPP
#if defined(__cplusplus)
#pragma once
#if !defined(_XET_API_HPP)
#pragma message("warning: this file is not intended to be included directly")
#endif

namespace xet
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for command list
    class CommandList : public xe::CommandList
    {
    public:

    protected:
        ///////////////////////////////////////////////////////////////////////////////

    public:
        ///////////////////////////////////////////////////////////////////////////////
        using xe::CommandList::CommandList;

        ~CommandList( void ) = default;

        CommandList( CommandList const& other ) = delete;
        void operator=( CommandList const& other ) = delete;

        CommandList( CommandList&& other ) = delete;
        void operator=( CommandList&& other ) = delete;

        ///////////////////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Append metric tracer marker into a command list.
        /// 
        /// @details
        ///     - The application may **not** call this function from simultaneous
        ///       threads with the same command list handle.
        /// @throws result_t
        void __xecall
        AppendMetricTracerMarker(
            MetricTracer* pMetricTracer,                    ///< [in] pointer to the metric tracer
            uint32_t value                                  ///< [in] tracer marker value
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Appends metric query begin into a command list.
        /// 
        /// @details
        ///     - The application may **not** call this function from simultaneous
        ///       threads with the same command list handle.
        /// @throws result_t
        void __xecall
        AppendMetricQueryBegin(
            MetricQuery* pMetricQuery                       ///< [in] pointer to the metric query
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Appends metric query end into a command list.
        /// 
        /// @details
        ///     - The application may **not** call this function from simultaneous
        ///       threads with the same command list handle.
        /// @throws result_t
        void __xecall
        AppendMetricQueryEnd(
            MetricQuery* pMetricQuery,                      ///< [in] pointer to the metric query
            xe::Event* pCompletionEvent = nullptr           ///< [in][optional] pointer to the completion event to signal
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief Appends metric query commands to flush all caches.
        /// 
        /// @details
        ///     - The application may **not** call this function from simultaneous
        ///       threads with the same command list handle.
        /// @throws result_t
        void __xecall
        AppendMetricMemoryBarrier(
            void
            );

    };

} // namespace xet

namespace xet
{
} // namespace xet
#endif // defined(__cplusplus)
#endif // _XET_CMDLIST_HPP
