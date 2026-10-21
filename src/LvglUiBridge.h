//
// Created by sputnik on 10/21/2026.
//

#ifndef HUD_DEV_LVGLUIBRIDGE_H
#define HUD_DEV_LVGLUIBRIDGE_H
#include <cstdio>

#include "hud_ui/vars.h"
#include "CarData/CarData.h"
#include "TimeFormatter.h"


namespace Hardware {
    class LvglUiBridge {
    public:
        LvglUiBridge() = delete;

        static void updateUi(const CarData& carData) {
            char speedStr[12];
            char rpmStr[12];
            snprintf(speedStr, sizeof(speedStr), "%d", carData.getSpeedInfo().getSpeed());
            snprintf(rpmStr, sizeof(rpmStr), "%d", carData.getSpeedInfo().getRPM());

            set_var_v_rpm(rpmStr);
            set_var_v_speed(speedStr);

            // 2. Обновление Передачи (Конвертация enum class в строку)
            const char* gearText = getGearString(carData.getSpeedInfo().getGear());
            set_var_v_gear(gearText);

            // 3. Обновление Таймингов (используем наш TimeFormatter)
            char lapTimeStr[16];
            char bestLapTimeStr[16];
            char deltaStr[16];

            TimeFormatter::formatLapTime(carData.getTimingInfo().getCurrentLapTimeMs(), lapTimeStr, sizeof(lapTimeStr));
            TimeFormatter::formatDelta(carData.getTimingInfo().getDeltaMs(), deltaStr, sizeof(deltaStr));
            TimeFormatter::formatLapTime(carData.getTimingInfo().getBestLapTimeMs(), bestLapTimeStr, sizeof(deltaStr));

            set_var_v_laptime_delta(deltaStr);
            set_var_v_laptime_current(lapTimeStr);
            set_var_v_laptime_predict(bestLapTimeStr);

            // 4. Обновление помощников
            char tc_valueStr[16];
            char abs_valueStr[16];

            snprintf(tc_valueStr, sizeof(tc_valueStr), "%d", carData.getAssistInfo().getTcLevel());
            snprintf(abs_valueStr, sizeof(abs_valueStr), "%d", carData.getAssistInfo().getAbsLevel());

            set_var_v_tc_value(tc_valueStr);
            set_var_v_abs_value(abs_valueStr);
        }

    private:
        // Быстрый маппинг без выделения памяти в куче
        static const char* getGearString(Gear gear) {
            switch (gear) {
                case Gear::Reverse: return "R";
                case Gear::Neutral: return "N";
                case Gear::First:   return "1";
                case Gear::Second:  return "2";
                case Gear::Third:   return "3";
                case Gear::Fourth:  return "4";
                case Gear::Fifth:   return "5";
                case Gear::Sixth:   return "6";
                case Gear::Seventh: return "7";
                case Gear::Eighth:  return "8";
                case Gear::Ninth:   return "9";
                default:            return "-";
            }
        }
    };
}

#endif //HUD_DEV_LVGLUIBRIDGE_H
