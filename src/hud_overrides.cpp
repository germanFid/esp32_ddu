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

char v_laptime_predict[100] = { 0 };

const char *get_var_v_laptime_predict() {
    return v_laptime_predict;
}

void set_var_v_laptime_predict(const char *value) {
    strncpy(v_laptime_predict, value, sizeof(v_laptime_predict) / sizeof(char));
    v_laptime_predict[sizeof(v_laptime_predict) / sizeof(char) - 1] = 0;
}

char v_laptime_delta[100] = { 0 };

const char *get_var_v_laptime_delta() {
    return v_laptime_delta;
}

void set_var_v_laptime_delta(const char *value) {
    strncpy(v_laptime_delta, value, sizeof(v_laptime_delta) / sizeof(char));
    v_laptime_delta[sizeof(v_laptime_delta) / sizeof(char) - 1] = 0;
}

char v_laptime_current[100] = { 0 };

const char *get_var_v_laptime_current() {
    return v_laptime_current;
}

void set_var_v_laptime_current(const char *value) {
    strncpy(v_laptime_current, value, sizeof(v_laptime_current) / sizeof(char));
    v_laptime_current[sizeof(v_laptime_current) / sizeof(char) - 1] = 0;
}

char v_laps_count[100] = { 0 };

const char *get_var_v_laps_count() {
    return v_laps_count;
}

void set_var_v_laps_count(const char *value) {
    strncpy(v_laps_count, value, sizeof(v_laps_count) / sizeof(char));
    v_laps_count[sizeof(v_laps_count) / sizeof(char) - 1] = 0;
}

char v_abs_value[100] = { 0 };

const char *get_var_v_abs_value() {
    return v_abs_value;
}

void set_var_v_abs_value(const char *value) {
    strncpy(v_abs_value, value, sizeof(v_abs_value) / sizeof(char));
    v_abs_value[sizeof(v_abs_value) / sizeof(char) - 1] = 0;
}

char v_tc_value[100] = { 0 };

const char *get_var_v_tc_value() {
    return v_tc_value;
}

void set_var_v_tc_value(const char *value) {
    strncpy(v_tc_value, value, sizeof(v_tc_value) / sizeof(char));
    v_tc_value[sizeof(v_tc_value) / sizeof(char) - 1] = 0;
}

