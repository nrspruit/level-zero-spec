#pragma once
#include "cmdqueue.h"

namespace OCLRT {
class LinearStream;
}

namespace L0 {
struct CommandList;
struct GraphicsAllocation;

struct CommandQueueImp : public CommandQueue {
    CommandQueueImp(Device *device, void *csrRT)
        : device(device),
          csrRT(csrRT),
          allocation(nullptr),
          commandStream(nullptr) {
    }

    xe_result_t destroy() override;

    void initialize();

  protected:
    void processResidency(CommandList *);
    void processCoherency(CommandList *);
    void submitBatchBuffer();
    Device *device;
    void *csrRT;
    GraphicsAllocation *allocation;
    OCLRT::LinearStream *commandStream;
};

} // namespace L0