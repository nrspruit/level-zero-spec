#pragma once
#define IMAGE_INTERNAL
#include "image_imp.h"
#undef IMAGE_INTERNAL
#include "runtime/command_stream/linear_stream.h"
#include "runtime/helpers/hw_info.h"
#include "runtime/indirect_heap/indirect_heap.h"

namespace L0 {

template <GFXCORE_FAMILY gfxCoreFamily>
struct ImageCoreFamily : public ImageImp {
    using GfxFamily = typename OCLRT::GfxFamilyMapper<gfxCoreFamily>::GfxFamily;
    using RENDER_SURFACE_STATE = typename GfxFamily::RENDER_SURFACE_STATE;
    using SURFACE_FORMAT = typename RENDER_SURFACE_STATE::SURFACE_FORMAT;
    using BaseClass = ImageImp;
    using ImageImp::ImageImp;

	//XE_NUMCHANNELS is subtracted off to eliminate an unused channel in every row.
    const SURFACE_FORMAT format_table[XE_IMAGE_FORMAT_MAX + 1][XE_NUMCHANNELS_MAX + 1 - XE_NUMCHANNELS_MIN] = {
        {RENDER_SURFACE_STATE::SURFACE_FORMAT_R8_UINT,	//XE_IMAGE_FORMAT_UINT8
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R8G8_UINT,
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R8G8B8_UINT,
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R8G8B8A8_UINT},
        {RENDER_SURFACE_STATE::SURFACE_FORMAT_R16_UINT,	//XE_IMAGE_FORMAT_UINT16
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R16G16_UINT,
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R16G16B16_UINT,
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R16G16B16A16_UINT},
        {RENDER_SURFACE_STATE::SURFACE_FORMAT_R32_UINT,	//XE_IMAGE_FORMAT_UINT32
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R32G32_UINT,
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R32G32B32_UINT,
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R32G32B32A32_UINT},
        {RENDER_SURFACE_STATE::SURFACE_FORMAT_R8_SINT, //XE_IMAGE_FORMAT_SINT8
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R8G8_SINT,
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R8G8B8_SINT,
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R8G8B8A8_SINT},
        {RENDER_SURFACE_STATE::SURFACE_FORMAT_R16_SINT, //XE_IMAGE_FORMAT_SINT16
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R16G16_SINT,
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R16G16B16_SINT,
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R16G16B16A16_SINT},
        {RENDER_SURFACE_STATE::SURFACE_FORMAT_R32_SINT, //XE_IMAGE_FORMAT_SINT32
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R32G32_SINT,
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R32G32B32_SINT,
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R32G32B32A32_SINT},
        {RENDER_SURFACE_STATE::SURFACE_FORMAT_R16_FLOAT, //XE_IMAGE_FORMAT_FLOAT16
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R16G16_FLOAT,
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R16G16B16_FLOAT,
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R16G16B16A16_FLOAT},
        {RENDER_SURFACE_STATE::SURFACE_FORMAT_R32_FLOAT, //XE_IMAGE_FORMAT_FLOAT32
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R32G32_FLOAT,
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R32G32B32_FLOAT,
            RENDER_SURFACE_STATE::SURFACE_FORMAT_R32G32B32A32_FLOAT},
    };

    bool initialize(Device *device, const xe_image_desc_t *desc) override;

  protected:
    RENDER_SURFACE_STATE surfaceState;
};

template <uint32_t gfxProductFamily>
struct ImageProductFamily;

} //namespace L0