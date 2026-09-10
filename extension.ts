//% color="#E65100" weight=90 icon="\uf2c7" block="MLX90640"
namespace mlx90640 {
    //% block="init MLX90640 sensor"
    //% shim=mlx90640::initSensor
    export function initSensor(): boolean { return true; }

    //% block="capture frame"
    //% shim=mlx90640::captureFrame
    export function captureFrame(): void { }

    //% block="create chunk buffer"
    export function createChunkBuffer(): Buffer {
        return control.createBuffer(192);
    }

    //% block="fill chunk %chunkIndex into %buf"
    //% shim=mlx90640::fillChunk
    export function fillChunk(chunkIndex: number, buf: Buffer): void { }
}
