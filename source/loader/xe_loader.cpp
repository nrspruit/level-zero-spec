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
* @file xe_loader.cpp
*
******************************************************************************/
#include "xe_loader.h"

namespace xe_loader
{
    ///////////////////////////////////////////////////////////////////////////////
    static const char* known_driver_names[] = { 
        MAKE_DRIVER_NAME( "xe_intc_gpu" )
    };

    static const size_t num_known_driver_names =
        sizeof( known_driver_names ) / sizeof( known_driver_names[ 0 ] );

    ///////////////////////////////////////////////////////////////////////////////
    Loader loader;


    ///////////////////////////////////////////////////////////////////////////////
    Loader::Loader()
    {
        drivers.reserve( num_known_driver_names );
        for( auto name : known_driver_names )
        {
            auto handle = LOAD_DRIVER_LIBRARY( name );
            if( NULL != handle )
            {
                drivers.emplace_back();
                drivers.rbegin()->handle = handle;
            }
                
        }

        if( getenv_tobool( "XE_ENABLE_VALIDATION_LAYER" ) )
            validationLayer = LOAD_DRIVER_LIBRARY( MAKE_DRIVER_NAME( "xe_validation_layer" ) );
    };

    ///////////////////////////////////////////////////////////////////////////////
    Loader::~Loader()
    {
        FREE_DRIVER_LIBRARY( validationLayer );

        for( auto& drv : drivers )
            FREE_DRIVER_LIBRARY( drv.handle );
    };

    //////////////////////////////////////////////////////////////////////////
    xe_result_t Loader::xeInit( xe_init_flag_t flags )
    {
        // for each driver, call xeInit
        return XE_RESULT_SUCCESS;
    }

    //////////////////////////////////////////////////////////////////////////
    xe_result_t Loader::xexInit( xe_init_flag_t flags )
    {
        // for each driver, call xexInit
        return XE_RESULT_SUCCESS;
    }

    //////////////////////////////////////////////////////////////////////////
    xe_result_t Loader::xetInit( xe_init_flag_t flags )
    {
        // for each driver, call xetInit
        return XE_RESULT_SUCCESS;
    }

    //////////////////////////////////////////////////////////////////////////
    xe_result_t Loader::xeGetDeviceGroups(
        uint32_t* pCount,
        xe_device_group_handle_t* pDeviceGroups )
    {
        // for each driver, call xeGetDeviceGroups
        // return sum of all
        return XE_RESULT_SUCCESS;
    }


} // namespace xe_loader
