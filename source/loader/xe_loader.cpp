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
        commonDriver = LOAD_DRIVER_LIBRARY( known_driver_names[ 0 ] );

        if( getenv_tobool( "XE_ENABLE_VALIDATION_LAYER" ) )
            validationLayer = LOAD_DRIVER_LIBRARY( MAKE_DRIVER_NAME( "xe_validation_layer" ) );
    };

    ///////////////////////////////////////////////////////////////////////////////
    Loader::~Loader()
    {
        FREE_DRIVER_LIBRARY( validationLayer );
        FREE_DRIVER_LIBRARY( commonDriver );
    };

} // namespace xe_loader