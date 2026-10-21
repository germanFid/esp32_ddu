//
// Created by sputnik on 10/21/2026.
//

#include <string.h>
#include "hud_ui/vars.h"

char v_gear[2] = { 0 };
char v_rpm[100] = { 0 };
char v_speed[100] = { 0 };
int32_t v_percent_rpm;


const char *get_var_v_gear() {
    return v_gear;
}

void set_var_v_gear(const char *value) {
    strncpy(v_gear, value, sizeof(v_gear) / sizeof(char));
    v_gear[sizeof(v_gear) / sizeof(char) - 1] = 0;
}

const char *get_var_v_rpm() {
    return v_rpm;
}

void set_var_v_rpm(const char *value) {
    strncpy(v_rpm, value, sizeof(v_rpm) / sizeof(char));
    v_rpm[sizeof(v_rpm) / sizeof(char) - 1] = 0;
}

const char *get_var_v_speed() {
    return v_speed;
}

void set_var_v_speed(const char *value) {
    strncpy(v_speed, value, sizeof(v_speed) / sizeof(char));
    v_speed[sizeof(v_speed) / sizeof(char) - 1] = 0;
}

int32_t get_var_v_percent_rpm() {
    return v_percent_rpm;
}

void set_var_v_percent_rpm(int32_t value) {
    v_percent_rpm = value;
}
