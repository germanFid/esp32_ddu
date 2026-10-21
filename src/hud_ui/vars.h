#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations

// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_V_GEAR = 0,
    FLOW_GLOBAL_VARIABLE_V_RPM = 1,
    FLOW_GLOBAL_VARIABLE_V_SPEED = 2,
    FLOW_GLOBAL_VARIABLE_V_PERCENT_RPM = 3,
    FLOW_GLOBAL_VARIABLE_V_LAPTIME_PREDICT = 4,
    FLOW_GLOBAL_VARIABLE_V_LAPTIME_DELTA = 5,
    FLOW_GLOBAL_VARIABLE_V_LAPTIME_CURRENT = 6,
    FLOW_GLOBAL_VARIABLE_V_LAPS_COUNT = 7,
    FLOW_GLOBAL_VARIABLE_V_ABS_VALUE = 8,
    FLOW_GLOBAL_VARIABLE_V_TC_VALUE = 9
};

// Native global variables

extern const char *get_var_v_gear();
extern void set_var_v_gear(const char *value);
extern const char *get_var_v_rpm();
extern void set_var_v_rpm(const char *value);
extern const char *get_var_v_speed();
extern void set_var_v_speed(const char *value);
extern int32_t get_var_v_percent_rpm();
extern void set_var_v_percent_rpm(int32_t value);
extern const char *get_var_v_laptime_predict();
extern void set_var_v_laptime_predict(const char *value);
extern const char *get_var_v_laptime_delta();
extern void set_var_v_laptime_delta(const char *value);
extern const char *get_var_v_laptime_current();
extern void set_var_v_laptime_current(const char *value);
extern const char *get_var_v_laps_count();
extern void set_var_v_laps_count(const char *value);
extern const char *get_var_v_abs_value();
extern void set_var_v_abs_value(const char *value);
extern const char *get_var_v_tc_value();
extern void set_var_v_tc_value(const char *value);

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/