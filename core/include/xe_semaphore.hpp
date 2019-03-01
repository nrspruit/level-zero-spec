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
* @file xe_semaphore.hpp
*
* @brief C++ wrapper of Intel Xe Driver APIs for Semaphore
*
* @cond DEV
* DO NOT EDIT: generated from /scripts/core/semaphore.yml
* @endcond
*
******************************************************************************/
#ifndef _XE_SEMAPHORE_HPP
#define _XE_SEMAPHORE_HPP
#if defined(__cplusplus)
#pragma once
#include "xe_common.hpp"

namespace xe
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for semaphore
    class Semaphore
    {
    protected:
        ::xe_semaphore_handle_t handle;                   ///< handle of semaphore object
        ::xe_semaphore_desc_t desc;                       ///< descriptor of the semaphore object

    public:
        auto getHandle( void ) const { return handle; }
        auto getDesc( void ) const { return desc; }

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ wrapper for ::xeSemaphoreDestroy
        inline void Destroy(
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ wrapper for ::xeSemaphoreQueryValue
        inline void QueryValue(
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ wrapper for ::xeSemaphoreReset
        inline void Reset(
            );

    };

} // namespace xe
#endif // defined(__cplusplus)
#endif // _XE_SEMAPHORE_HPP