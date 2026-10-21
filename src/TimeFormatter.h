//
// Created by sputnik on 10/21/2026.
//

#ifndef HUD_DEV_TIMEFORMATTER_H
#define HUD_DEV_TIMEFORMATTER_H

#include <cstdint>
#include <cstdio>  // Для snprintf

class TimeFormatter {
public:
    // Запрещаем создавать экземпляры класса, так как это чисто утилитарный класс (Utility Class)
    TimeFormatter() = delete;

    /**
     * Форматирует время круга в формат "М:СС.сс" (например, 1:24.05)
     * @param timeMs Время в миллисекундах
     * @param outBuffer Указатель на массив char, куда запишется результат
     * @param bufferSize Размер этого массива
     */
    static void formatLapTime(uint32_t timeMs, char* outBuffer, size_t bufferSize) {
        if (outBuffer == nullptr || bufferSize == 0) return;

        // Если времени еще нет (круг только начался)
        if (timeMs == 0) {
            snprintf(outBuffer, bufferSize, "--:--.--");
            return;
        }

        uint32_t totalSeconds = timeMs / 1000;
        uint32_t minutes = totalSeconds / 60;
        uint32_t seconds = totalSeconds % 60;
        uint32_t hundredths = (timeMs % 1000) / 10; // Получаем сотые доли секунды (.сс)

        // Запись в формате Минуты:Секунды.Сотые
        // На гоночных DDU тысячные обычно не выводят, чтобы текст не «прыгал» слишком быстро
        snprintf(outBuffer, bufferSize, "%lu:%02lu.%02lu",
                 (unsigned long)minutes, (unsigned long)seconds, (unsigned long)hundredths);
    }

    /**
     * Форматирует дельту времени в формат "+С.сс" или "-С.сс" (например, +0.12 или -1.45)
     * @param deltaMs Дельта в миллисекундах (может быть отрицательной)
     * @param outBuffer Указатель на массив char
     * @param bufferSize Размер массива
     */
    static void formatDelta(int32_t deltaMs, char* outBuffer, size_t bufferSize) {
        if (outBuffer == nullptr || bufferSize == 0) return;

        if (deltaMs == 0) {
            snprintf(outBuffer, bufferSize, " 0.00");
            return;
        }

        // Вычисляем знак дельты
        char sign = (deltaMs > 0) ? '+' : '-';

        // Берем абсолютное значение для дальнейших расчетов
        uint32_t absDelta = (deltaMs > 0) ? deltaMs : -deltaMs;

        uint32_t seconds = absDelta / 1000;
        uint32_t hundredths = (absDelta % 1000) / 10;

        // Выводим дельту со знаком (например: "+0.15" или "-1.04")
        snprintf(outBuffer, bufferSize, "%c%lu.%02lu",
                 sign, (unsigned long)seconds, (unsigned long)hundredths);
    }
};

#endif //HUD_DEV_TIMEFORMATTER_H
