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
    void fillChunk(int chunkIndex, Buffer buf) {
        if (NULL == buf) return;
        
        // โค้ดสำหรับคัดลอกข้อมูลลง Buffer จะอยู่ตรงนี้ในอนาคต
        // เช่น memcpy(buf->data, source_data, 192);
    }
}
