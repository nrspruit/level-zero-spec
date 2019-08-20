/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file xet_sysman.cpp
 *
 * @brief C++ wrapper of Intel 'One API' Level-Zero Tool APIs for System Resource Management (SMI)
 *
 * @cond DEV
 * DO NOT EDIT: generated from /scripts/tools/sysman.yml
 * @endcond
 *
 */
#include "xet_lib.h"

extern "C" {

///////////////////////////////////////////////////////////////////////////////
/// @brief Get the handle to access SMI features for a device
/// 
/// @details
///     - The returned handle is unique
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hDevice
///         + nullptr == phSysman
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanGet(
    xet_device_handle_t hDevice,                    ///< [in] Handle of the device
    xet_sysman_version_t version,                   ///< [in] SMI version that application was built with
    xet_sysman_handle_t* phSysman                   ///< [out] Handle for accessing SMI features
    )
{
    auto pfnGet = xet_lib::context.ddiTable.Sysman.pfnGet;
    if( nullptr == pfnGet )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnGet( hDevice, version, phSysman );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get properties about the device
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pProperties
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanDeviceGetProperties(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    xet_sysman_properties_t* pProperties            ///< [in] Structure that will contain information about the device.
    )
{
    auto pfnDeviceGetProperties = xet_lib::context.ddiTable.Sysman.pfnDeviceGetProperties;
    if( nullptr == pfnDeviceGetProperties )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnDeviceGetProperties( hSysman, pProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get optimization mode of the device
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pMode
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanDeviceGetOptimizationMode(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    xet_optimization_mode_t* pMode                  ///< [in] The current optimization mode of the device.
    )
{
    auto pfnDeviceGetOptimizationMode = xet_lib::context.ddiTable.Sysman.pfnDeviceGetOptimizationMode;
    if( nullptr == pfnDeviceGetOptimizationMode )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnDeviceGetOptimizationMode( hSysman, pMode );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Set optimization mode of the device
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanDeviceSetOptimizationMode(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    xet_optimization_mode_t pMode                   ///< [in] The new optimization mode of the device.
    )
{
    auto pfnDeviceSetOptimizationMode = xet_lib::context.ddiTable.Sysman.pfnDeviceSetOptimizationMode;
    if( nullptr == pfnDeviceSetOptimizationMode )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnDeviceSetOptimizationMode( hSysman, pMode );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Reset device
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanDeviceReset(
    xet_sysman_handle_t hSysman                     ///< [in] SMI handle for the device
    )
{
    auto pfnDeviceReset = xet_lib::context.ddiTable.Sysman.pfnDeviceReset;
    if( nullptr == pfnDeviceReset )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnDeviceReset( hSysman );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get the number of power domains
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pCount
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanPowerGetCount(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t* pCount                                ///< [in] The number of power domains.
    )
{
    auto pfnPowerGetCount = xet_lib::context.ddiTable.Sysman.pfnPowerGetCount;
    if( nullptr == pfnPowerGetCount )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnPowerGetCount( hSysman, pCount );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get properties related to a power domain
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pProperties
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanPowerGetProperties(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t pwrIndex,                              ///< [in] The index of the power domain (0 ... [::xetSysmanPowerGetCount()
                                                    ///< - 1]).
    xet_power_properties_t* pProperties             ///< [in] Structure that will contain property data.
    )
{
    auto pfnPowerGetProperties = xet_lib::context.ddiTable.Sysman.pfnPowerGetProperties;
    if( nullptr == pfnPowerGetProperties )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnPowerGetProperties( hSysman, pwrIndex, pProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get energy counter
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pEnergy
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanPowerGetEnergyCounter(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t pwrIndex,                              ///< [in] The index of the power domain (0 ... [::xetSysmanPowerGetCount()
                                                    ///< - 1]).
    xet_power_energy_counter_t* pEnergy             ///< [in] Will contain the latest snapshot of the energy counter and
                                                    ///< timestamp when the last counter value was measured.
    )
{
    auto pfnPowerGetEnergyCounter = xet_lib::context.ddiTable.Sysman.pfnPowerGetEnergyCounter;
    if( nullptr == pfnPowerGetEnergyCounter )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnPowerGetEnergyCounter( hSysman, pwrIndex, pEnergy );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get energy threshold
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pThreshold
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanPowerGetEnergyThreshold(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t pwrIndex,                              ///< [in] The index of the power domain (0 ... [::xetSysmanPowerGetCount()
                                                    ///< - 1]).
    xet_power_energy_threshold_t* pThreshold        ///< [out] The current energy threshold value in joules.
    )
{
    auto pfnPowerGetEnergyThreshold = xet_lib::context.ddiTable.Sysman.pfnPowerGetEnergyThreshold;
    if( nullptr == pfnPowerGetEnergyThreshold )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnPowerGetEnergyThreshold( hSysman, pwrIndex, pThreshold );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Set energy threshold
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pThreshold
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanPowerSetEnergyThreshold(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t pwrIndex,                              ///< [in] The index of the power domain (0 ... [::xetSysmanPowerGetCount()
                                                    ///< - 1]).
    xet_power_energy_threshold_t* pThreshold        ///< [in] The energy threshold to be set in joules.
    )
{
    auto pfnPowerSetEnergyThreshold = xet_lib::context.ddiTable.Sysman.pfnPowerSetEnergyThreshold;
    if( nullptr == pfnPowerSetEnergyThreshold )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnPowerSetEnergyThreshold( hSysman, pwrIndex, pThreshold );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get power limits
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanPowerGetLimits(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t pwrIndex,                              ///< [in] The index of the power domain (0 ... [::xetSysmanPowerGetCount()
                                                    ///< - 1]).
    xet_power_sustained_limit_t* pSustained,        ///< [in][optional] The sustained power limit.
    xet_power_burst_limit_t* pBurst,                ///< [in][optional] The burst power limit.
    xet_power_peak_limit_t* pPeak                   ///< [in][optional] The peak power limit.
    )
{
    auto pfnPowerGetLimits = xet_lib::context.ddiTable.Sysman.pfnPowerGetLimits;
    if( nullptr == pfnPowerGetLimits )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnPowerGetLimits( hSysman, pwrIndex, pSustained, pBurst, pPeak );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Set power limits
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanPowerSetLimits(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t pwrIndex,                              ///< [in] The index of the power domain (0 ... [::xetSysmanPowerGetCount()
                                                    ///< - 1]).
    const xet_power_sustained_limit_t* pSustained,  ///< [in][optional] The sustained power limit.
    const xet_power_burst_limit_t* pBurst,          ///< [in][optional] The burst power limit.
    const xet_power_peak_limit_t* pPeak             ///< [in][optional] The peak power limit.
    )
{
    auto pfnPowerSetLimits = xet_lib::context.ddiTable.Sysman.pfnPowerSetLimits;
    if( nullptr == pfnPowerSetLimits )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnPowerSetLimits( hSysman, pwrIndex, pSustained, pBurst, pPeak );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get the number of frequency domains
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pCount
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanFrequencyGetCount(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t* pCount                                ///< [in] The number of frequency domains.
    )
{
    auto pfnFrequencyGetCount = xet_lib::context.ddiTable.Sysman.pfnFrequencyGetCount;
    if( nullptr == pfnFrequencyGetCount )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnFrequencyGetCount( hSysman, pCount );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get frequency properties - available frequencies
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pProperties
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanFrequencyGetProperties(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t freqIndex,                             ///< [in] The index of the frequency domain (0 ...
                                                    ///< [::xetSysmanFrequencyGetCount() - 1]).
    xet_freq_properties_t* pProperties              ///< [in] The frequency properties for the specified domain.
    )
{
    auto pfnFrequencyGetProperties = xet_lib::context.ddiTable.Sysman.pfnFrequencyGetProperties;
    if( nullptr == pfnFrequencyGetProperties )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnFrequencyGetProperties( hSysman, freqIndex, pProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get current frequency limits
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pLimits
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanFrequencyGetRange(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t freqIndex,                             ///< [in] The index of the frequency domain (0 ...
                                                    ///< [::xetSysmanFrequencyGetCount() - 1]).
    xet_freq_range_t* pLimits                       ///< [in] The range between which the hardware can operate for the
                                                    ///< specified domain.
    )
{
    auto pfnFrequencyGetRange = xet_lib::context.ddiTable.Sysman.pfnFrequencyGetRange;
    if( nullptr == pfnFrequencyGetRange )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnFrequencyGetRange( hSysman, freqIndex, pLimits );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Set frequency range between which the hardware can operate.
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pLimits
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanFrequencySetRange(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t freqIndex,                             ///< [in] The index of the frequency domain (0 ...
                                                    ///< [::xetSysmanFrequencyGetCount() - 1]).
    const xet_freq_range_t* pLimits                 ///< [in] The limits between which the hardware can operate for the
                                                    ///< specified domain.
    )
{
    auto pfnFrequencySetRange = xet_lib::context.ddiTable.Sysman.pfnFrequencySetRange;
    if( nullptr == pfnFrequencySetRange )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnFrequencySetRange( hSysman, freqIndex, pLimits );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get current frequency state - frequency request, actual frequency, TDP
///        limits
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pState
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanFrequencyGetState(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t freqIndex,                             ///< [in] The index of the frequency domain (0 ...
                                                    ///< [::xetSysmanFrequencyGetCount() - 1]).
    xet_freq_state_t* pState                        ///< [in] Frequency state for the specified domain.
    )
{
    auto pfnFrequencyGetState = xet_lib::context.ddiTable.Sysman.pfnFrequencyGetState;
    if( nullptr == pfnFrequencyGetState )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnFrequencyGetState( hSysman, freqIndex, pState );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get frequency throttle time
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pThrottleTime
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanFrequencyGetThrottleTime(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t freqIndex,                             ///< [in] The index of the frequency domain (0 ...
                                                    ///< [::xetSysmanFrequencyGetCount() - 1]).
    xet_freq_throttle_time_t* pThrottleTime         ///< [in] Will contain a snapshot of the throttle time counters for the
                                                    ///< specified domain.
    )
{
    auto pfnFrequencyGetThrottleTime = xet_lib::context.ddiTable.Sysman.pfnFrequencyGetThrottleTime;
    if( nullptr == pfnFrequencyGetThrottleTime )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnFrequencyGetThrottleTime( hSysman, freqIndex, pThrottleTime );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get the number of activity domains that can be monitored on this
///        device/sub-device
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pCount
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanActivityGetCount(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t* pCount                                ///< [in] The number of activity domains.
    )
{
    auto pfnActivityGetCount = xet_lib::context.ddiTable.Sysman.pfnActivityGetCount;
    if( nullptr == pfnActivityGetCount )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnActivityGetCount( hSysman, pCount );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get activity properties - type of activity counter, if the activity
///        counter is on a sub-device
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pProperties
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanActivityGetProperties(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t activityIndex,                         ///< [in] The index of the activity domain (0 ...
                                                    ///< [::xetSysmanActivityGetCount() - 1]).
    xet_activity_properties_t* pProperties          ///< [in] The properties for the specified activity domain.
    )
{
    auto pfnActivityGetProperties = xet_lib::context.ddiTable.Sysman.pfnActivityGetProperties;
    if( nullptr == pfnActivityGetProperties )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnActivityGetProperties( hSysman, activityIndex, pProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get the activity counters of a part of the device
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pStats
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanActivityGetStats(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t activityIndex,                         ///< [in] The index of the activity domain (0 ...
                                                    ///< [::xetSysmanActivityGetCount() - 1]).
    xet_activity_stats_t* pStats                    ///< [in] Will contain a snapshot of the activity counters.
    )
{
    auto pfnActivityGetStats = xet_lib::context.ddiTable.Sysman.pfnActivityGetStats;
    if( nullptr == pfnActivityGetStats )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnActivityGetStats( hSysman, activityIndex, pStats );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get the number of memory modules that can be monitored on this
///        device/sub-device
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pCount
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanMemoryGetCount(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t* pCount                                ///< [in] The number of memory modules.
    )
{
    auto pfnMemoryGetCount = xet_lib::context.ddiTable.Sysman.pfnMemoryGetCount;
    if( nullptr == pfnMemoryGetCount )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnMemoryGetCount( hSysman, pCount );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get memory properties
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pProperties
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanMemoryGetProperties(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t memIndex,                              ///< [in] The index of the memory module (0 ...
                                                    ///< [::xetSysmanMemoryGetCount() - 1]).
    xet_mem_properties_t* pProperties               ///< [in] Will contain memory properties.
    )
{
    auto pfnMemoryGetProperties = xet_lib::context.ddiTable.Sysman.pfnMemoryGetProperties;
    if( nullptr == pfnMemoryGetProperties )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnMemoryGetProperties( hSysman, memIndex, pProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get memory bandwidth
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pBandwidth
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanMemoryGetBandwidth(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t memIndex,                              ///< [in] The index of the memory module (0 ...
                                                    ///< [::xetSysmanMemoryGetCount() - 1]).
    xet_mem_bandwidth_t* pBandwidth                 ///< [in] Will contain a snapshot of the bandwidth counters.
    )
{
    auto pfnMemoryGetBandwidth = xet_lib::context.ddiTable.Sysman.pfnMemoryGetBandwidth;
    if( nullptr == pfnMemoryGetBandwidth )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnMemoryGetBandwidth( hSysman, memIndex, pBandwidth );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get memory allocation
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pAllocated
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanMemoryGetAllocated(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t memIndex,                              ///< [in] The index of the memory module (0 ...
                                                    ///< [::xetSysmanMemoryGetCount() - 1]).
    xet_mem_alloc_t* pAllocated                     ///< [in] Will contain the current allocated memory.
    )
{
    auto pfnMemoryGetAllocated = xet_lib::context.ddiTable.Sysman.pfnMemoryGetAllocated;
    if( nullptr == pfnMemoryGetAllocated )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnMemoryGetAllocated( hSysman, memIndex, pAllocated );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get the number of PCI end-points that can be monitored on this
///        device/sub-device
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pCount
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanPciGetCount(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t* pCount                                ///< [in] The number of PCI end-points.
    )
{
    auto pfnPciGetCount = xet_lib::context.ddiTable.Sysman.pfnPciGetCount;
    if( nullptr == pfnPciGetCount )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnPciGetCount( hSysman, pCount );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get PCI properties - address, max speed
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pProperties
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanPciGetProperties(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t pciIndex,                              ///< [in] The index of the PCI end-point (0 ... [::xetSysmanPciGetCount() -
                                                    ///< 1]).
    xet_pci_properties_t* pProperties               ///< [in] Will contain the PCI properties.
    )
{
    auto pfnPciGetProperties = xet_lib::context.ddiTable.Sysman.pfnPciGetProperties;
    if( nullptr == pfnPciGetProperties )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnPciGetProperties( hSysman, pciIndex, pProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get current PCI state - current speed
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pState
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanPciGetState(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t pciIndex,                              ///< [in] The index of the PCI end-point (0 ... [::xetSysmanPciGetCount() -
                                                    ///< 1]).
    xet_pci_state_t* pState                         ///< [in] Will contain the PCI properties.
    )
{
    auto pfnPciGetState = xet_lib::context.ddiTable.Sysman.pfnPciGetState;
    if( nullptr == pfnPciGetState )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnPciGetState( hSysman, pciIndex, pState );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get properties of a bar
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pProperties
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanPciGetBarProperties(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t pciIndex,                              ///< [in] The index of the PCI end-point (0 ... [::xetSysmanPciGetCount() -
                                                    ///< 1]).
    uint32_t barIndex,                              ///< [in] The index of the bar (0 ... [::xet_pci_properties_t.numBars -
                                                    ///< 1]).
    xet_pci_bar_properties_t* pProperties           ///< [in] Will contain properties of the specified bar
    )
{
    auto pfnPciGetBarProperties = xet_lib::context.ddiTable.Sysman.pfnPciGetBarProperties;
    if( nullptr == pfnPciGetBarProperties )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnPciGetBarProperties( hSysman, pciIndex, barIndex, pProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get PCI throughput
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pThroughput
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanPciGetThroughput(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t pciIndex,                              ///< [in] The index of the PCI end-point (0 ... [::xetSysmanPciGetCount() -
                                                    ///< 1]).
    xet_pci_throughput_t* pThroughput               ///< [in] Will contain a snapshot of the latest throughput counters.
    )
{
    auto pfnPciGetThroughput = xet_lib::context.ddiTable.Sysman.pfnPciGetThroughput;
    if( nullptr == pfnPciGetThroughput )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnPciGetThroughput( hSysman, pciIndex, pThroughput );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get PCI stats
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pStats
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanPciGetStats(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t pciIndex,                              ///< [in] The index of the PCI end-point (0 ... [::xetSysmanPciGetCount() -
                                                    ///< 1]).
    xet_pci_stats_t* pStats                         ///< [in] Will contain a snapshot of the latest stats.
    )
{
    auto pfnPciGetStats = xet_lib::context.ddiTable.Sysman.pfnPciGetStats;
    if( nullptr == pfnPciGetStats )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnPciGetStats( hSysman, pciIndex, pStats );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get the number of high-speed switches that can be monitored on this
///        device/sub-device
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pCount
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanSwitchGetCount(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t* pCount                                ///< [in] The number of high-speed switches.
    )
{
    auto pfnSwitchGetCount = xet_lib::context.ddiTable.Sysman.pfnSwitchGetCount;
    if( nullptr == pfnSwitchGetCount )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnSwitchGetCount( hSysman, pCount );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get Switch properties
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pProperties
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanSwitchGetProperties(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t switchIndex,                           ///< [in] The index of the switch (0 ... [::xetSysmanSwitchGetCount() -
                                                    ///< 1]).
    xet_switch_properties_t* pProperties            ///< [in] Will contain the Switch properties.
    )
{
    auto pfnSwitchGetProperties = xet_lib::context.ddiTable.Sysman.pfnSwitchGetProperties;
    if( nullptr == pfnSwitchGetProperties )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnSwitchGetProperties( hSysman, switchIndex, pProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get Switch state
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pState
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanSwitchGetState(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t switchIndex,                           ///< [in] The index of the switch (0 ... [::xetSysmanSwitchGetCount() -
                                                    ///< 1]).
    xet_switch_state_t* pState                      ///< [in] Will contain the current state of the switch (enabled/disabled).
    )
{
    auto pfnSwitchGetState = xet_lib::context.ddiTable.Sysman.pfnSwitchGetState;
    if( nullptr == pfnSwitchGetState )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnSwitchGetState( hSysman, switchIndex, pState );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Set Switch state
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanSwitchSetState(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t switchIndex,                           ///< [in] The index of the switch (0 ... [::xetSysmanSwitchGetCount() -
                                                    ///< 1]).
    xe_bool_t enable                                ///< [in] Set to true to enable the Switch, otherwise it will be disabled.
    )
{
    auto pfnSwitchSetState = xet_lib::context.ddiTable.Sysman.pfnSwitchSetState;
    if( nullptr == pfnSwitchSetState )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnSwitchSetState( hSysman, switchIndex, enable );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get Switch Port properties
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pProperties
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanSwitchPortGetProperties(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t switchIndex,                           ///< [in] The index of the switch (0 ... [::xetSysmanSwitchGetCount() -
                                                    ///< 1]).
    uint32_t portIndex,                             ///< [in] The index of the port (0 ... [::xet_switch_properties_t.numPorts
                                                    ///< - 1]).
    xet_switch_port_properties_t* pProperties       ///< [in] Will contain properties of the Switch Port
    )
{
    auto pfnSwitchPortGetProperties = xet_lib::context.ddiTable.Sysman.pfnSwitchPortGetProperties;
    if( nullptr == pfnSwitchPortGetProperties )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnSwitchPortGetProperties( hSysman, switchIndex, portIndex, pProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get Switch Port state
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pState
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanSwitchPortGetState(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t switchIndex,                           ///< [in] The index of the switch (0 ... [::xetSysmanSwitchGetCount() -
                                                    ///< 1]).
    uint32_t portIndex,                             ///< [in] The index of the port (0 ... [::xet_switch_properties_t.numPorts
                                                    ///< - 1]).
    xet_switch_port_state_t* pState                 ///< [in] Will contain the current state of the Switch Port
    )
{
    auto pfnSwitchPortGetState = xet_lib::context.ddiTable.Sysman.pfnSwitchPortGetState;
    if( nullptr == pfnSwitchPortGetState )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnSwitchPortGetState( hSysman, switchIndex, portIndex, pState );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get Switch Port throughput
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pThroughput
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanSwitchPortGetThroughput(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t switchIndex,                           ///< [in] The index of the switch (0 ... [::xetSysmanSwitchGetCount() -
                                                    ///< 1]).
    uint32_t portIndex,                             ///< [in] The index of the port (0 ... [::xet_switch_properties_t.numPorts
                                                    ///< - 1]).
    xet_switch_port_throughput_t* pThroughput       ///< [in] Will contain the Switch port throughput counters.
    )
{
    auto pfnSwitchPortGetThroughput = xet_lib::context.ddiTable.Sysman.pfnSwitchPortGetThroughput;
    if( nullptr == pfnSwitchPortGetThroughput )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnSwitchPortGetThroughput( hSysman, switchIndex, portIndex, pThroughput );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get Switch Port stats
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pStats
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanSwitchPortGetStats(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t switchIndex,                           ///< [in] The index of the switch (0 ... [::xetSysmanSwitchGetCount() -
                                                    ///< 1]).
    uint32_t portIndex,                             ///< [in] The index of the port (0 ... [::xet_switch_properties_t.numPorts
                                                    ///< - 1]).
    xet_switch_port_stats_t* pStats                 ///< [in] Will contain the Switch port stats.
    )
{
    auto pfnSwitchPortGetStats = xet_lib::context.ddiTable.Sysman.pfnSwitchPortGetStats;
    if( nullptr == pfnSwitchPortGetStats )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnSwitchPortGetStats( hSysman, switchIndex, portIndex, pStats );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get the number of temperature sensors that can be monitored on this
///        device/sub-device
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pCount
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanTemperatureGetCount(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t* pCount                                ///< [in] The number of temperature sensors.
    )
{
    auto pfnTemperatureGetCount = xet_lib::context.ddiTable.Sysman.pfnTemperatureGetCount;
    if( nullptr == pfnTemperatureGetCount )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnTemperatureGetCount( hSysman, pCount );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get temperature sensor properties
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pProperties
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanTemperatureGetProperties(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t tempIndex,                             ///< [in] The index of the temperature sensor (0 ...
                                                    ///< [::xetSysmanTemperatureGetCount() - 1]).
    xet_temp_properties_t* pProperties              ///< [in] Will contain the temperature sensor properties.
    )
{
    auto pfnTemperatureGetProperties = xet_lib::context.ddiTable.Sysman.pfnTemperatureGetProperties;
    if( nullptr == pfnTemperatureGetProperties )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnTemperatureGetProperties( hSysman, tempIndex, pProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get the temperature from a specified sensor
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pTemperature
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanTemperatureGet(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t tempIndex,                             ///< [in] The index of the temperature sensor (0 ...
                                                    ///< [::xetSysmanTemperatureGetCount() - 1]).
    uint32_t* pTemperature                          ///< [in] Will contain the temperature read from the specified sensor.
    )
{
    auto pfnTemperatureGet = xet_lib::context.ddiTable.Sysman.pfnTemperatureGet;
    if( nullptr == pfnTemperatureGet )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnTemperatureGet( hSysman, tempIndex, pTemperature );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get the number of standby hardware components that can be controlled
///        on this device/sub-device
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pCount
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanStandbyGetCount(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t* pCount                                ///< [in] The number of standby hardware components.
    )
{
    auto pfnStandbyGetCount = xet_lib::context.ddiTable.Sysman.pfnStandbyGetCount;
    if( nullptr == pfnStandbyGetCount )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnStandbyGetCount( hSysman, pCount );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get standby hardware component properties
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pProperties
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanStandbyGetProperties(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t stbyIndex,                             ///< [in] The index of the standby hardware component (0 ...
                                                    ///< [::xetSysmanStandbyGetCount() - 1]).
    xet_stby_properties_t* pProperties              ///< [in] Will contain the standby hardware properties.
    )
{
    auto pfnStandbyGetProperties = xet_lib::context.ddiTable.Sysman.pfnStandbyGetProperties;
    if( nullptr == pfnStandbyGetProperties )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnStandbyGetProperties( hSysman, stbyIndex, pProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get the current standby promotion mode
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pMode
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanStandbyGetMode(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t stbyIndex,                             ///< [in] The index of the standby hardware component (0 ...
                                                    ///< [::xetSysmanStandbyGetCount() - 1]).
    xet_stby_promo_mode_t* pMode                    ///< [in] Will contain the current standby mode.
    )
{
    auto pfnStandbyGetMode = xet_lib::context.ddiTable.Sysman.pfnStandbyGetMode;
    if( nullptr == pfnStandbyGetMode )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnStandbyGetMode( hSysman, stbyIndex, pMode );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Set standby promotion mode
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanStandbySetMode(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t stbyIndex,                             ///< [in] The index of the standby hardware component (0 ...
                                                    ///< [::xetSysmanStandbyGetCount() - 1]).
    xet_stby_promo_mode_t mode                      ///< [in] New standby mode.
    )
{
    auto pfnStandbySetMode = xet_lib::context.ddiTable.Sysman.pfnStandbySetMode;
    if( nullptr == pfnStandbySetMode )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnStandbySetMode( hSysman, stbyIndex, mode );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get the number of firmwares on this device/sub-device
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pCount
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanFirmwareGetCount(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t* pCount                                ///< [in] The number of firmwares.
    )
{
    auto pfnFirmwareGetCount = xet_lib::context.ddiTable.Sysman.pfnFirmwareGetCount;
    if( nullptr == pfnFirmwareGetCount )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnFirmwareGetCount( hSysman, pCount );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get firmware properties
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pProperties
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanFirmwareGetProperties(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t firmwareIndex,                         ///< [in] The index of the firmware (0 ... [::xetSysmanFirmwareGetCount() -
                                                    ///< 1]).
    xet_firmware_properties_t* pProperties          ///< [in] Pointer to an array that will hold the properties of the firmware
    )
{
    auto pfnFirmwareGetProperties = xet_lib::context.ddiTable.Sysman.pfnFirmwareGetProperties;
    if( nullptr == pfnFirmwareGetProperties )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnFirmwareGetProperties( hSysman, firmwareIndex, pProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get firmware checksum
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pChecksum
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanFirmwareGetChecksum(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t firmwareIndex,                         ///< [in] The index of the firmware (0 ... [::xetSysmanFirmwareGetCount() -
                                                    ///< 1]).
    uint32_t* pChecksum                             ///< [in] Calculated checksum of the installed firmware.
    )
{
    auto pfnFirmwareGetChecksum = xet_lib::context.ddiTable.Sysman.pfnFirmwareGetChecksum;
    if( nullptr == pfnFirmwareGetChecksum )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnFirmwareGetChecksum( hSysman, firmwareIndex, pChecksum );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Flash a new firmware image
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pImage
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanFirmwareFlash(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t firmwareIndex,                         ///< [in] The index of the firmware (0 ... [::xetSysmanFirmwareGetCount() -
                                                    ///< 1]).
    void* pImage,                                   ///< [in] Image of the new firmware to flash.
    uint32_t size                                   ///< [in] Size of the flash image.
    )
{
    auto pfnFirmwareFlash = xet_lib::context.ddiTable.Sysman.pfnFirmwareFlash;
    if( nullptr == pfnFirmwareFlash )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnFirmwareFlash( hSysman, firmwareIndex, pImage, size );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get the number of PSU attached this device/sub-device
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pCount
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanPsuGetCount(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t* pCount                                ///< [in] The number of PSUs.
    )
{
    auto pfnPsuGetCount = xet_lib::context.ddiTable.Sysman.pfnPsuGetCount;
    if( nullptr == pfnPsuGetCount )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnPsuGetCount( hSysman, pCount );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get power supply properties
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pProperties
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanPsuGetProperties(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t psuIndex,                              ///< [in] The index of the power supply (0 ... [::xetSysmanPsuGetCount() -
                                                    ///< 1]).
    xet_psu_properties_t* pProperties               ///< [in] Will contain the properties of the power supply.
    )
{
    auto pfnPsuGetProperties = xet_lib::context.ddiTable.Sysman.pfnPsuGetProperties;
    if( nullptr == pfnPsuGetProperties )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnPsuGetProperties( hSysman, psuIndex, pProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get current power supply state
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pState
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanPsuGetState(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t psuIndex,                              ///< [in] The index of the power supply (0 ... [::xetSysmanPsuGetCount() -
                                                    ///< 1]).
    xet_psu_state_t* pState                         ///< [in] Will contain the current state of the power supply.
    )
{
    auto pfnPsuGetState = xet_lib::context.ddiTable.Sysman.pfnPsuGetState;
    if( nullptr == pfnPsuGetState )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnPsuGetState( hSysman, psuIndex, pState );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get the number of fans attached this device/sub-device
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pCount
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanFanGetCount(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t* pCount                                ///< [in] The number of fans.
    )
{
    auto pfnFanGetCount = xet_lib::context.ddiTable.Sysman.pfnFanGetCount;
    if( nullptr == pfnFanGetCount )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnFanGetCount( hSysman, pCount );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get fan properties
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pProperties
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanFanGetProperties(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t fanIndex,                              ///< [in] The index of the fan (0 ... [::xetSysmanFanGetCount() - 1]).
    xet_fan_properties_t* pProperties               ///< [in] Will contain the properties of the fan.
    )
{
    auto pfnFanGetProperties = xet_lib::context.ddiTable.Sysman.pfnFanGetProperties;
    if( nullptr == pfnFanGetProperties )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnFanGetProperties( hSysman, fanIndex, pProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get current fan configuration
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pConfig
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanFanGetConfig(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t fanIndex,                              ///< [in] The index of the fan (0 ... [::xetSysmanFanGetCount() - 1]).
    xet_fan_config_t* pConfig                       ///< [in] Will contain the current configuration of the fan.
    )
{
    auto pfnFanGetConfig = xet_lib::context.ddiTable.Sysman.pfnFanGetConfig;
    if( nullptr == pfnFanGetConfig )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnFanGetConfig( hSysman, fanIndex, pConfig );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Set fan configuration
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pConfig
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanFanSetConfig(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t fanIndex,                              ///< [in] The index of the fan (0 ... [::xetSysmanFanGetCount() - 1]).
    const xet_fan_config_t* pConfig                 ///< [in] New fan configuration.
    )
{
    auto pfnFanSetConfig = xet_lib::context.ddiTable.Sysman.pfnFanSetConfig;
    if( nullptr == pfnFanSetConfig )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnFanSetConfig( hSysman, fanIndex, pConfig );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get current state of a fan - current mode and speed
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pState
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanFanGetState(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t fanIndex,                              ///< [in] The index of the fan (0 ... [::xetSysmanFanGetCount() - 1]).
    xet_fan_speed_units_t units,                    ///< [in] The units in which the fan speed should be returned.
    xet_fan_state_t* pState                         ///< [in] Will contain the current state of the fan.
    )
{
    auto pfnFanGetState = xet_lib::context.ddiTable.Sysman.pfnFanGetState;
    if( nullptr == pfnFanGetState )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnFanGetState( hSysman, fanIndex, units, pState );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get the number of PSU attached this device/sub-device
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pCount
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanLedGetCount(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t* pCount                                ///< [in] The number of LEDs.
    )
{
    auto pfnLedGetCount = xet_lib::context.ddiTable.Sysman.pfnLedGetCount;
    if( nullptr == pfnLedGetCount )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnLedGetCount( hSysman, pCount );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get LED properties
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pProperties
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanLedGetProperties(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t ledIndex,                              ///< [in] The index of the LED (0 ... [::xetSysmanLedGetCount() - 1]).
    xet_led_properties_t* pProperties               ///< [in] Will contain the properties of the LED.
    )
{
    auto pfnLedGetProperties = xet_lib::context.ddiTable.Sysman.pfnLedGetProperties;
    if( nullptr == pfnLedGetProperties )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnLedGetProperties( hSysman, ledIndex, pProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get current state of a LED - on/off, color
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pState
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanLedGetState(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t ledIndex,                              ///< [in] The index of the LED (0 ... [::xetSysmanLedGetCount() - 1]).
    xet_led_state_t* pState                         ///< [in] Will contain the current state of the LED.
    )
{
    auto pfnLedGetState = xet_lib::context.ddiTable.Sysman.pfnLedGetState;
    if( nullptr == pfnLedGetState )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnLedGetState( hSysman, ledIndex, pState );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Set state of a LED - on/off, color
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pState
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanLedSetState(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t ledIndex,                              ///< [in] The index of the LED (0 ... [::xetSysmanLedGetCount() - 1]).
    const xet_led_state_t* pState                   ///< [in] New state of the LED.
    )
{
    auto pfnLedSetState = xet_lib::context.ddiTable.Sysman.pfnLedSetState;
    if( nullptr == pfnLedSetState )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnLedSetState( hSysman, ledIndex, pState );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get the number of RAS error sets on this device/sub-device
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pCount
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanRasGetCount(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t* pCount                                ///< [in] The number of RAS errors sets.
    )
{
    auto pfnRasGetCount = xet_lib::context.ddiTable.Sysman.pfnRasGetCount;
    if( nullptr == pfnRasGetCount )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnRasGetCount( hSysman, pCount );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get RAS properties of the device
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pProperties
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanRasGetProperties(
    xet_sysman_handle_t hSysman,                    ///< [in] Handle of the SMI object
    uint32_t rasIndex,                              ///< [in] The index of the RAS error set (0 ... [::xetSysmanRasGetCount() -
                                                    ///< 1]).
    xet_ras_properties_t* pProperties               ///< [in] Structure describing RAS properties
    )
{
    auto pfnRasGetProperties = xet_lib::context.ddiTable.Sysman.pfnRasGetProperties;
    if( nullptr == pfnRasGetProperties )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnRasGetProperties( hSysman, rasIndex, pProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get the number of errors of a given RAS error set
/// 
/// @details
///     - Clearing errors will affect other threads/applications - the counter
///       values will start from zero.
///     - Clearing errors requires write permissions.
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pTotalErrors
///     - ::XE_RESULT_ERROR_UNSUPPORTED
///         + This device does not support RAS.
///     - ::XE_RESULT_ERROR_INSUFFICENT_PERMISSIONS
///         + Don't have permissions to clear error counters.
xe_result_t __xecall
xetSysmanRasGetErrors(
    xet_sysman_handle_t hSysman,                    ///< [in] Handle of the SMI object
    uint32_t rasIndex,                              ///< [in] The index of the RAS error set (0 ... [::xetSysmanRasGetCount() -
                                                    ///< 1]).
    xe_bool_t clear,                                ///< [in] Set to 1 to clear the counters of this type
    uint64_t* pTotalErrors,                         ///< [in] The number total number of errors that have occurred
    xet_ras_details_t* pDetails                     ///< [in][optional] Breakdown of where errors have occurred
    )
{
    auto pfnRasGetErrors = xet_lib::context.ddiTable.Sysman.pfnRasGetErrors;
    if( nullptr == pfnRasGetErrors )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnRasGetErrors( hSysman, rasIndex, clear, pTotalErrors, pDetails );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get event properties
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pProperties
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanEventsGetProperties(
    xet_sysman_handle_t hSysman,                    ///< [in] Handle of the SMI object
    xet_event_properties_t* pProperties             ///< [in] Structure describing event properties
    )
{
    auto pfnEventsGetProperties = xet_lib::context.ddiTable.Sysman.pfnEventsGetProperties;
    if( nullptr == pfnEventsGetProperties )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnEventsGetProperties( hSysman, pProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Register to receive events
/// 
/// @details
///     - This will only register the specified list of events. If other events
///       have been registered, notifications for them will continue.
///     - Set count to zero to receive notifications for all events.
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanEventsRegister(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle for the device
    uint32_t count,                                 ///< [in] Number of entries in the array pEvents. If zero, all events will
                                                    ///< be registered.
    xet_event_request_t* pEvents                    ///< [in][optional] Events to register.
    )
{
    auto pfnEventsRegister = xet_lib::context.ddiTable.Sysman.pfnEventsRegister;
    if( nullptr == pfnEventsRegister )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnEventsRegister( hSysman, count, pEvents );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Unregister events
/// 
/// @details
///     - This will only unregister the specified list of events. If other
///       events have been registered, notifications for them will continue.
///     - Set count to zero to no longer receive any notifications.
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanEventsUnregister(
    xet_sysman_handle_t hSysman,                    ///< [in] Handle of the SMI object
    uint32_t count,                                 ///< [in] Number of entries in the array pEvents. If zero, all events will
                                                    ///< be unregistered.
    xet_event_request_t* pEvents                    ///< [in][optional] Events to unregister.
    )
{
    auto pfnEventsUnregister = xet_lib::context.ddiTable.Sysman.pfnEventsUnregister;
    if( nullptr == pfnEventsUnregister )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnEventsUnregister( hSysman, count, pEvents );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get events that have been triggered for a specific device or from all
///        registered devices
/// 
/// @details
///     - If events have occurred, they are returned and the corresponding event
///       status is cleared if the argument clear = true.
///     - If listening to events from multiple devices, it is recommended to
///       call this function with hSysman = nullptr, clear = false and timeout =
///       ::XET_EVENT_WAIT_INFINITE. Then call this function for each device
///       with clear = true and timeout = 0.
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pEvents
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanEventsListen(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle for a device. Set to nullptr to get events from any
                                                    ///< device for which the application has registered to receive
                                                    ///< notifications.
    xe_bool_t clear,                                ///< [in] Clear the event status.
    uint32_t timeout,                               ///< [in] How long to wait in milliseconds for events to arrive. Zero will
                                                    ///< check status and return immediately. Set to ::XET_EVENT_WAIT_INFINITE
                                                    ///< to block until events arrive.
    uint32_t* pEvents                               ///< [in] Bitfield of events (1<<::xet_sysman_event_type_t) that have been
                                                    ///< triggered.
    )
{
    auto pfnEventsListen = xet_lib::context.ddiTable.Sysman.pfnEventsListen;
    if( nullptr == pfnEventsListen )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnEventsListen( hSysman, clear, timeout, pEvents );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get the number of diagnostic test suites that can be run on this
///        device/sub-device
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pCount
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanDiagnosticsGetCount(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle of the device.
    uint32_t* pCount                                ///< [in] The number of diagnostic test suites.
    )
{
    auto pfnDiagnosticsGetCount = xet_lib::context.ddiTable.Sysman.pfnDiagnosticsGetCount;
    if( nullptr == pfnDiagnosticsGetCount )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnDiagnosticsGetCount( hSysman, pCount );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Get properties of a diagnostics test suite
/// 
/// @details
///     - The application may call this function from simultaneous threads.
///     - The implementation of this function should be lock-free.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pProperties
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanDiagnosticsGetProperties(
    xet_sysman_handle_t hSysman,                    ///< [in] Handle of the SMI object
    uint32_t testIndex,                             ///< [in] The index of a diagnostics test (0 ...
                                                    ///< [::xetSysmanDiagnosticsGetCount() - 1]).
    xet_diag_properties_t* pProperties              ///< [in] Structure describing the properties of a diagnostics test suite
    )
{
    auto pfnDiagnosticsGetProperties = xet_lib::context.ddiTable.Sysman.pfnDiagnosticsGetProperties;
    if( nullptr == pfnDiagnosticsGetProperties )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnDiagnosticsGetProperties( hSysman, testIndex, pProperties );
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Run a diagnostics test suite, either all tests or a subset of tests.
/// 
/// @details
///     - This function will block until the diagnostics have completed.
/// 
/// @returns
///     - ::XE_RESULT_SUCCESS
///     - ::XE_RESULT_ERROR_UNINITIALIZED
///     - ::XE_RESULT_ERROR_DEVICE_LOST
///     - ::XE_RESULT_ERROR_INVALID_ARGUMENT
///         + nullptr == hSysman
///         + nullptr == pResult
///     - ::XE_RESULT_ERROR_UNSUPPORTED
xe_result_t __xecall
xetSysmanDiagnosticsRunTests(
    xet_sysman_handle_t hSysman,                    ///< [in] SMI handle for the device
    uint32_t testIndex,                             ///< [in] The index of a diagnostics test (0 ...
                                                    ///< [::xetSysmanDiagnosticsGetCount() - 1]).
    uint32_t start,                                 ///< [in] The index of the first test to run. Set to
                                                    ///< ::XET_DIAG_FIRST_TEST_INDEX to start from the beginning.
    uint32_t end,                                   ///< [in] The index of the last test to run. Set to
                                                    ///< ::XET_DIAG_LAST_TEST_INDEX to complete all tests after the start test.
    xet_diag_result_t* pResult                      ///< [in] The result of the diagnostics
    )
{
    auto pfnDiagnosticsRunTests = xet_lib::context.ddiTable.Sysman.pfnDiagnosticsRunTests;
    if( nullptr == pfnDiagnosticsRunTests )
        return XE_RESULT_ERROR_UNSUPPORTED;

    return pfnDiagnosticsRunTests( hSysman, testIndex, start, end, pResult );
}

} // extern "C"

namespace xet
{
    ///////////////////////////////////////////////////////////////////////////////
    Sysman::Sysman( 
        sysman_handle_t handle,                         ///< [in] handle of SMI object
        Device* pDevice                                 ///< [in] pointer to owner object
        ) :
        m_handle( handle ),
        m_pDevice( pDevice )
    {
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get the handle to access SMI features for a device
    /// 
    /// @details
    ///     - The returned handle is unique
    /// 
    /// @returns
    ///     - Sysman*: Handle for accessing SMI features
    /// 
    /// @throws result_t
    Sysman* __xecall
    Sysman::Get(
        Device* pDevice,                                ///< [in] Handle of the device
        version_t version                               ///< [in] SMI version that application was built with
        )
    {
        xet_sysman_handle_t hSysman;

        auto result = static_cast<result_t>( ::xetSysmanGet(
            reinterpret_cast<xet_device_handle_t>( pDevice->getHandle() ),
            static_cast<xet_sysman_version_t>( version ),
            &hSysman ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::Get" );

        Sysman* pSysman = nullptr;

        try
        {
            pSysman = new Sysman( reinterpret_cast<sysman_handle_t>( hSysman ), pDevice );
        }
        catch( std::bad_alloc& )
        {
            delete pSysman;
            pSysman = nullptr;

            throw exception_t( result_t::ERROR_OUT_OF_HOST_MEMORY, __FILE__, STRING(__LINE__), "xet::Sysman::Get" );
        }

        return pSysman;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get properties about the device
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::DeviceGetProperties(
        properties_t* pProperties                       ///< [in] Structure that will contain information about the device.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanDeviceGetProperties(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            reinterpret_cast<xet_sysman_properties_t*>( pProperties ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::DeviceGetProperties" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get optimization mode of the device
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::DeviceGetOptimizationMode(
        optimization_mode_t* pMode                      ///< [in] The current optimization mode of the device.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanDeviceGetOptimizationMode(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            reinterpret_cast<xet_optimization_mode_t*>( pMode ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::DeviceGetOptimizationMode" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Set optimization mode of the device
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::DeviceSetOptimizationMode(
        optimization_mode_t pMode                       ///< [in] The new optimization mode of the device.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanDeviceSetOptimizationMode(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            static_cast<xet_optimization_mode_t>( pMode ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::DeviceSetOptimizationMode" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Reset device
    /// 
    /// @throws result_t
    void __xecall
    Sysman::DeviceReset(
        void
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanDeviceReset(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::DeviceReset" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get the number of power domains
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::PowerGetCount(
        uint32_t* pCount                                ///< [in] The number of power domains.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanPowerGetCount(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pCount ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::PowerGetCount" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get properties related to a power domain
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::PowerGetProperties(
        uint32_t pwrIndex,                              ///< [in] The index of the power domain (0 ... [::xetSysmanPowerGetCount()
                                                        ///< - 1]).
        power_properties_t* pProperties                 ///< [in] Structure that will contain property data.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanPowerGetProperties(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pwrIndex,
            reinterpret_cast<xet_power_properties_t*>( pProperties ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::PowerGetProperties" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get energy counter
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::PowerGetEnergyCounter(
        uint32_t pwrIndex,                              ///< [in] The index of the power domain (0 ... [::xetSysmanPowerGetCount()
                                                        ///< - 1]).
        power_energy_counter_t* pEnergy                 ///< [in] Will contain the latest snapshot of the energy counter and
                                                        ///< timestamp when the last counter value was measured.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanPowerGetEnergyCounter(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pwrIndex,
            reinterpret_cast<xet_power_energy_counter_t*>( pEnergy ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::PowerGetEnergyCounter" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get energy threshold
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @returns
    ///     - power_energy_threshold_t: The current energy threshold value in joules.
    /// 
    /// @throws result_t
    Sysman::power_energy_threshold_t __xecall
    Sysman::PowerGetEnergyThreshold(
        uint32_t pwrIndex                               ///< [in] The index of the power domain (0 ... [::xetSysmanPowerGetCount()
                                                        ///< - 1]).
        )
    {
        xet_power_energy_threshold_t threshold;

        auto result = static_cast<result_t>( ::xetSysmanPowerGetEnergyThreshold(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pwrIndex,
            &threshold ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::PowerGetEnergyThreshold" );

        return *reinterpret_cast<power_energy_threshold_t*>( &threshold );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Set energy threshold
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::PowerSetEnergyThreshold(
        uint32_t pwrIndex,                              ///< [in] The index of the power domain (0 ... [::xetSysmanPowerGetCount()
                                                        ///< - 1]).
        power_energy_threshold_t* pThreshold            ///< [in] The energy threshold to be set in joules.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanPowerSetEnergyThreshold(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pwrIndex,
            reinterpret_cast<xet_power_energy_threshold_t*>( pThreshold ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::PowerSetEnergyThreshold" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get power limits
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::PowerGetLimits(
        uint32_t pwrIndex,                              ///< [in] The index of the power domain (0 ... [::xetSysmanPowerGetCount()
                                                        ///< - 1]).
        power_sustained_limit_t* pSustained,            ///< [in][optional] The sustained power limit.
        power_burst_limit_t* pBurst,                    ///< [in][optional] The burst power limit.
        power_peak_limit_t* pPeak                       ///< [in][optional] The peak power limit.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanPowerGetLimits(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pwrIndex,
            reinterpret_cast<xet_power_sustained_limit_t*>( pSustained ),
            reinterpret_cast<xet_power_burst_limit_t*>( pBurst ),
            reinterpret_cast<xet_power_peak_limit_t*>( pPeak ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::PowerGetLimits" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Set power limits
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::PowerSetLimits(
        uint32_t pwrIndex,                              ///< [in] The index of the power domain (0 ... [::xetSysmanPowerGetCount()
                                                        ///< - 1]).
        const power_sustained_limit_t* pSustained,      ///< [in][optional] The sustained power limit.
        const power_burst_limit_t* pBurst,              ///< [in][optional] The burst power limit.
        const power_peak_limit_t* pPeak                 ///< [in][optional] The peak power limit.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanPowerSetLimits(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pwrIndex,
            reinterpret_cast<const xet_power_sustained_limit_t*>( pSustained ),
            reinterpret_cast<const xet_power_burst_limit_t*>( pBurst ),
            reinterpret_cast<const xet_power_peak_limit_t*>( pPeak ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::PowerSetLimits" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get the number of frequency domains
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::FrequencyGetCount(
        uint32_t* pCount                                ///< [in] The number of frequency domains.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanFrequencyGetCount(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pCount ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::FrequencyGetCount" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get frequency properties - available frequencies
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::FrequencyGetProperties(
        uint32_t freqIndex,                             ///< [in] The index of the frequency domain (0 ...
                                                        ///< [::xetSysmanFrequencyGetCount() - 1]).
        freq_properties_t* pProperties                  ///< [in] The frequency properties for the specified domain.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanFrequencyGetProperties(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            freqIndex,
            reinterpret_cast<xet_freq_properties_t*>( pProperties ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::FrequencyGetProperties" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get current frequency limits
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::FrequencyGetRange(
        uint32_t freqIndex,                             ///< [in] The index of the frequency domain (0 ...
                                                        ///< [::xetSysmanFrequencyGetCount() - 1]).
        freq_range_t* pLimits                           ///< [in] The range between which the hardware can operate for the
                                                        ///< specified domain.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanFrequencyGetRange(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            freqIndex,
            reinterpret_cast<xet_freq_range_t*>( pLimits ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::FrequencyGetRange" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Set frequency range between which the hardware can operate.
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::FrequencySetRange(
        uint32_t freqIndex,                             ///< [in] The index of the frequency domain (0 ...
                                                        ///< [::xetSysmanFrequencyGetCount() - 1]).
        const freq_range_t* pLimits                     ///< [in] The limits between which the hardware can operate for the
                                                        ///< specified domain.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanFrequencySetRange(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            freqIndex,
            reinterpret_cast<const xet_freq_range_t*>( pLimits ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::FrequencySetRange" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get current frequency state - frequency request, actual frequency, TDP
    ///        limits
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::FrequencyGetState(
        uint32_t freqIndex,                             ///< [in] The index of the frequency domain (0 ...
                                                        ///< [::xetSysmanFrequencyGetCount() - 1]).
        freq_state_t* pState                            ///< [in] Frequency state for the specified domain.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanFrequencyGetState(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            freqIndex,
            reinterpret_cast<xet_freq_state_t*>( pState ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::FrequencyGetState" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get frequency throttle time
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::FrequencyGetThrottleTime(
        uint32_t freqIndex,                             ///< [in] The index of the frequency domain (0 ...
                                                        ///< [::xetSysmanFrequencyGetCount() - 1]).
        freq_throttle_time_t* pThrottleTime             ///< [in] Will contain a snapshot of the throttle time counters for the
                                                        ///< specified domain.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanFrequencyGetThrottleTime(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            freqIndex,
            reinterpret_cast<xet_freq_throttle_time_t*>( pThrottleTime ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::FrequencyGetThrottleTime" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get the number of activity domains that can be monitored on this
    ///        device/sub-device
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::ActivityGetCount(
        uint32_t* pCount                                ///< [in] The number of activity domains.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanActivityGetCount(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pCount ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::ActivityGetCount" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get activity properties - type of activity counter, if the activity
    ///        counter is on a sub-device
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::ActivityGetProperties(
        uint32_t activityIndex,                         ///< [in] The index of the activity domain (0 ...
                                                        ///< [::xetSysmanActivityGetCount() - 1]).
        activity_properties_t* pProperties              ///< [in] The properties for the specified activity domain.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanActivityGetProperties(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            activityIndex,
            reinterpret_cast<xet_activity_properties_t*>( pProperties ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::ActivityGetProperties" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get the activity counters of a part of the device
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::ActivityGetStats(
        uint32_t activityIndex,                         ///< [in] The index of the activity domain (0 ...
                                                        ///< [::xetSysmanActivityGetCount() - 1]).
        activity_stats_t* pStats                        ///< [in] Will contain a snapshot of the activity counters.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanActivityGetStats(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            activityIndex,
            reinterpret_cast<xet_activity_stats_t*>( pStats ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::ActivityGetStats" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get the number of memory modules that can be monitored on this
    ///        device/sub-device
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::MemoryGetCount(
        uint32_t* pCount                                ///< [in] The number of memory modules.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanMemoryGetCount(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pCount ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::MemoryGetCount" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get memory properties
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::MemoryGetProperties(
        uint32_t memIndex,                              ///< [in] The index of the memory module (0 ...
                                                        ///< [::xetSysmanMemoryGetCount() - 1]).
        mem_properties_t* pProperties                   ///< [in] Will contain memory properties.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanMemoryGetProperties(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            memIndex,
            reinterpret_cast<xet_mem_properties_t*>( pProperties ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::MemoryGetProperties" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get memory bandwidth
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::MemoryGetBandwidth(
        uint32_t memIndex,                              ///< [in] The index of the memory module (0 ...
                                                        ///< [::xetSysmanMemoryGetCount() - 1]).
        mem_bandwidth_t* pBandwidth                     ///< [in] Will contain a snapshot of the bandwidth counters.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanMemoryGetBandwidth(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            memIndex,
            reinterpret_cast<xet_mem_bandwidth_t*>( pBandwidth ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::MemoryGetBandwidth" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get memory allocation
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::MemoryGetAllocated(
        uint32_t memIndex,                              ///< [in] The index of the memory module (0 ...
                                                        ///< [::xetSysmanMemoryGetCount() - 1]).
        mem_alloc_t* pAllocated                         ///< [in] Will contain the current allocated memory.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanMemoryGetAllocated(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            memIndex,
            reinterpret_cast<xet_mem_alloc_t*>( pAllocated ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::MemoryGetAllocated" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get the number of PCI end-points that can be monitored on this
    ///        device/sub-device
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::PciGetCount(
        uint32_t* pCount                                ///< [in] The number of PCI end-points.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanPciGetCount(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pCount ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::PciGetCount" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get PCI properties - address, max speed
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::PciGetProperties(
        uint32_t pciIndex,                              ///< [in] The index of the PCI end-point (0 ... [::xetSysmanPciGetCount() -
                                                        ///< 1]).
        pci_properties_t* pProperties                   ///< [in] Will contain the PCI properties.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanPciGetProperties(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pciIndex,
            reinterpret_cast<xet_pci_properties_t*>( pProperties ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::PciGetProperties" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get current PCI state - current speed
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::PciGetState(
        uint32_t pciIndex,                              ///< [in] The index of the PCI end-point (0 ... [::xetSysmanPciGetCount() -
                                                        ///< 1]).
        pci_state_t* pState                             ///< [in] Will contain the PCI properties.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanPciGetState(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pciIndex,
            reinterpret_cast<xet_pci_state_t*>( pState ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::PciGetState" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get properties of a bar
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::PciGetBarProperties(
        uint32_t pciIndex,                              ///< [in] The index of the PCI end-point (0 ... [::xetSysmanPciGetCount() -
                                                        ///< 1]).
        uint32_t barIndex,                              ///< [in] The index of the bar (0 ... [::xet_pci_properties_t.numBars -
                                                        ///< 1]).
        pci_bar_properties_t* pProperties               ///< [in] Will contain properties of the specified bar
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanPciGetBarProperties(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pciIndex,
            barIndex,
            reinterpret_cast<xet_pci_bar_properties_t*>( pProperties ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::PciGetBarProperties" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get PCI throughput
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::PciGetThroughput(
        uint32_t pciIndex,                              ///< [in] The index of the PCI end-point (0 ... [::xetSysmanPciGetCount() -
                                                        ///< 1]).
        pci_throughput_t* pThroughput                   ///< [in] Will contain a snapshot of the latest throughput counters.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanPciGetThroughput(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pciIndex,
            reinterpret_cast<xet_pci_throughput_t*>( pThroughput ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::PciGetThroughput" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get PCI stats
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::PciGetStats(
        uint32_t pciIndex,                              ///< [in] The index of the PCI end-point (0 ... [::xetSysmanPciGetCount() -
                                                        ///< 1]).
        pci_stats_t* pStats                             ///< [in] Will contain a snapshot of the latest stats.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanPciGetStats(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pciIndex,
            reinterpret_cast<xet_pci_stats_t*>( pStats ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::PciGetStats" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get the number of high-speed switches that can be monitored on this
    ///        device/sub-device
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::SwitchGetCount(
        uint32_t* pCount                                ///< [in] The number of high-speed switches.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanSwitchGetCount(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pCount ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::SwitchGetCount" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get Switch properties
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::SwitchGetProperties(
        uint32_t switchIndex,                           ///< [in] The index of the switch (0 ... [::xetSysmanSwitchGetCount() -
                                                        ///< 1]).
        switch_properties_t* pProperties                ///< [in] Will contain the Switch properties.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanSwitchGetProperties(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            switchIndex,
            reinterpret_cast<xet_switch_properties_t*>( pProperties ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::SwitchGetProperties" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get Switch state
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::SwitchGetState(
        uint32_t switchIndex,                           ///< [in] The index of the switch (0 ... [::xetSysmanSwitchGetCount() -
                                                        ///< 1]).
        switch_state_t* pState                          ///< [in] Will contain the current state of the switch (enabled/disabled).
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanSwitchGetState(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            switchIndex,
            reinterpret_cast<xet_switch_state_t*>( pState ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::SwitchGetState" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Set Switch state
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::SwitchSetState(
        uint32_t switchIndex,                           ///< [in] The index of the switch (0 ... [::xetSysmanSwitchGetCount() -
                                                        ///< 1]).
        xe::bool_t enable                               ///< [in] Set to true to enable the Switch, otherwise it will be disabled.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanSwitchSetState(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            switchIndex,
            static_cast<xe_bool_t>( enable ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::SwitchSetState" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get Switch Port properties
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::SwitchPortGetProperties(
        uint32_t switchIndex,                           ///< [in] The index of the switch (0 ... [::xetSysmanSwitchGetCount() -
                                                        ///< 1]).
        uint32_t portIndex,                             ///< [in] The index of the port (0 ... [::xet_switch_properties_t.numPorts
                                                        ///< - 1]).
        switch_port_properties_t* pProperties           ///< [in] Will contain properties of the Switch Port
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanSwitchPortGetProperties(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            switchIndex,
            portIndex,
            reinterpret_cast<xet_switch_port_properties_t*>( pProperties ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::SwitchPortGetProperties" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get Switch Port state
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::SwitchPortGetState(
        uint32_t switchIndex,                           ///< [in] The index of the switch (0 ... [::xetSysmanSwitchGetCount() -
                                                        ///< 1]).
        uint32_t portIndex,                             ///< [in] The index of the port (0 ... [::xet_switch_properties_t.numPorts
                                                        ///< - 1]).
        switch_port_state_t* pState                     ///< [in] Will contain the current state of the Switch Port
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanSwitchPortGetState(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            switchIndex,
            portIndex,
            reinterpret_cast<xet_switch_port_state_t*>( pState ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::SwitchPortGetState" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get Switch Port throughput
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::SwitchPortGetThroughput(
        uint32_t switchIndex,                           ///< [in] The index of the switch (0 ... [::xetSysmanSwitchGetCount() -
                                                        ///< 1]).
        uint32_t portIndex,                             ///< [in] The index of the port (0 ... [::xet_switch_properties_t.numPorts
                                                        ///< - 1]).
        switch_port_throughput_t* pThroughput           ///< [in] Will contain the Switch port throughput counters.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanSwitchPortGetThroughput(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            switchIndex,
            portIndex,
            reinterpret_cast<xet_switch_port_throughput_t*>( pThroughput ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::SwitchPortGetThroughput" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get Switch Port stats
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::SwitchPortGetStats(
        uint32_t switchIndex,                           ///< [in] The index of the switch (0 ... [::xetSysmanSwitchGetCount() -
                                                        ///< 1]).
        uint32_t portIndex,                             ///< [in] The index of the port (0 ... [::xet_switch_properties_t.numPorts
                                                        ///< - 1]).
        switch_port_stats_t* pStats                     ///< [in] Will contain the Switch port stats.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanSwitchPortGetStats(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            switchIndex,
            portIndex,
            reinterpret_cast<xet_switch_port_stats_t*>( pStats ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::SwitchPortGetStats" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get the number of temperature sensors that can be monitored on this
    ///        device/sub-device
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::TemperatureGetCount(
        uint32_t* pCount                                ///< [in] The number of temperature sensors.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanTemperatureGetCount(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pCount ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::TemperatureGetCount" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get temperature sensor properties
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::TemperatureGetProperties(
        uint32_t tempIndex,                             ///< [in] The index of the temperature sensor (0 ...
                                                        ///< [::xetSysmanTemperatureGetCount() - 1]).
        temp_properties_t* pProperties                  ///< [in] Will contain the temperature sensor properties.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanTemperatureGetProperties(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            tempIndex,
            reinterpret_cast<xet_temp_properties_t*>( pProperties ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::TemperatureGetProperties" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get the temperature from a specified sensor
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::TemperatureGet(
        uint32_t tempIndex,                             ///< [in] The index of the temperature sensor (0 ...
                                                        ///< [::xetSysmanTemperatureGetCount() - 1]).
        uint32_t* pTemperature                          ///< [in] Will contain the temperature read from the specified sensor.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanTemperatureGet(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            tempIndex,
            pTemperature ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::TemperatureGet" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get the number of standby hardware components that can be controlled
    ///        on this device/sub-device
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::StandbyGetCount(
        uint32_t* pCount                                ///< [in] The number of standby hardware components.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanStandbyGetCount(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pCount ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::StandbyGetCount" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get standby hardware component properties
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::StandbyGetProperties(
        uint32_t stbyIndex,                             ///< [in] The index of the standby hardware component (0 ...
                                                        ///< [::xetSysmanStandbyGetCount() - 1]).
        stby_properties_t* pProperties                  ///< [in] Will contain the standby hardware properties.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanStandbyGetProperties(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            stbyIndex,
            reinterpret_cast<xet_stby_properties_t*>( pProperties ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::StandbyGetProperties" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get the current standby promotion mode
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::StandbyGetMode(
        uint32_t stbyIndex,                             ///< [in] The index of the standby hardware component (0 ...
                                                        ///< [::xetSysmanStandbyGetCount() - 1]).
        stby_promo_mode_t* pMode                        ///< [in] Will contain the current standby mode.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanStandbyGetMode(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            stbyIndex,
            reinterpret_cast<xet_stby_promo_mode_t*>( pMode ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::StandbyGetMode" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Set standby promotion mode
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::StandbySetMode(
        uint32_t stbyIndex,                             ///< [in] The index of the standby hardware component (0 ...
                                                        ///< [::xetSysmanStandbyGetCount() - 1]).
        stby_promo_mode_t mode                          ///< [in] New standby mode.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanStandbySetMode(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            stbyIndex,
            static_cast<xet_stby_promo_mode_t>( mode ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::StandbySetMode" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get the number of firmwares on this device/sub-device
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::FirmwareGetCount(
        uint32_t* pCount                                ///< [in] The number of firmwares.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanFirmwareGetCount(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pCount ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::FirmwareGetCount" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get firmware properties
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::FirmwareGetProperties(
        uint32_t firmwareIndex,                         ///< [in] The index of the firmware (0 ... [::xetSysmanFirmwareGetCount() -
                                                        ///< 1]).
        firmware_properties_t* pProperties              ///< [in] Pointer to an array that will hold the properties of the firmware
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanFirmwareGetProperties(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            firmwareIndex,
            reinterpret_cast<xet_firmware_properties_t*>( pProperties ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::FirmwareGetProperties" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get firmware checksum
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::FirmwareGetChecksum(
        uint32_t firmwareIndex,                         ///< [in] The index of the firmware (0 ... [::xetSysmanFirmwareGetCount() -
                                                        ///< 1]).
        uint32_t* pChecksum                             ///< [in] Calculated checksum of the installed firmware.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanFirmwareGetChecksum(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            firmwareIndex,
            pChecksum ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::FirmwareGetChecksum" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Flash a new firmware image
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::FirmwareFlash(
        uint32_t firmwareIndex,                         ///< [in] The index of the firmware (0 ... [::xetSysmanFirmwareGetCount() -
                                                        ///< 1]).
        void* pImage,                                   ///< [in] Image of the new firmware to flash.
        uint32_t size                                   ///< [in] Size of the flash image.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanFirmwareFlash(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            firmwareIndex,
            pImage,
            size ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::FirmwareFlash" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get the number of PSU attached this device/sub-device
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::PsuGetCount(
        uint32_t* pCount                                ///< [in] The number of PSUs.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanPsuGetCount(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pCount ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::PsuGetCount" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get power supply properties
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::PsuGetProperties(
        uint32_t psuIndex,                              ///< [in] The index of the power supply (0 ... [::xetSysmanPsuGetCount() -
                                                        ///< 1]).
        psu_properties_t* pProperties                   ///< [in] Will contain the properties of the power supply.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanPsuGetProperties(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            psuIndex,
            reinterpret_cast<xet_psu_properties_t*>( pProperties ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::PsuGetProperties" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get current power supply state
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::PsuGetState(
        uint32_t psuIndex,                              ///< [in] The index of the power supply (0 ... [::xetSysmanPsuGetCount() -
                                                        ///< 1]).
        psu_state_t* pState                             ///< [in] Will contain the current state of the power supply.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanPsuGetState(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            psuIndex,
            reinterpret_cast<xet_psu_state_t*>( pState ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::PsuGetState" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get the number of fans attached this device/sub-device
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::FanGetCount(
        uint32_t* pCount                                ///< [in] The number of fans.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanFanGetCount(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pCount ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::FanGetCount" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get fan properties
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::FanGetProperties(
        uint32_t fanIndex,                              ///< [in] The index of the fan (0 ... [::xetSysmanFanGetCount() - 1]).
        fan_properties_t* pProperties                   ///< [in] Will contain the properties of the fan.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanFanGetProperties(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            fanIndex,
            reinterpret_cast<xet_fan_properties_t*>( pProperties ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::FanGetProperties" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get current fan configuration
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::FanGetConfig(
        uint32_t fanIndex,                              ///< [in] The index of the fan (0 ... [::xetSysmanFanGetCount() - 1]).
        fan_config_t* pConfig                           ///< [in] Will contain the current configuration of the fan.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanFanGetConfig(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            fanIndex,
            reinterpret_cast<xet_fan_config_t*>( pConfig ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::FanGetConfig" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Set fan configuration
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::FanSetConfig(
        uint32_t fanIndex,                              ///< [in] The index of the fan (0 ... [::xetSysmanFanGetCount() - 1]).
        const fan_config_t* pConfig                     ///< [in] New fan configuration.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanFanSetConfig(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            fanIndex,
            reinterpret_cast<const xet_fan_config_t*>( pConfig ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::FanSetConfig" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get current state of a fan - current mode and speed
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::FanGetState(
        uint32_t fanIndex,                              ///< [in] The index of the fan (0 ... [::xetSysmanFanGetCount() - 1]).
        fan_speed_units_t units,                        ///< [in] The units in which the fan speed should be returned.
        fan_state_t* pState                             ///< [in] Will contain the current state of the fan.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanFanGetState(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            fanIndex,
            static_cast<xet_fan_speed_units_t>( units ),
            reinterpret_cast<xet_fan_state_t*>( pState ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::FanGetState" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get the number of PSU attached this device/sub-device
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::LedGetCount(
        uint32_t* pCount                                ///< [in] The number of LEDs.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanLedGetCount(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pCount ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::LedGetCount" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get LED properties
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::LedGetProperties(
        uint32_t ledIndex,                              ///< [in] The index of the LED (0 ... [::xetSysmanLedGetCount() - 1]).
        led_properties_t* pProperties                   ///< [in] Will contain the properties of the LED.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanLedGetProperties(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            ledIndex,
            reinterpret_cast<xet_led_properties_t*>( pProperties ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::LedGetProperties" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get current state of a LED - on/off, color
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::LedGetState(
        uint32_t ledIndex,                              ///< [in] The index of the LED (0 ... [::xetSysmanLedGetCount() - 1]).
        led_state_t* pState                             ///< [in] Will contain the current state of the LED.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanLedGetState(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            ledIndex,
            reinterpret_cast<xet_led_state_t*>( pState ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::LedGetState" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Set state of a LED - on/off, color
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::LedSetState(
        uint32_t ledIndex,                              ///< [in] The index of the LED (0 ... [::xetSysmanLedGetCount() - 1]).
        const led_state_t* pState                       ///< [in] New state of the LED.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanLedSetState(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            ledIndex,
            reinterpret_cast<const xet_led_state_t*>( pState ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::LedSetState" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get the number of RAS error sets on this device/sub-device
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::RasGetCount(
        uint32_t* pCount                                ///< [in] The number of RAS errors sets.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanRasGetCount(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pCount ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::RasGetCount" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get RAS properties of the device
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::RasGetProperties(
        uint32_t rasIndex,                              ///< [in] The index of the RAS error set (0 ... [::xetSysmanRasGetCount() -
                                                        ///< 1]).
        ras_properties_t* pProperties                   ///< [in] Structure describing RAS properties
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanRasGetProperties(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            rasIndex,
            reinterpret_cast<xet_ras_properties_t*>( pProperties ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::RasGetProperties" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get the number of errors of a given RAS error set
    /// 
    /// @details
    ///     - Clearing errors will affect other threads/applications - the counter
    ///       values will start from zero.
    ///     - Clearing errors requires write permissions.
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::RasGetErrors(
        uint32_t rasIndex,                              ///< [in] The index of the RAS error set (0 ... [::xetSysmanRasGetCount() -
                                                        ///< 1]).
        xe::bool_t clear,                               ///< [in] Set to 1 to clear the counters of this type
        uint64_t* pTotalErrors,                         ///< [in] The number total number of errors that have occurred
        ras_details_t* pDetails                         ///< [in][optional] Breakdown of where errors have occurred
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanRasGetErrors(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            rasIndex,
            static_cast<xe_bool_t>( clear ),
            pTotalErrors,
            reinterpret_cast<xet_ras_details_t*>( pDetails ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::RasGetErrors" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get event properties
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::EventsGetProperties(
        event_properties_t* pProperties                 ///< [in] Structure describing event properties
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanEventsGetProperties(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            reinterpret_cast<xet_event_properties_t*>( pProperties ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::EventsGetProperties" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Register to receive events
    /// 
    /// @details
    ///     - This will only register the specified list of events. If other events
    ///       have been registered, notifications for them will continue.
    ///     - Set count to zero to receive notifications for all events.
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::EventsRegister(
        uint32_t count,                                 ///< [in] Number of entries in the array pEvents. If zero, all events will
                                                        ///< be registered.
        event_request_t* pEvents                        ///< [in][optional] Events to register.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanEventsRegister(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            count,
            reinterpret_cast<xet_event_request_t*>( pEvents ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::EventsRegister" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Unregister events
    /// 
    /// @details
    ///     - This will only unregister the specified list of events. If other
    ///       events have been registered, notifications for them will continue.
    ///     - Set count to zero to no longer receive any notifications.
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::EventsUnregister(
        uint32_t count,                                 ///< [in] Number of entries in the array pEvents. If zero, all events will
                                                        ///< be unregistered.
        event_request_t* pEvents                        ///< [in][optional] Events to unregister.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanEventsUnregister(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            count,
            reinterpret_cast<xet_event_request_t*>( pEvents ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::EventsUnregister" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get events that have been triggered for a specific device or from all
    ///        registered devices
    /// 
    /// @details
    ///     - If events have occurred, they are returned and the corresponding event
    ///       status is cleared if the argument clear = true.
    ///     - If listening to events from multiple devices, it is recommended to
    ///       call this function with hSysman = nullptr, clear = false and timeout =
    ///       ::XET_EVENT_WAIT_INFINITE. Then call this function for each device
    ///       with clear = true and timeout = 0.
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::EventsListen(
        Sysman* pSysman,                                ///< [in] SMI handle for a device. Set to nullptr to get events from any
                                                        ///< device for which the application has registered to receive
                                                        ///< notifications.
        xe::bool_t clear,                               ///< [in] Clear the event status.
        uint32_t timeout,                               ///< [in] How long to wait in milliseconds for events to arrive. Zero will
                                                        ///< check status and return immediately. Set to ::XET_EVENT_WAIT_INFINITE
                                                        ///< to block until events arrive.
        uint32_t* pEvents                               ///< [in] Bitfield of events (1<<::xet_sysman_event_type_t) that have been
                                                        ///< triggered.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanEventsListen(
            reinterpret_cast<xet_sysman_handle_t>( pSysman->getHandle() ),
            static_cast<xe_bool_t>( clear ),
            timeout,
            pEvents ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::EventsListen" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get the number of diagnostic test suites that can be run on this
    ///        device/sub-device
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::DiagnosticsGetCount(
        uint32_t* pCount                                ///< [in] The number of diagnostic test suites.
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanDiagnosticsGetCount(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            pCount ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::DiagnosticsGetCount" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Get properties of a diagnostics test suite
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::DiagnosticsGetProperties(
        uint32_t testIndex,                             ///< [in] The index of a diagnostics test (0 ...
                                                        ///< [::xetSysmanDiagnosticsGetCount() - 1]).
        diag_properties_t* pProperties                  ///< [in] Structure describing the properties of a diagnostics test suite
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanDiagnosticsGetProperties(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            testIndex,
            reinterpret_cast<xet_diag_properties_t*>( pProperties ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::DiagnosticsGetProperties" );
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Run a diagnostics test suite, either all tests or a subset of tests.
    /// 
    /// @details
    ///     - This function will block until the diagnostics have completed.
    /// 
    /// @throws result_t
    void __xecall
    Sysman::DiagnosticsRunTests(
        uint32_t testIndex,                             ///< [in] The index of a diagnostics test (0 ...
                                                        ///< [::xetSysmanDiagnosticsGetCount() - 1]).
        uint32_t start,                                 ///< [in] The index of the first test to run. Set to
                                                        ///< ::XET_DIAG_FIRST_TEST_INDEX to start from the beginning.
        uint32_t end,                                   ///< [in] The index of the last test to run. Set to
                                                        ///< ::XET_DIAG_LAST_TEST_INDEX to complete all tests after the start test.
        diag_result_t* pResult                          ///< [in] The result of the diagnostics
        )
    {
        auto result = static_cast<result_t>( ::xetSysmanDiagnosticsRunTests(
            reinterpret_cast<xet_sysman_handle_t>( getHandle() ),
            testIndex,
            start,
            end,
            reinterpret_cast<xet_diag_result_t*>( pResult ) ) );

        if( result_t::SUCCESS != result )
            throw exception_t( result, __FILE__, STRING(__LINE__), "xet::Sysman::DiagnosticsRunTests" );
    }

} // namespace xet

namespace xet
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::version_t to std::string
    std::string to_string( const Sysman::version_t val )
    {
        std::string str;

        switch( val )
        {
        case Sysman::version_t::CURRENT:
            str = "Sysman::version_t::CURRENT";
            break;

        default:
            str = "Sysman::version_t::?";
            break;
        };

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::optimization_mode_t to std::string
    std::string to_string( const Sysman::optimization_mode_t val )
    {
        std::string str;

        switch( val )
        {
        case Sysman::optimization_mode_t::DEFAULT:
            str = "Sysman::optimization_mode_t::DEFAULT";
            break;

        case Sysman::optimization_mode_t::SINGLE_PROCESS_COMPUTE:
            str = "Sysman::optimization_mode_t::SINGLE_PROCESS_COMPUTE";
            break;

        default:
            str = "Sysman::optimization_mode_t::?";
            break;
        };

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::power_domain_t to std::string
    std::string to_string( const Sysman::power_domain_t val )
    {
        std::string str;

        switch( val )
        {
        case Sysman::power_domain_t::PWR_DOMAIN_TOTAL:
            str = "Sysman::power_domain_t::PWR_DOMAIN_TOTAL";
            break;

        default:
            str = "Sysman::power_domain_t::?";
            break;
        };

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::freq_domain_t to std::string
    std::string to_string( const Sysman::freq_domain_t val )
    {
        std::string str;

        switch( val )
        {
        case Sysman::freq_domain_t::GPU:
            str = "Sysman::freq_domain_t::GPU";
            break;

        case Sysman::freq_domain_t::MEMORY:
            str = "Sysman::freq_domain_t::MEMORY";
            break;

        default:
            str = "Sysman::freq_domain_t::?";
            break;
        };

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::freq_throttle_reasons_t to std::string
    std::string to_string( const Sysman::freq_throttle_reasons_t val )
    {
        const auto bits = static_cast<uint32_t>( val );

        std::string str;
        
        if( 0 == bits )
            str += "NONE   ";
        
        if( static_cast<uint32_t>(Sysman::freq_throttle_reasons_t::AVE_PWR_CAP) & bits )
            str += "AVE_PWR_CAP | ";
        
        if( static_cast<uint32_t>(Sysman::freq_throttle_reasons_t::BURST_PWR_CAP) & bits )
            str += "BURST_PWR_CAP | ";
        
        if( static_cast<uint32_t>(Sysman::freq_throttle_reasons_t::CURRENT_LIMIT) & bits )
            str += "CURRENT_LIMIT | ";
        
        if( static_cast<uint32_t>(Sysman::freq_throttle_reasons_t::THERMAL_LIMIT) & bits )
            str += "THERMAL_LIMIT | ";
        
        if( static_cast<uint32_t>(Sysman::freq_throttle_reasons_t::PSU_ALERT) & bits )
            str += "PSU_ALERT | ";
        
        if( static_cast<uint32_t>(Sysman::freq_throttle_reasons_t::SW_RANGE) & bits )
            str += "SW_RANGE | ";
        
        if( static_cast<uint32_t>(Sysman::freq_throttle_reasons_t::HW_RANGE) & bits )
            str += "HW_RANGE | ";

        return ( str.size() > 3 ) 
            ? "Sysman::freq_throttle_reasons_t::{ " + str.substr(0, str.size() - 3) + " }"
            : "Sysman::freq_throttle_reasons_t::{ ? }";
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::activity_type_t to std::string
    std::string to_string( const Sysman::activity_type_t val )
    {
        std::string str;

        switch( val )
        {
        case Sysman::activity_type_t::GLOBAL:
            str = "Sysman::activity_type_t::GLOBAL";
            break;

        case Sysman::activity_type_t::COMPUTE:
            str = "Sysman::activity_type_t::COMPUTE";
            break;

        case Sysman::activity_type_t::MEDIA:
            str = "Sysman::activity_type_t::MEDIA";
            break;

        default:
            str = "Sysman::activity_type_t::?";
            break;
        };

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::mem_type_t to std::string
    std::string to_string( const Sysman::mem_type_t val )
    {
        std::string str;

        switch( val )
        {
        case Sysman::mem_type_t::HBM:
            str = "Sysman::mem_type_t::HBM";
            break;

        case Sysman::mem_type_t::DDR:
            str = "Sysman::mem_type_t::DDR";
            break;

        case Sysman::mem_type_t::SRAM:
            str = "Sysman::mem_type_t::SRAM";
            break;

        case Sysman::mem_type_t::L1:
            str = "Sysman::mem_type_t::L1";
            break;

        case Sysman::mem_type_t::L3:
            str = "Sysman::mem_type_t::L3";
            break;

        case Sysman::mem_type_t::GRF:
            str = "Sysman::mem_type_t::GRF";
            break;

        case Sysman::mem_type_t::SLM:
            str = "Sysman::mem_type_t::SLM";
            break;

        default:
            str = "Sysman::mem_type_t::?";
            break;
        };

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::pci_bar_type_t to std::string
    std::string to_string( const Sysman::pci_bar_type_t val )
    {
        std::string str;

        switch( val )
        {
        case Sysman::pci_bar_type_t::CONFIG:
            str = "Sysman::pci_bar_type_t::CONFIG";
            break;

        case Sysman::pci_bar_type_t::MMIO:
            str = "Sysman::pci_bar_type_t::MMIO";
            break;

        case Sysman::pci_bar_type_t::VRAM:
            str = "Sysman::pci_bar_type_t::VRAM";
            break;

        case Sysman::pci_bar_type_t::ROM:
            str = "Sysman::pci_bar_type_t::ROM";
            break;

        case Sysman::pci_bar_type_t::VGA_IO:
            str = "Sysman::pci_bar_type_t::VGA_IO";
            break;

        case Sysman::pci_bar_type_t::VGA_MEM:
            str = "Sysman::pci_bar_type_t::VGA_MEM";
            break;

        case Sysman::pci_bar_type_t::INDIRECT_IO:
            str = "Sysman::pci_bar_type_t::INDIRECT_IO";
            break;

        case Sysman::pci_bar_type_t::INDIRECT_MEM:
            str = "Sysman::pci_bar_type_t::INDIRECT_MEM";
            break;

        case Sysman::pci_bar_type_t::OTHER:
            str = "Sysman::pci_bar_type_t::OTHER";
            break;

        default:
            str = "Sysman::pci_bar_type_t::?";
            break;
        };

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::temp_sensors_t to std::string
    std::string to_string( const Sysman::temp_sensors_t val )
    {
        std::string str;

        switch( val )
        {
        case Sysman::temp_sensors_t::GLOBAL:
            str = "Sysman::temp_sensors_t::GLOBAL";
            break;

        case Sysman::temp_sensors_t::GPU:
            str = "Sysman::temp_sensors_t::GPU";
            break;

        case Sysman::temp_sensors_t::MEMORY:
            str = "Sysman::temp_sensors_t::MEMORY";
            break;

        default:
            str = "Sysman::temp_sensors_t::?";
            break;
        };

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::stby_type_t to std::string
    std::string to_string( const Sysman::stby_type_t val )
    {
        std::string str;

        switch( val )
        {
        case Sysman::stby_type_t::GLOBAL:
            str = "Sysman::stby_type_t::GLOBAL";
            break;

        default:
            str = "Sysman::stby_type_t::?";
            break;
        };

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::stby_promo_mode_t to std::string
    std::string to_string( const Sysman::stby_promo_mode_t val )
    {
        std::string str;

        switch( val )
        {
        case Sysman::stby_promo_mode_t::DEFAULT:
            str = "Sysman::stby_promo_mode_t::DEFAULT";
            break;

        case Sysman::stby_promo_mode_t::NEVER:
            str = "Sysman::stby_promo_mode_t::NEVER";
            break;

        default:
            str = "Sysman::stby_promo_mode_t::?";
            break;
        };

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::psu_voltage_status_t to std::string
    std::string to_string( const Sysman::psu_voltage_status_t val )
    {
        std::string str;

        switch( val )
        {
        case Sysman::psu_voltage_status_t::NORMAL:
            str = "Sysman::psu_voltage_status_t::NORMAL";
            break;

        case Sysman::psu_voltage_status_t::OVER:
            str = "Sysman::psu_voltage_status_t::OVER";
            break;

        case Sysman::psu_voltage_status_t::UNDER:
            str = "Sysman::psu_voltage_status_t::UNDER";
            break;

        default:
            str = "Sysman::psu_voltage_status_t::?";
            break;
        };

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::fan_speed_mode_t to std::string
    std::string to_string( const Sysman::fan_speed_mode_t val )
    {
        std::string str;

        switch( val )
        {
        case Sysman::fan_speed_mode_t::DEFAULT:
            str = "Sysman::fan_speed_mode_t::DEFAULT";
            break;

        case Sysman::fan_speed_mode_t::FIXED:
            str = "Sysman::fan_speed_mode_t::FIXED";
            break;

        case Sysman::fan_speed_mode_t::TABLE:
            str = "Sysman::fan_speed_mode_t::TABLE";
            break;

        default:
            str = "Sysman::fan_speed_mode_t::?";
            break;
        };

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::fan_speed_units_t to std::string
    std::string to_string( const Sysman::fan_speed_units_t val )
    {
        std::string str;

        switch( val )
        {
        case Sysman::fan_speed_units_t::RPM:
            str = "Sysman::fan_speed_units_t::RPM";
            break;

        case Sysman::fan_speed_units_t::PERCENT:
            str = "Sysman::fan_speed_units_t::PERCENT";
            break;

        default:
            str = "Sysman::fan_speed_units_t::?";
            break;
        };

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::ras_error_type_t to std::string
    std::string to_string( const Sysman::ras_error_type_t val )
    {
        std::string str;

        switch( val )
        {
        case Sysman::ras_error_type_t::CORRECTABLE:
            str = "Sysman::ras_error_type_t::CORRECTABLE";
            break;

        case Sysman::ras_error_type_t::UNCORRECTABLE:
            str = "Sysman::ras_error_type_t::UNCORRECTABLE";
            break;

        default:
            str = "Sysman::ras_error_type_t::?";
            break;
        };

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::event_type_t to std::string
    std::string to_string( const Sysman::event_type_t val )
    {
        std::string str;

        switch( val )
        {
        case Sysman::event_type_t::FREQ_THROTTLED:
            str = "Sysman::event_type_t::FREQ_THROTTLED";
            break;

        case Sysman::event_type_t::ENERGY_THRESHOLD_CROSSED:
            str = "Sysman::event_type_t::ENERGY_THRESHOLD_CROSSED";
            break;

        case Sysman::event_type_t::RAS_ERRORS:
            str = "Sysman::event_type_t::RAS_ERRORS";
            break;

        case Sysman::event_type_t::NUM:
            str = "Sysman::event_type_t::NUM";
            break;

        default:
            str = "Sysman::event_type_t::?";
            break;
        };

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::diag_type_t to std::string
    std::string to_string( const Sysman::diag_type_t val )
    {
        std::string str;

        switch( val )
        {
        case Sysman::diag_type_t::SCAN:
            str = "Sysman::diag_type_t::SCAN";
            break;

        case Sysman::diag_type_t::ARRAY:
            str = "Sysman::diag_type_t::ARRAY";
            break;

        default:
            str = "Sysman::diag_type_t::?";
            break;
        };

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::diag_result_t to std::string
    std::string to_string( const Sysman::diag_result_t val )
    {
        std::string str;

        switch( val )
        {
        case Sysman::diag_result_t::NO_ERRORS:
            str = "Sysman::diag_result_t::NO_ERRORS";
            break;

        case Sysman::diag_result_t::ABORT:
            str = "Sysman::diag_result_t::ABORT";
            break;

        case Sysman::diag_result_t::FAIL_CANT_REPAIR:
            str = "Sysman::diag_result_t::FAIL_CANT_REPAIR";
            break;

        case Sysman::diag_result_t::REBOOT_FOR_REPAIR:
            str = "Sysman::diag_result_t::REBOOT_FOR_REPAIR";
            break;

        default:
            str = "Sysman::diag_result_t::?";
            break;
        };

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::properties_t to std::string
    std::string to_string( const Sysman::properties_t val )
    {
        std::string str;
        
        str += "Sysman::properties_t::type : ";
        str += to_string(val.type);
        str += "\n";
        
        str += "Sysman::properties_t::vendorId : ";
        str += std::to_string(val.vendorId);
        str += "\n";
        
        str += "Sysman::properties_t::deviceId : ";
        str += std::to_string(val.deviceId);
        str += "\n";
        
        str += "Sysman::properties_t::uuid : ";
        str += to_string(val.uuid);
        str += "\n";
        
        str += "Sysman::properties_t::numSubdevices : ";
        str += std::to_string(val.numSubdevices);
        str += "\n";
        
        str += "Sysman::properties_t::isSubdevice : ";
        str += std::to_string(val.isSubdevice);
        str += "\n";
        
        str += "Sysman::properties_t::subdeviceId : ";
        str += std::to_string(val.subdeviceId);
        str += "\n";
        
        str += "Sysman::properties_t::serialNumber : ";
        {
            std::string tmp;
            for( auto& entry : val.serialNumber )
            {
                tmp += std::to_string( entry );
                tmp += ", ";
            }
            str += "[ " + tmp.substr( 0, tmp.size() - 2 ) + " ]";;
        }
        str += "\n";
        
        str += "Sysman::properties_t::boardNumber : ";
        {
            std::string tmp;
            for( auto& entry : val.boardNumber )
            {
                tmp += std::to_string( entry );
                tmp += ", ";
            }
            str += "[ " + tmp.substr( 0, tmp.size() - 2 ) + " ]";;
        }
        str += "\n";
        
        str += "Sysman::properties_t::brandName : ";
        {
            std::string tmp;
            for( auto& entry : val.brandName )
            {
                tmp += std::to_string( entry );
                tmp += ", ";
            }
            str += "[ " + tmp.substr( 0, tmp.size() - 2 ) + " ]";;
        }
        str += "\n";
        
        str += "Sysman::properties_t::modelName : ";
        {
            std::string tmp;
            for( auto& entry : val.modelName )
            {
                tmp += std::to_string( entry );
                tmp += ", ";
            }
            str += "[ " + tmp.substr( 0, tmp.size() - 2 ) + " ]";;
        }
        str += "\n";
        
        str += "Sysman::properties_t::vendorName : ";
        {
            std::string tmp;
            for( auto& entry : val.vendorName )
            {
                tmp += std::to_string( entry );
                tmp += ", ";
            }
            str += "[ " + tmp.substr( 0, tmp.size() - 2 ) + " ]";;
        }
        str += "\n";
        
        str += "Sysman::properties_t::driverVersion : ";
        {
            std::string tmp;
            for( auto& entry : val.driverVersion )
            {
                tmp += std::to_string( entry );
                tmp += ", ";
            }
            str += "[ " + tmp.substr( 0, tmp.size() - 2 ) + " ]";;
        }
        str += "\n";
        
        str += "Sysman::properties_t::wasRepaired : ";
        str += std::to_string(val.wasRepaired);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::power_properties_t to std::string
    std::string to_string( const Sysman::power_properties_t val )
    {
        std::string str;
        
        str += "Sysman::power_properties_t::type : ";
        str += to_string(val.type);
        str += "\n";
        
        str += "Sysman::power_properties_t::onSubdevice : ";
        str += std::to_string(val.onSubdevice);
        str += "\n";
        
        str += "Sysman::power_properties_t::subdeviceUuid : ";
        str += to_string(val.subdeviceUuid);
        str += "\n";
        
        str += "Sysman::power_properties_t::canControl : ";
        str += std::to_string(val.canControl);
        str += "\n";
        
        str += "Sysman::power_properties_t::maxLimit : ";
        str += std::to_string(val.maxLimit);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::power_energy_counter_t to std::string
    std::string to_string( const Sysman::power_energy_counter_t val )
    {
        std::string str;
        
        str += "Sysman::power_energy_counter_t::energy : ";
        str += std::to_string(val.energy);
        str += "\n";
        
        str += "Sysman::power_energy_counter_t::timestamp : ";
        str += std::to_string(val.timestamp);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::power_energy_threshold_t to std::string
    std::string to_string( const Sysman::power_energy_threshold_t val )
    {
        std::string str;
        
        str += "Sysman::power_energy_threshold_t::energy : ";
        str += std::to_string(val.energy);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::power_sustained_limit_t to std::string
    std::string to_string( const Sysman::power_sustained_limit_t val )
    {
        std::string str;
        
        str += "Sysman::power_sustained_limit_t::enabled : ";
        str += std::to_string(val.enabled);
        str += "\n";
        
        str += "Sysman::power_sustained_limit_t::power : ";
        str += std::to_string(val.power);
        str += "\n";
        
        str += "Sysman::power_sustained_limit_t::interval : ";
        str += std::to_string(val.interval);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::power_burst_limit_t to std::string
    std::string to_string( const Sysman::power_burst_limit_t val )
    {
        std::string str;
        
        str += "Sysman::power_burst_limit_t::enabled : ";
        str += std::to_string(val.enabled);
        str += "\n";
        
        str += "Sysman::power_burst_limit_t::power : ";
        str += std::to_string(val.power);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::power_peak_limit_t to std::string
    std::string to_string( const Sysman::power_peak_limit_t val )
    {
        std::string str;
        
        str += "Sysman::power_peak_limit_t::power : ";
        str += std::to_string(val.power);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::freq_properties_t to std::string
    std::string to_string( const Sysman::freq_properties_t val )
    {
        std::string str;
        
        str += "Sysman::freq_properties_t::type : ";
        str += to_string(val.type);
        str += "\n";
        
        str += "Sysman::freq_properties_t::onSubdevice : ";
        str += std::to_string(val.onSubdevice);
        str += "\n";
        
        str += "Sysman::freq_properties_t::subdeviceUuid : ";
        str += to_string(val.subdeviceUuid);
        str += "\n";
        
        str += "Sysman::freq_properties_t::canControl : ";
        str += std::to_string(val.canControl);
        str += "\n";
        
        str += "Sysman::freq_properties_t::canOverclock : ";
        str += std::to_string(val.canOverclock);
        str += "\n";
        
        str += "Sysman::freq_properties_t::min : ";
        str += std::to_string(val.min);
        str += "\n";
        
        str += "Sysman::freq_properties_t::max : ";
        str += std::to_string(val.max);
        str += "\n";
        
        str += "Sysman::freq_properties_t::step : ";
        str += std::to_string(val.step);
        str += "\n";
        
        str += "Sysman::freq_properties_t::num : ";
        str += std::to_string(val.num);
        str += "\n";
        
        str += "Sysman::freq_properties_t::pClocks : ";
        {
            std::stringstream ss;
            ss << "0x" << std::hex << reinterpret_cast<size_t>(val.pClocks);
            str += ss.str();
        }
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::freq_range_t to std::string
    std::string to_string( const Sysman::freq_range_t val )
    {
        std::string str;
        
        str += "Sysman::freq_range_t::min : ";
        str += std::to_string(val.min);
        str += "\n";
        
        str += "Sysman::freq_range_t::max : ";
        str += std::to_string(val.max);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::freq_state_t to std::string
    std::string to_string( const Sysman::freq_state_t val )
    {
        std::string str;
        
        str += "Sysman::freq_state_t::request : ";
        str += std::to_string(val.request);
        str += "\n";
        
        str += "Sysman::freq_state_t::tdp : ";
        str += std::to_string(val.tdp);
        str += "\n";
        
        str += "Sysman::freq_state_t::efficient : ";
        str += std::to_string(val.efficient);
        str += "\n";
        
        str += "Sysman::freq_state_t::actual : ";
        str += std::to_string(val.actual);
        str += "\n";
        
        str += "Sysman::freq_state_t::throttleReasons : ";
        str += std::to_string(val.throttleReasons);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::freq_throttle_time_t to std::string
    std::string to_string( const Sysman::freq_throttle_time_t val )
    {
        std::string str;
        
        str += "Sysman::freq_throttle_time_t::throttleTime : ";
        str += std::to_string(val.throttleTime);
        str += "\n";
        
        str += "Sysman::freq_throttle_time_t::timestamp : ";
        str += std::to_string(val.timestamp);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::activity_properties_t to std::string
    std::string to_string( const Sysman::activity_properties_t val )
    {
        std::string str;
        
        str += "Sysman::activity_properties_t::type : ";
        str += to_string(val.type);
        str += "\n";
        
        str += "Sysman::activity_properties_t::onSubdevice : ";
        str += std::to_string(val.onSubdevice);
        str += "\n";
        
        str += "Sysman::activity_properties_t::subdeviceUuid : ";
        str += to_string(val.subdeviceUuid);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::activity_stats_t to std::string
    std::string to_string( const Sysman::activity_stats_t val )
    {
        std::string str;
        
        str += "Sysman::activity_stats_t::activeTime : ";
        str += std::to_string(val.activeTime);
        str += "\n";
        
        str += "Sysman::activity_stats_t::timestamp : ";
        str += std::to_string(val.timestamp);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::mem_properties_t to std::string
    std::string to_string( const Sysman::mem_properties_t val )
    {
        std::string str;
        
        str += "Sysman::mem_properties_t::type : ";
        str += to_string(val.type);
        str += "\n";
        
        str += "Sysman::mem_properties_t::onSubdevice : ";
        str += std::to_string(val.onSubdevice);
        str += "\n";
        
        str += "Sysman::mem_properties_t::subdeviceUuid : ";
        str += to_string(val.subdeviceUuid);
        str += "\n";
        
        str += "Sysman::mem_properties_t::size : ";
        str += std::to_string(val.size);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::mem_bandwidth_t to std::string
    std::string to_string( const Sysman::mem_bandwidth_t val )
    {
        std::string str;
        
        str += "Sysman::mem_bandwidth_t::readCounter : ";
        str += std::to_string(val.readCounter);
        str += "\n";
        
        str += "Sysman::mem_bandwidth_t::writeCounter : ";
        str += std::to_string(val.writeCounter);
        str += "\n";
        
        str += "Sysman::mem_bandwidth_t::maxBandwidth : ";
        str += std::to_string(val.maxBandwidth);
        str += "\n";
        
        str += "Sysman::mem_bandwidth_t::timestamp : ";
        str += std::to_string(val.timestamp);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::mem_alloc_t to std::string
    std::string to_string( const Sysman::mem_alloc_t val )
    {
        std::string str;
        
        str += "Sysman::mem_alloc_t::allocated : ";
        str += std::to_string(val.allocated);
        str += "\n";
        
        str += "Sysman::mem_alloc_t::total : ";
        str += std::to_string(val.total);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::pci_address_t to std::string
    std::string to_string( const Sysman::pci_address_t val )
    {
        std::string str;
        
        str += "Sysman::pci_address_t::domain : ";
        str += std::to_string(val.domain);
        str += "\n";
        
        str += "Sysman::pci_address_t::bus : ";
        str += std::to_string(val.bus);
        str += "\n";
        
        str += "Sysman::pci_address_t::device : ";
        str += std::to_string(val.device);
        str += "\n";
        
        str += "Sysman::pci_address_t::function : ";
        str += std::to_string(val.function);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::pci_speed_t to std::string
    std::string to_string( const Sysman::pci_speed_t val )
    {
        std::string str;
        
        str += "Sysman::pci_speed_t::gen : ";
        str += std::to_string(val.gen);
        str += "\n";
        
        str += "Sysman::pci_speed_t::width : ";
        str += std::to_string(val.width);
        str += "\n";
        
        str += "Sysman::pci_speed_t::maxBandwidth : ";
        str += std::to_string(val.maxBandwidth);
        str += "\n";
        
        str += "Sysman::pci_speed_t::maxPacketSize : ";
        str += std::to_string(val.maxPacketSize);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::pci_properties_t to std::string
    std::string to_string( const Sysman::pci_properties_t val )
    {
        std::string str;
        
        str += "Sysman::pci_properties_t::address : ";
        str += to_string(val.address);
        str += "\n";
        
        str += "Sysman::pci_properties_t::onSubdevice : ";
        str += std::to_string(val.onSubdevice);
        str += "\n";
        
        str += "Sysman::pci_properties_t::subdeviceUuid : ";
        str += to_string(val.subdeviceUuid);
        str += "\n";
        
        str += "Sysman::pci_properties_t::numBars : ";
        str += std::to_string(val.numBars);
        str += "\n";
        
        str += "Sysman::pci_properties_t::maxSpeed : ";
        str += to_string(val.maxSpeed);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::pci_state_t to std::string
    std::string to_string( const Sysman::pci_state_t val )
    {
        std::string str;
        
        str += "Sysman::pci_state_t::speed : ";
        str += to_string(val.speed);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::pci_bar_properties_t to std::string
    std::string to_string( const Sysman::pci_bar_properties_t val )
    {
        std::string str;
        
        str += "Sysman::pci_bar_properties_t::type : ";
        str += to_string(val.type);
        str += "\n";
        
        str += "Sysman::pci_bar_properties_t::base : ";
        str += std::to_string(val.base);
        str += "\n";
        
        str += "Sysman::pci_bar_properties_t::size : ";
        str += std::to_string(val.size);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::pci_throughput_t to std::string
    std::string to_string( const Sysman::pci_throughput_t val )
    {
        std::string str;
        
        str += "Sysman::pci_throughput_t::timestamp : ";
        str += std::to_string(val.timestamp);
        str += "\n";
        
        str += "Sysman::pci_throughput_t::rxCounter : ";
        str += std::to_string(val.rxCounter);
        str += "\n";
        
        str += "Sysman::pci_throughput_t::txCounter : ";
        str += std::to_string(val.txCounter);
        str += "\n";
        
        str += "Sysman::pci_throughput_t::maxBandwidth : ";
        str += std::to_string(val.maxBandwidth);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::pci_stats_t to std::string
    std::string to_string( const Sysman::pci_stats_t val )
    {
        std::string str;
        
        str += "Sysman::pci_stats_t::timestamp : ";
        str += std::to_string(val.timestamp);
        str += "\n";
        
        str += "Sysman::pci_stats_t::replayCounter : ";
        str += std::to_string(val.replayCounter);
        str += "\n";
        
        str += "Sysman::pci_stats_t::packetCounter : ";
        str += std::to_string(val.packetCounter);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::switch_properties_t to std::string
    std::string to_string( const Sysman::switch_properties_t val )
    {
        std::string str;
        
        str += "Sysman::switch_properties_t::numPorts : ";
        str += std::to_string(val.numPorts);
        str += "\n";
        
        str += "Sysman::switch_properties_t::onSubdevice : ";
        str += std::to_string(val.onSubdevice);
        str += "\n";
        
        str += "Sysman::switch_properties_t::subdeviceUuid : ";
        str += to_string(val.subdeviceUuid);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::switch_state_t to std::string
    std::string to_string( const Sysman::switch_state_t val )
    {
        std::string str;
        
        str += "Sysman::switch_state_t::enabled : ";
        str += std::to_string(val.enabled);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::switch_port_speed_t to std::string
    std::string to_string( const Sysman::switch_port_speed_t val )
    {
        std::string str;
        
        str += "Sysman::switch_port_speed_t::bitRate : ";
        str += std::to_string(val.bitRate);
        str += "\n";
        
        str += "Sysman::switch_port_speed_t::width : ";
        str += std::to_string(val.width);
        str += "\n";
        
        str += "Sysman::switch_port_speed_t::maxBandwidth : ";
        str += std::to_string(val.maxBandwidth);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::switch_port_properties_t to std::string
    std::string to_string( const Sysman::switch_port_properties_t val )
    {
        std::string str;
        
        str += "Sysman::switch_port_properties_t::maxSpeed : ";
        str += to_string(val.maxSpeed);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::switch_port_state_t to std::string
    std::string to_string( const Sysman::switch_port_state_t val )
    {
        std::string str;
        
        str += "Sysman::switch_port_state_t::isConnected : ";
        str += std::to_string(val.isConnected);
        str += "\n";
        
        str += "Sysman::switch_port_state_t::remoteDeviceUuid : ";
        str += to_string(val.remoteDeviceUuid);
        str += "\n";
        
        str += "Sysman::switch_port_state_t::remoteDeviceSwitchIndex : ";
        str += std::to_string(val.remoteDeviceSwitchIndex);
        str += "\n";
        
        str += "Sysman::switch_port_state_t::remoteSwitchPortIndex : ";
        str += std::to_string(val.remoteSwitchPortIndex);
        str += "\n";
        
        str += "Sysman::switch_port_state_t::rxSpeed : ";
        str += to_string(val.rxSpeed);
        str += "\n";
        
        str += "Sysman::switch_port_state_t::txSpeed : ";
        str += to_string(val.txSpeed);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::switch_port_throughput_t to std::string
    std::string to_string( const Sysman::switch_port_throughput_t val )
    {
        std::string str;
        
        str += "Sysman::switch_port_throughput_t::timestamp : ";
        str += std::to_string(val.timestamp);
        str += "\n";
        
        str += "Sysman::switch_port_throughput_t::rxCounter : ";
        str += std::to_string(val.rxCounter);
        str += "\n";
        
        str += "Sysman::switch_port_throughput_t::txCounter : ";
        str += std::to_string(val.txCounter);
        str += "\n";
        
        str += "Sysman::switch_port_throughput_t::rxMaxBandwidth : ";
        str += std::to_string(val.rxMaxBandwidth);
        str += "\n";
        
        str += "Sysman::switch_port_throughput_t::txMaxBandwidth : ";
        str += std::to_string(val.txMaxBandwidth);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::switch_port_stats_t to std::string
    std::string to_string( const Sysman::switch_port_stats_t val )
    {
        std::string str;
        
        str += "Sysman::switch_port_stats_t::timestamp : ";
        str += std::to_string(val.timestamp);
        str += "\n";
        
        str += "Sysman::switch_port_stats_t::replayCounter : ";
        str += std::to_string(val.replayCounter);
        str += "\n";
        
        str += "Sysman::switch_port_stats_t::packetCounter : ";
        str += std::to_string(val.packetCounter);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::temp_properties_t to std::string
    std::string to_string( const Sysman::temp_properties_t val )
    {
        std::string str;
        
        str += "Sysman::temp_properties_t::type : ";
        str += to_string(val.type);
        str += "\n";
        
        str += "Sysman::temp_properties_t::onSubdevice : ";
        str += std::to_string(val.onSubdevice);
        str += "\n";
        
        str += "Sysman::temp_properties_t::subdeviceUuid : ";
        str += to_string(val.subdeviceUuid);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::stby_properties_t to std::string
    std::string to_string( const Sysman::stby_properties_t val )
    {
        std::string str;
        
        str += "Sysman::stby_properties_t::type : ";
        str += to_string(val.type);
        str += "\n";
        
        str += "Sysman::stby_properties_t::onSubdevice : ";
        str += std::to_string(val.onSubdevice);
        str += "\n";
        
        str += "Sysman::stby_properties_t::subdeviceUuid : ";
        str += to_string(val.subdeviceUuid);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::firmware_properties_t to std::string
    std::string to_string( const Sysman::firmware_properties_t val )
    {
        std::string str;
        
        str += "Sysman::firmware_properties_t::onSubdevice : ";
        str += std::to_string(val.onSubdevice);
        str += "\n";
        
        str += "Sysman::firmware_properties_t::subdeviceUuid : ";
        str += to_string(val.subdeviceUuid);
        str += "\n";
        
        str += "Sysman::firmware_properties_t::canControl : ";
        str += std::to_string(val.canControl);
        str += "\n";
        
        str += "Sysman::firmware_properties_t::name : ";
        {
            std::string tmp;
            for( auto& entry : val.name )
            {
                tmp += std::to_string( entry );
                tmp += ", ";
            }
            str += "[ " + tmp.substr( 0, tmp.size() - 2 ) + " ]";;
        }
        str += "\n";
        
        str += "Sysman::firmware_properties_t::version : ";
        {
            std::string tmp;
            for( auto& entry : val.version )
            {
                tmp += std::to_string( entry );
                tmp += ", ";
            }
            str += "[ " + tmp.substr( 0, tmp.size() - 2 ) + " ]";;
        }
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::psu_properties_t to std::string
    std::string to_string( const Sysman::psu_properties_t val )
    {
        std::string str;
        
        str += "Sysman::psu_properties_t::onSubdevice : ";
        str += std::to_string(val.onSubdevice);
        str += "\n";
        
        str += "Sysman::psu_properties_t::subdeviceUuid : ";
        str += to_string(val.subdeviceUuid);
        str += "\n";
        
        str += "Sysman::psu_properties_t::canControl : ";
        str += std::to_string(val.canControl);
        str += "\n";
        
        str += "Sysman::psu_properties_t::haveFan : ";
        str += std::to_string(val.haveFan);
        str += "\n";
        
        str += "Sysman::psu_properties_t::ampLimit : ";
        str += std::to_string(val.ampLimit);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::psu_state_t to std::string
    std::string to_string( const Sysman::psu_state_t val )
    {
        std::string str;
        
        str += "Sysman::psu_state_t::voltStatus : ";
        str += to_string(val.voltStatus);
        str += "\n";
        
        str += "Sysman::psu_state_t::fanFailed : ";
        str += std::to_string(val.fanFailed);
        str += "\n";
        
        str += "Sysman::psu_state_t::temperature : ";
        str += std::to_string(val.temperature);
        str += "\n";
        
        str += "Sysman::psu_state_t::current : ";
        str += std::to_string(val.current);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::fan_temp_speed_t to std::string
    std::string to_string( const Sysman::fan_temp_speed_t val )
    {
        std::string str;
        
        str += "Sysman::fan_temp_speed_t::temperature : ";
        str += std::to_string(val.temperature);
        str += "\n";
        
        str += "Sysman::fan_temp_speed_t::speed : ";
        str += std::to_string(val.speed);
        str += "\n";
        
        str += "Sysman::fan_temp_speed_t::units : ";
        str += to_string(val.units);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::fan_properties_t to std::string
    std::string to_string( const Sysman::fan_properties_t val )
    {
        std::string str;
        
        str += "Sysman::fan_properties_t::onSubdevice : ";
        str += std::to_string(val.onSubdevice);
        str += "\n";
        
        str += "Sysman::fan_properties_t::subdeviceUuid : ";
        str += to_string(val.subdeviceUuid);
        str += "\n";
        
        str += "Sysman::fan_properties_t::canControl : ";
        str += std::to_string(val.canControl);
        str += "\n";
        
        str += "Sysman::fan_properties_t::maxSpeed : ";
        str += std::to_string(val.maxSpeed);
        str += "\n";
        
        str += "Sysman::fan_properties_t::maxPoints : ";
        str += std::to_string(val.maxPoints);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::fan_config_t to std::string
    std::string to_string( const Sysman::fan_config_t val )
    {
        std::string str;
        
        str += "Sysman::fan_config_t::mode : ";
        str += to_string(val.mode);
        str += "\n";
        
        str += "Sysman::fan_config_t::speed : ";
        str += std::to_string(val.speed);
        str += "\n";
        
        str += "Sysman::fan_config_t::speedUnits : ";
        str += to_string(val.speedUnits);
        str += "\n";
        
        str += "Sysman::fan_config_t::numPoints : ";
        str += std::to_string(val.numPoints);
        str += "\n";
        
        str += "Sysman::fan_config_t::table : ";
        {
            std::string tmp;
            for( auto& entry : val.table )
            {
                tmp += to_string( entry );
                tmp += ", ";
            }
            str += "[ " + tmp.substr( 0, tmp.size() - 2 ) + " ]";;
        }
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::fan_state_t to std::string
    std::string to_string( const Sysman::fan_state_t val )
    {
        std::string str;
        
        str += "Sysman::fan_state_t::mode : ";
        str += to_string(val.mode);
        str += "\n";
        
        str += "Sysman::fan_state_t::speedUnits : ";
        str += to_string(val.speedUnits);
        str += "\n";
        
        str += "Sysman::fan_state_t::speed : ";
        str += std::to_string(val.speed);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::led_properties_t to std::string
    std::string to_string( const Sysman::led_properties_t val )
    {
        std::string str;
        
        str += "Sysman::led_properties_t::onSubdevice : ";
        str += std::to_string(val.onSubdevice);
        str += "\n";
        
        str += "Sysman::led_properties_t::subdeviceUuid : ";
        str += to_string(val.subdeviceUuid);
        str += "\n";
        
        str += "Sysman::led_properties_t::canControl : ";
        str += std::to_string(val.canControl);
        str += "\n";
        
        str += "Sysman::led_properties_t::haveRGB : ";
        str += std::to_string(val.haveRGB);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::led_state_t to std::string
    std::string to_string( const Sysman::led_state_t val )
    {
        std::string str;
        
        str += "Sysman::led_state_t::isOn : ";
        str += std::to_string(val.isOn);
        str += "\n";
        
        str += "Sysman::led_state_t::red : ";
        str += std::to_string(val.red);
        str += "\n";
        
        str += "Sysman::led_state_t::green : ";
        str += std::to_string(val.green);
        str += "\n";
        
        str += "Sysman::led_state_t::blue : ";
        str += std::to_string(val.blue);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::ras_properties_t to std::string
    std::string to_string( const Sysman::ras_properties_t val )
    {
        std::string str;
        
        str += "Sysman::ras_properties_t::type : ";
        str += to_string(val.type);
        str += "\n";
        
        str += "Sysman::ras_properties_t::onSubdevice : ";
        str += std::to_string(val.onSubdevice);
        str += "\n";
        
        str += "Sysman::ras_properties_t::subdeviceUuid : ";
        str += to_string(val.subdeviceUuid);
        str += "\n";
        
        str += "Sysman::ras_properties_t::supported : ";
        str += std::to_string(val.supported);
        str += "\n";
        
        str += "Sysman::ras_properties_t::enabled : ";
        str += std::to_string(val.enabled);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::ras_details_t to std::string
    std::string to_string( const Sysman::ras_details_t val )
    {
        std::string str;
        
        str += "Sysman::ras_details_t::numResets : ";
        str += std::to_string(val.numResets);
        str += "\n";
        
        str += "Sysman::ras_details_t::numProgrammingErrors : ";
        str += std::to_string(val.numProgrammingErrors);
        str += "\n";
        
        str += "Sysman::ras_details_t::numDriverErrors : ";
        str += std::to_string(val.numDriverErrors);
        str += "\n";
        
        str += "Sysman::ras_details_t::numComputeErrors : ";
        str += std::to_string(val.numComputeErrors);
        str += "\n";
        
        str += "Sysman::ras_details_t::numNonComputeErrors : ";
        str += std::to_string(val.numNonComputeErrors);
        str += "\n";
        
        str += "Sysman::ras_details_t::numCacheErrors : ";
        str += std::to_string(val.numCacheErrors);
        str += "\n";
        
        str += "Sysman::ras_details_t::numMemoryErrors : ";
        str += std::to_string(val.numMemoryErrors);
        str += "\n";
        
        str += "Sysman::ras_details_t::numPciErrors : ";
        str += std::to_string(val.numPciErrors);
        str += "\n";
        
        str += "Sysman::ras_details_t::numSwitchErrors : ";
        str += std::to_string(val.numSwitchErrors);
        str += "\n";
        
        str += "Sysman::ras_details_t::numDisplayErrors : ";
        str += std::to_string(val.numDisplayErrors);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::event_properties_t to std::string
    std::string to_string( const Sysman::event_properties_t val )
    {
        std::string str;
        
        str += "Sysman::event_properties_t::supportedEvents : ";
        {
            std::string tmp;
            for( auto& entry : val.supportedEvents )
            {
                tmp += std::to_string( entry );
                tmp += ", ";
            }
            str += "[ " + tmp.substr( 0, tmp.size() - 2 ) + " ]";;
        }
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::event_request_t to std::string
    std::string to_string( const Sysman::event_request_t val )
    {
        std::string str;
        
        str += "Sysman::event_request_t::event : ";
        str += to_string(val.event);
        str += "\n";
        
        str += "Sysman::event_request_t::threshold : ";
        str += std::to_string(val.threshold);
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::diag_test_t to std::string
    std::string to_string( const Sysman::diag_test_t val )
    {
        std::string str;
        
        str += "Sysman::diag_test_t::index : ";
        str += std::to_string(val.index);
        str += "\n";
        
        str += "Sysman::diag_test_t::name : ";
        str += val.name;
        str += "\n";

        return str;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Sysman::diag_properties_t to std::string
    std::string to_string( const Sysman::diag_properties_t val )
    {
        std::string str;
        
        str += "Sysman::diag_properties_t::type : ";
        str += to_string(val.type);
        str += "\n";
        
        str += "Sysman::diag_properties_t::onSubdevice : ";
        str += std::to_string(val.onSubdevice);
        str += "\n";
        
        str += "Sysman::diag_properties_t::subdeviceUuid : ";
        str += to_string(val.subdeviceUuid);
        str += "\n";
        
        str += "Sysman::diag_properties_t::name : ";
        str += val.name;
        str += "\n";
        
        str += "Sysman::diag_properties_t::numTests : ";
        str += std::to_string(val.numTests);
        str += "\n";
        
        str += "Sysman::diag_properties_t::pTests : ";
        {
            std::stringstream ss;
            ss << "0x" << std::hex << reinterpret_cast<size_t>(val.pTests);
            str += ss.str();
        }
        str += "\n";

        return str;
    }

} // namespace xet
