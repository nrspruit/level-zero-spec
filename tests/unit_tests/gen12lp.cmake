if(SUPPORT_GEN12LP)
    set(HW_SOURCES
        ${HW_SOURCES}
        ${COMPUTE_RUNTIME_GEN12LP}
        cmdlist_tgllp.cpp
        cmdqueue_tgllp.cpp
        gen12lp.cmake
    )

    set(HW_SOURCES_ULT
        ${HW_SOURCES_ULT}
        ${COMPUTE_RUNTIME_ULT_GEN12LP}
        ${HW_SOURCES}
    )

    set(DEFAULT_PRODUCT_FAMILY IGFX_TIGERLAKE_LP)
endif()
