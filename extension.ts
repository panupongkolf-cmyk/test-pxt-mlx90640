//% color="#E65100" weight=90 icon="\uf2c7" block="MLX90640"
namespace mlx90640 {
    //% block="init MLX90640 sensor"
    //% shim=mlx90640::initSensor
    export function initSensor(): boolean {
        return true;
    }

    //% block="capture frame"
    //% shim=mlx90640::captureFrame
    export function captureFrame(): void {
    }

    //% block="get frame chunk %chunkIndex"
    //% shim=mlx90640::getChunk
    export function getChunk(chunkIndex: number): Buffer {
        return null;
    }

    //% block="get pixel temp at %pixelIndex"
    //% shim=mlx90640::getPixelTemp
    export function getPixelTemp(pixelIndex: number): number {
        return 0;
    }
}
