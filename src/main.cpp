#include <Arduino.h>
#include <lvgl.h>

#include "LvglUiBridge.h"
#include "my_display.hpp"
#include "hud_ui/ui.h"
#include "hud_ui/vars.h"
#include "SerialReciever.h"

#define HOR_RES 320
#define VER_RES 480
#define BUF_SIZE (HOR_RES * 40 * 2) // Для RGB565 на 40 строк (в байтах)

static LGFX lcd;
static uint8_t lv_buffer[BUF_SIZE];

CarData carData;
Hardware::SerialReceiver serialReceiver;

// DEBUG_VALUES
// int rpm;
// int speed;
//
// std::string rpm_str;
// std::string speed_str;

static uint32_t my_tick(void)
{
    return millis();
}

void updateHardware(const int rpm, const int rpmPercent, const int speed, const String* gear) {
    set_var_v_rpm(std::to_string(rpm).c_str());
    set_var_v_speed(std::to_string(speed).c_str());
    set_var_v_percent_rpm(rpmPercent);
    set_var_v_gear(gear->c_str());
}

void parseTelemetry(String data) {
    // Ищем позиции разделителей '_'
    int firstUnderscore = data.indexOf('_');
    int secondUnderscore = data.indexOf('_', firstUnderscore + 1);
    int thirdUnderscore = data.indexOf('_', secondUnderscore + 1);

    // Проверяем корректность пакета
    if (firstUnderscore == -1 || secondUnderscore == -1) {
        return; // Битый пакет, пропускаем
    }

    // Разделяем строку на подстроки
    String rpmStr = data.substring(0, firstUnderscore);
    String rpmPercentStr = data.substring(firstUnderscore + 1, secondUnderscore);
    String speedStr = data.substring(secondUnderscore + 1, thirdUnderscore);
    String gearStr = data.substring(thirdUnderscore + 1);

    // Конвертируем в нужные типы данных
    int rpm = rpmStr.toInt();
    int rpmPercent = rpmPercentStr.toInt();
    int speed = speedStr.toInt();
    // Передачу оставляем строкой (String), так как SimHub шлет 'N' и 'R'

    // Применяем данные к вашему железу
    updateHardware(rpm, rpmPercent, speed, &gearStr);
}

void setup() {
    lcd.init();
    lcd.fillScreen(TFT_BLACK);

    lv_init();
    lv_tick_set_cb(my_tick);

    lv_display_t *disp = lv_lovyan_gfx_create(HOR_RES, VER_RES, lv_buffer, sizeof(lv_buffer), true);

    lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_270);

    Serial.begin(115200);
    while (!Serial) { delay(10); }

    ui_init(); // FROM EEZ
}

void loop() {
    if (serialReceiver.readSerial(carData)) {
        Hardware::LvglUiBridge::updateUi(carData);
    }

    ui_tick();

    lv_timer_handler();
    delay(5);
}