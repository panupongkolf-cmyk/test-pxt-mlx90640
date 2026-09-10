//% color="#E65100" weight=90 icon="\uf2c7" block="MLX90640"
namespace mlx90640 {
    /**
     * เริ่มต้นตั้งค่าเซนเซอร์ MLX90640 ผ่าน I2C (Pin 19/20)
     */
    //% block="init MLX90640 sensor"
    //% shim=mlx90640::initSensor
    export function initSensor(): boolean {
        return true;
    }

    /**
     * อ่านและประมวลผลเฟรมภาพความร้อน 768 พิกเซลเข้าสู่ Memory (ใช้ Native FPU)
     */
    //% block="capture frame"
    //% shim=mlx90640::captureFrame
    export function captureFrame(): void {
    }

    /**
     * ดึงข้อมูล Binary Buffer ย่อย (Index 0-7) ความยาว 192 ไบต์เพื่อส่งผ่าน Bluetooth UART
     */
    //% block="get frame chunk %chunkIndex"
    //% shim=mlx90640::getChunk
    export function getChunk(chunkIndex: number): Buffer {
        return null;
    }

    /**
     * อ่านค่าอุณหภูมิ (°C) ของพิกเซลที่ระบุ (0-767) สำหรับการ Debug
     */
    //% block="get pixel temp at %pixelIndex"
    //% shim=mlx90640::getPixelTemp
    export function getPixelTemp(pixelIndex: number): number {
        return 0;
    }
}
