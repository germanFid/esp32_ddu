//
// Created by sputnik on 10/21/2026.
//

#ifndef HUD_DEV_SERIALRECIEVER_H
#define HUD_DEV_SERIALRECIEVER_H

#include <cstdint>
#include <CarData/CarData.h>

namespace Hardware {
#pragma pack(push, 1)
    struct TelemetryPacket {
        uint8_t startMarker;   // 0xAA

        // SpeedInfo
        int32_t speed;
        int32_t rpm;
        int8_t gear;

        // TimingInfo
        uint32_t currentLap;
        uint32_t bestLap;
        int32_t delta;

        // AssistInfo
        uint8_t tcLevel;
        uint8_t absLevel;
        uint8_t tcActive;
        uint8_t absActive;

        uint8_t endMarker;     // 0xBB
    };
#pragma pack(pop)

    class SerialReceiver {
    public:
        SerialReceiver() : bufferIndex(0) {}
        bool readSerial(CarData& carData) {
            while (Serial.available() > 0) {
                uint8_t incomingByte = Serial.read();

                                                                    // Если ищем начало пакета
                if (bufferIndex == 0 && incomingByte != 0xAA) {
                    continue; // Пропускаем мусор
                }

                rawBuffer[bufferIndex++] = incomingByte;

                // Если собрали полный пакет
                if (bufferIndex == sizeof(TelemetryPacket)) {
                    bufferIndex = 0; // Сбрасываем для следующего круга

                    // Проверяем валидность маркеров
                    if (rawBuffer[0] == 0xAA && rawBuffer[sizeof(TelemetryPacket) - 1] == 0xBB) {
                        // Кастуем буфер в структуру
                        TelemetryPacket* packet = reinterpret_cast<TelemetryPacket*>(rawBuffer);

                        // Обновляем CarData через наши ООП сеттеры
                        carData.updateSpeedInfo(packet->speed, packet->rpm, static_cast<Gear>(packet->gear));
                        carData.updateTimingInfo(packet->currentLap, packet->bestLap, packet->delta);
                        carData.updateAssistInfo(packet->tcLevel, packet->absLevel, packet->tcActive > 0, packet->absActive > 0);

                        return true; // Данные успешно обновлены
                    }
                }
            }
            return false;
        }

    private:
        uint8_t rawBuffer[sizeof(TelemetryPacket)];
        std::size_t bufferIndex;
    };
}

#endif //HUD_DEV_SERIALRECIEVER_H
