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
* @file xe_image.cpp
*
* @brief C++ wrapper of Intel Xe Level-Zero APIs for Images
*
* @cond DEV
* DO NOT EDIT: generated from /scripts/core/image.yml
* @endcond
*
******************************************************************************/
#include "xe_api.hpp"
#include "xe_api.h"

namespace xe
{
    ///////////////////////////////////////////////////////////////////////////////
    Image::Image( 
        Device* pDevice,                                ///< [in] pointer to parent object
        const desc_t& desc                              ///< [in] descriptor of the image object
        ) :
        m_pDevice( pDevice ),
        m_desc( desc )
    {
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Retrieves supported properties of an image.
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @returns
    ///     - properties_t: pointer to image properties
    /// 
    /// @throws result_t
    Image::properties_t __xecall
    Image::GetProperties(
        Device* pDevice,                                ///< [in] pointer to the device
        const desc_t* desc                              ///< [in] pointer to image descriptor
        )
    {
        // auto result = ::xeImageGetProperties( handle, pDevice, desc );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::Image::GetProperties");

        return properties_t{};
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Creates a image object on the device.
    /// 
    /// @details
    ///     - The application may call this function from simultaneous threads.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @remarks
    ///   _Analogues_
    ///     - clCreateImage
    /// 
    /// @returns
    ///     - Image: pointer to handle of image object created
    /// 
    /// @throws result_t
    Image* __xecall
    Image::Create(
        Device* pDevice,                                ///< [in] pointer to the device
        const desc_t* desc                              ///< [in] pointer to image descriptor
        )
    {
        // auto result = ::xeImageCreate( handle, pDevice, desc );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::Image::Create");

        return (Image*)0;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Deletes a image object.
    /// 
    /// @details
    ///     - The application is responsible for making sure the device is not
    ///       currently referencing the image before it is deleted
    ///     - The implementation of this function will immediately free all Host and
    ///       Device allocations associated with this image
    ///     - The application may **not** call this function from simultaneous
    ///       threads with the same image handle.
    ///     - The implementation of this function should be lock-free.
    /// 
    /// @throws result_t
    void __xecall
    Image::Destroy(
        Image* pImage                                   ///< [in] pointer to image object to destroy
        )
    {
        // auto result = ::xeImageDestroy( handle, pImage );
        // if( ::XE_RESULT_SUCCESS != result ) throw exception(result, "xe::Image::Destroy");
    }

#ifdef _DEBUG
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Image::desc_version_t to std::string
    std::string to_string( Image::desc_version_t val )
    {
        switch( val )
        {
        case Image::desc_version_t::CURRENT:
            return std::string("Image::desc_version_t::CURRENT");
        };
        return std::string("Image::desc_version_t::?");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Image::flag_t to std::string
    std::string to_string( Image::flag_t val )
    {
        const auto bits = static_cast<uint32_t>( val );
        if( 0 == bits ) return std::string("{}");
        std::string str;
        if( static_cast<uint32_t>(Image::flag_t::PROGRAM_READ) & bits )
            str += "Image::flag_t::PROGRAM_READ | ";
        if( static_cast<uint32_t>(Image::flag_t::PROGRAM_WRITE) & bits )
            str += "Image::flag_t::PROGRAM_WRITE | ";
        if( static_cast<uint32_t>(Image::flag_t::BIAS_CACHED) & bits )
            str += "Image::flag_t::BIAS_CACHED | ";
        if( static_cast<uint32_t>(Image::flag_t::BIAS_UNCACHED) & bits )
            str += "Image::flag_t::BIAS_UNCACHED | ";
        return "{ " + str.substr(0, str.size() - 3) + " }";
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Image::type_t to std::string
    std::string to_string( Image::type_t val )
    {
        switch( val )
        {
        case Image::type_t::_1D:
            return std::string("Image::type_t::_1D");
        case Image::type_t::_1DARRAY:
            return std::string("Image::type_t::_1DARRAY");
        case Image::type_t::_2D:
            return std::string("Image::type_t::_2D");
        case Image::type_t::_2DARRAY:
            return std::string("Image::type_t::_2DARRAY");
        case Image::type_t::_3D:
            return std::string("Image::type_t::_3D");
        };
        return std::string("Image::type_t::?");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Image::format_layout_t to std::string
    std::string to_string( Image::format_layout_t val )
    {
        switch( val )
        {
        case Image::format_layout_t::_8:
            return std::string("Image::format_layout_t::_8");
        case Image::format_layout_t::_16:
            return std::string("Image::format_layout_t::_16");
        case Image::format_layout_t::_32:
            return std::string("Image::format_layout_t::_32");
        case Image::format_layout_t::_8_8:
            return std::string("Image::format_layout_t::_8_8");
        case Image::format_layout_t::_8_8_8_8:
            return std::string("Image::format_layout_t::_8_8_8_8");
        case Image::format_layout_t::_16_16:
            return std::string("Image::format_layout_t::_16_16");
        case Image::format_layout_t::_16_16_16_16:
            return std::string("Image::format_layout_t::_16_16_16_16");
        case Image::format_layout_t::_32_32:
            return std::string("Image::format_layout_t::_32_32");
        case Image::format_layout_t::_32_32_32_32:
            return std::string("Image::format_layout_t::_32_32_32_32");
        case Image::format_layout_t::_10_10_10_2:
            return std::string("Image::format_layout_t::_10_10_10_2");
        case Image::format_layout_t::_11_11_10:
            return std::string("Image::format_layout_t::_11_11_10");
        case Image::format_layout_t::_5_6_5:
            return std::string("Image::format_layout_t::_5_6_5");
        case Image::format_layout_t::_5_5_5_1:
            return std::string("Image::format_layout_t::_5_5_5_1");
        case Image::format_layout_t::_4_4_4_4:
            return std::string("Image::format_layout_t::_4_4_4_4");
        case Image::format_layout_t::Y8:
            return std::string("Image::format_layout_t::Y8");
        case Image::format_layout_t::NV12:
            return std::string("Image::format_layout_t::NV12");
        case Image::format_layout_t::YUYV:
            return std::string("Image::format_layout_t::YUYV");
        case Image::format_layout_t::VYUY:
            return std::string("Image::format_layout_t::VYUY");
        case Image::format_layout_t::YVYU:
            return std::string("Image::format_layout_t::YVYU");
        case Image::format_layout_t::UYVY:
            return std::string("Image::format_layout_t::UYVY");
        case Image::format_layout_t::AYUV:
            return std::string("Image::format_layout_t::AYUV");
        case Image::format_layout_t::YUAV:
            return std::string("Image::format_layout_t::YUAV");
        case Image::format_layout_t::P010:
            return std::string("Image::format_layout_t::P010");
        case Image::format_layout_t::Y410:
            return std::string("Image::format_layout_t::Y410");
        case Image::format_layout_t::P012:
            return std::string("Image::format_layout_t::P012");
        case Image::format_layout_t::Y16:
            return std::string("Image::format_layout_t::Y16");
        case Image::format_layout_t::P016:
            return std::string("Image::format_layout_t::P016");
        case Image::format_layout_t::Y216:
            return std::string("Image::format_layout_t::Y216");
        case Image::format_layout_t::P216:
            return std::string("Image::format_layout_t::P216");
        case Image::format_layout_t::P416:
            return std::string("Image::format_layout_t::P416");
        };
        return std::string("Image::format_layout_t::?");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Image::format_type_t to std::string
    std::string to_string( Image::format_type_t val )
    {
        switch( val )
        {
        case Image::format_type_t::UINT:
            return std::string("Image::format_type_t::UINT");
        case Image::format_type_t::SINT:
            return std::string("Image::format_type_t::SINT");
        case Image::format_type_t::UNORM:
            return std::string("Image::format_type_t::UNORM");
        case Image::format_type_t::SNORM:
            return std::string("Image::format_type_t::SNORM");
        case Image::format_type_t::FLOAT:
            return std::string("Image::format_type_t::FLOAT");
        };
        return std::string("Image::format_type_t::?");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Image::format_swizzle_t to std::string
    std::string to_string( Image::format_swizzle_t val )
    {
        switch( val )
        {
        case Image::format_swizzle_t::R:
            return std::string("Image::format_swizzle_t::R");
        case Image::format_swizzle_t::G:
            return std::string("Image::format_swizzle_t::G");
        case Image::format_swizzle_t::B:
            return std::string("Image::format_swizzle_t::B");
        case Image::format_swizzle_t::A:
            return std::string("Image::format_swizzle_t::A");
        case Image::format_swizzle_t::_0:
            return std::string("Image::format_swizzle_t::_0");
        case Image::format_swizzle_t::_1:
            return std::string("Image::format_swizzle_t::_1");
        case Image::format_swizzle_t::X:
            return std::string("Image::format_swizzle_t::X");
        };
        return std::string("Image::format_swizzle_t::?");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Image::properties_version_t to std::string
    std::string to_string( Image::properties_version_t val )
    {
        switch( val )
        {
        case Image::properties_version_t::CURRENT:
            return std::string("Image::properties_version_t::CURRENT");
        };
        return std::string("Image::properties_version_t::?");
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Converts Image::sampler_filter_flags_t to std::string
    std::string to_string( Image::sampler_filter_flags_t val )
    {
        const auto bits = static_cast<uint32_t>( val );
        if( 0 == bits ) return std::string("{}");
        std::string str;
        if( static_cast<uint32_t>(Image::sampler_filter_flags_t::LINEAR) & bits )
            str += "Image::sampler_filter_flags_t::LINEAR | ";
        return "{ " + str.substr(0, str.size() - 3) + " }";
    }


#endif // _DEBUG
} // namespace xe