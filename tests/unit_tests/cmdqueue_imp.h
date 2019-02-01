#pragma once
#include "cmdqueue.h"

namespace OCLRT {
class LinearStream;
}

namespace xe {
struct GraphicsAllocation;

struct CommandQueueImp : public CommandQueue {
    CommandQueueImp(Device *device)
        : device(device),
        allocation(nullptr),
        commandStream(nullptr) {
    }

    xe_result_t destroy() override;

    void initialize();

  protected:
    Device *device;
    GraphicsAllocation *allocation;
    OCLRT::LinearStream *commandStream;
};

} // namespace xe