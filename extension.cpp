#include "pxt.h"

namespace mlx90640 {
    //%
    bool initSensor() {
        return true;
    }

    //%
    void captureFrame() {
    }

    //%
    Buffer getChunk(int chunkIndex) {
        uint8_t dummy[192] = {0};
        return pxt::mkBuffer(dummy, 192);
    }

    //%
    int getPixelTemp(int pixelIndex) {
        return 250;
    }
}
