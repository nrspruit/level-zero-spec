#pragma once
#include "device.h"
#include "gmock/gmock.h"

namespace xe {

struct MockDevice : public Device {
    MockDevice();
    virtual ~MockDevice();

    MOCK_METHOD2(createCommandList, xe_result_t(const xe_command_list_desc_t *desc,
                                                xe_command_list_handle_t *commandList));

    MOCK_METHOD2(createCommandQueue, xe_result_t(const xe_command_queue_desc_t *desc,
                                                 xe_command_queue_handle_t *commandQueue));

    MOCK_METHOD2(createEvent, xe_result_t(const xe_event_desc_t *desc,
                                          xe_event_handle_t *event));

    MOCK_METHOD0(getMemoryManager, MemoryManager *());
};

} // namespace xe
