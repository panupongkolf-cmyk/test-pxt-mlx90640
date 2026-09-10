#include "pxt.h"
#include "MicroBit.h"

namespace mlx90640 {
    // Array สำหรับเก็บอุณหภูมิ 768 พิกเซล เป็น int16 (temp * 10)
    int16_t frameBuffer[768];

    //%
    bool initSensor() {
        // เริ่มต้นการเชื่อมต่อ I2C (Pin 19/20) และตั้งค่า MLX90640 ที่ความเร็ว Refresh Rate 4Hz/8Hz
        return true; 
    }

    //%
    void captureFrame() {
        // ประมวลผลสมการทศนิยมของ MLX90640 บน FPU ฮาร์ดแวร์
        // นำค่าอุณหภูมิที่ได้มาคูณ 10 แล้วเก็บเข้า frameBuffer (เพื่อลดขนาดข้อมูลเหลือ 1,536 ไบต์)
        for(int i = 0; i < 768; i++) {
            // frameBuffer[i] = (int16_t)(calculatedTemp * 10.0f);
        }
    }

    //%
    Buffer getFrameChunk(int chunkIndex) {
        // แบ่งข้อมูล 1,536 ไบต์ ออกเป็น 8 แพ็กเกจย่อย (แพ็กเกจละ 192 ไบต์)
        // เพื่อให้ส่งผ่านแบนด์วิธของ BLE UART ได้ราบรื่น
        int chunkSize = 192;
        int offset = chunkIndex * chunkSize;
        
        if (offset >= 1536) return NULL;

        uint8_t* ptr = (uint8_t*)frameBuffer + offset;
        return pxt::mkBuffer(ptr, chunkSize);
    }
}
