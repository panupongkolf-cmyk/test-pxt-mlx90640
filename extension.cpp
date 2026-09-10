#include "pxt.h"
#include "MicroBit.h"

namespace mlx90640 {
    // กำหนดที่อยู่ I2C ของ MLX90640 (มาตรฐาน 0x33)
    #define MLX90640_I2C_ADDR (0x33 << 1)

    // บัฟเฟอร์เก็บอุณหภูมิ 768 พิกเซล (768 x 2 ไบต์ = 1,536 ไบต์)
    static int16_t frameBuffer[768];
    static bool isInitialized = false;

    //%
    bool initSensor() {
        // กำหนดความเร็ว I2C Bus ของ micro:bit V2 ไปที่ 400kHz (Fast Mode)
        uBit.i2c.frequency(400000);
        
        // ส่งคำสั่งคำนวณและตั้งค่า Refresh Rate ของ MLX90640 ที่ 4Hz/8Hz
        uint8_t cmd[2] = {0x80, 0x0D}; // Control register address
        int ret = uBit.i2c.write(MLX90640_I2C_ADDR, (char*)cmd, 2);
        
        if (ret == MICROBIT_OK) {
            isInitialized = true;
            return true;
        }
        return false;
    }

    //%
    void captureFrame() {
        if (!isInitialized) return;

        // ดึงข้อมูลภาพความร้อนจาก MLX90640 และประมวลผลด้วย FPU ฮาร์ดแวร์
        // ในส่วนนี้จะจำลองการอ่านคำนวณ 768 ค่า แล้วแปลงเป็น (Float * 10) เก็บลง int16_t
        for (int i = 0; i < 768; i++) {
            // ตัวอย่าง: แปลงสมการ FPU เป็น int16_t (เช่น 25.4°C -> 254)
            // frameBuffer[i] = (int16_t)(calculatedTemp * 10.0f);
            
            // ข้อมูลจำลองสำหรับทดสอบระบบ
            frameBuffer[i] = (int16_t)(250 + (i % 50)); 
        }
    }

    //%
    Buffer getChunk(int chunkIndex) {
        // แบ่งข้อมูล 1,536 ไบต์ ออกเป็น 8 Chunk (Chunk ละ 192 ไบต์)
        int chunkSize = 192;
        int offset = chunkIndex * chunkSize;

        if (offset >= 1,536 || chunkIndex < 0) return NULL;

        // สร้าง MakeCode Buffer ส่งออกไปยังชั้น Python
        uint8_t* ptr = (uint8_t*)frameBuffer + offset;
        return pxt::mkBuffer(ptr, chunkSize);
    }

    //%
    float getPixelTemp(int pixelIndex) {
        if (pixelIndex < 0 || pixelIndex >= 768) return 0.0f;
        return (float)frameBuffer[pixelIndex] / 10.0f;
    }
}
