//% color="#E65100" icon="\uf2c7" block="MLX90640"
namespace mlx90640 {
    /**
     * เริ่มต้นการทำงานของเซนเซอร์ MLX90640
     */
    //% block="init MLX90640 sensor"
    //% shim=mlx90640::initSensor
    export function initSensor(): boolean {
        return true;
    }

    /**
     * คำนวณและดึงค่าภาพความร้อน 768 พิกเซล
     */
    //% block="capture frame"
    //% shim=mlx90640::captureFrame
    export function captureFrame(): void {
    }

    /**
     * ดึงแพ็กเกจข้อมูลย่อยสำหรับส่งผ่าน Bluetooth
     */
    //% block="get frame chunk %chunkIndex"
    //% shim=mlx90640::getFrameChunk
    export function getFrameChunk(chunkIndex: number): Buffer {
        return null;
    }
}
