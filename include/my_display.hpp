#pragma once
#define LGFX_USE_V1
#include <LovyanGFX.hpp>

class LGFX : public lgfx::LGFX_Device
{
    lgfx::Panel_Device* _panel_instance;
    lgfx::Bus_SPI*      _bus_instance;

public:
    LGFX(void)
    {
        _bus_instance = new lgfx::Bus_SPI();
        _panel_instance = new lgfx::Panel_ST7796();

        auto bus_cfg = _bus_instance->config();
        bus_cfg.spi_host = VSPI_HOST;     // На ESP32 обычно SPI2_HOST (он же HSPI) или SPI3_HOST (VSPI)
        bus_cfg.spi_mode = 0;
        bus_cfg.freq_write = 40000000;    // Скорость шины на запись (40 МГц)
        bus_cfg.freq_read  = 16000000;

        // === ЗАДАЙТЕ ВАШИ ПИНЫ ДЛЯ ШИНЫ ТУТ ===
        bus_cfg.pin_sclk = 18;            // Пин тактирования (CLK / SCK)
        bus_cfg.pin_mosi = 23;            // Пин передачи данных (MOSI / SDA)
        bus_cfg.pin_miso = 19;            // Пин приема данных (MISO / SDO), если не используется — поставьте -1
        bus_cfg.pin_dc   = 2;             // Пин выборки данных/команд (DC / RS)

        _bus_instance->config(bus_cfg);
        _panel_instance->setBus(_bus_instance);

        auto panel_cfg = _panel_instance->config();

        // === ЗАДАЙТЕ ОСТАЛЬНЫЕ ПИНЫ ТУТ ===
        panel_cfg.pin_cs           =  15;  // Пин выбора чипа (CS)
        panel_cfg.pin_rst          =  4;  // Пин сброса (RST / RESET), если подключен к EN платы — поставьте -1
        // panel_cfg.pin_bl           = -1;  // Пин управления подсветкой (LED / BL)

        // panel_cfg.backlight_level  = true;// true = подсветка горит при подаче HIGH, false = при подаче LOW
        panel_cfg.panel_width      = 320; // Физическое разрешение матрицы
        panel_cfg.panel_height     = 480;
        panel_cfg.offset_x         = 0;
        panel_cfg.offset_y         = 0;

        _panel_instance->config(panel_cfg);
        setPanel(_panel_instance);
    }
};