#include "module.h"

#include <cassert>
#include <memory>

namespace L0 {

struct ModuleBuildLogImp : public ModuleBuildLog {
    ModuleBuildLogImp() {}

    ~ModuleBuildLogImp() {}

    xe_result_t destroy() override {
        delete this;
        return XE_RESULT_SUCCESS;
    }

    xe_result_t getString(size_t *pSize, char *pBuildLog) override {
        // FIX_ME: const_cast shouldnt be here.
        char *buildLog = const_cast<char *>(this->buildLog.c_str());

        // FIX_ME: API has changed where application will call getString twice. The flow:
        //         1. getString(&szSize, nullptr)
        //         2. pString = malloc(szSize)
        //         3. getString(&szSize, pString)
        /*
        if (buildLog != nullptr) {
            *pBuildLog = buildLog;
            *pSize = strlen(buildLog) + 1;
        } else {
            *pBuildLog = nullptr;
            *pSize = 0;
        }
        */
        return XE_RESULT_SUCCESS;
    }

    void appendString(const char *pBuildLog, size_t size) override {
        if ((pBuildLog == nullptr) || (size == 0) || (pBuildLog[0] == '\0'))
            return;

        if (pBuildLog[size - 1] == '\0')
            --size;

        if (this->buildLog.length() != 0)
            this->buildLog.append("\n");

        this->buildLog.append(pBuildLog, size);
    }

  protected:
    std::string buildLog;
};

ModuleBuildLog *ModuleBuildLog::create() {
    auto moduleBuildLog = new ModuleBuildLogImp();
    assert(moduleBuildLog != nullptr);
    return moduleBuildLog;
}

} // namespace L0