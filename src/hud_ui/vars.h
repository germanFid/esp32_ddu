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
    FLOW_GLOBAL_VARIABLE_V_PERCENT_RPM = 3
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

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/