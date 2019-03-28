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
* @file xex_cmdgraph.hpp
*
* @brief C++ wrapper of Intel Xe Level-Zero Extended APIs for CommandGraph
*
* @cond DEV
* DO NOT EDIT: generated from /scripts/extended/cmdgraph.yml
* @endcond
*
******************************************************************************/
#ifndef _XEX_CMDGRAPH_HPP
#define _XEX_CMDGRAPH_HPP
#if defined(__cplusplus)
#pragma once
#include "xex_common.hpp"

namespace xex
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief C++ wrapper for command graph
    class CommandGraph
    {
    protected:
        ::xex_command_graph_handle_t handle;              ///< handle of command graph object
        ::xex_command_graph_desc_t desc;                  ///< descriptor of the command graph object

    public:
        auto getHandle( void ) const { return handle; }
        auto getDesc( void ) const { return desc; }

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ wrapper for ::xexCommandGraphDestroy
        /// @throws result_t
        inline void
        Destroy(
            void
            );

        ///////////////////////////////////////////////////////////////////////////////
        /// @brief C++ wrapper for ::xexCommandGraphClose
        /// @throws result_t
        inline void
        Close(
            void
            );

    };

} // namespace xex
#endif // defined(__cplusplus)
#endif // _XEX_CMDGRAPH_HPP