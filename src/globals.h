#ifndef GLOBALS_H
#define GLOBALS_H



// INTERNAL VARIABLES
// static bool relay_defaults[16];
// static bool relays[16];


// DATABASE VARIABLES
// These can be changed either on the device (e.g. GUI) or via the Notecard
// typedef struct {
//   float dhw_setpoint = 25.0;
//   bool enabled = true;
//   bool manual_mode = false;
//   int mode = 1;
//   int poll_interval_ms = 2000;
//   int nc_time_sync_interval_s = 10;
//   int nc_info_interval_s = 5;
//   int pid_info_interval_s = 2;
//   int thr_flex = 0;
//   float comp_speed_manual = 20.0;

// } db_variables_t;

// QUEUE OUT VARIABLES
// These are only changed on the device and published via the Notecard
// typedef struct{
//   float tc[8] = {0,0,0,0,0,0,0,0};
//   float t_ambient = 0;
//   float tw_dhw = 0;
//   float tr_comp_in = 0;
//   float tr_comp_out = 0;
//   float tr_cond_out = 0;
//   float tr_flex = 0;
//   float tw_flex = 0;
//   float pr_comp_in = 0;
//   float pr_comp_out = 0;
//   time_t last_poll_time = 0;
//   float compressor_target_speed = 50.0;
//   float compressor_read_speed = 50.0;
//   float fan_speed = 50.0;
//   int water_flow_pps = 0.0;
//   float water_flow_lpm = 0.0;
// } qo_variables_t;

// ENVIRONMENT VARIABLES
// These are changed remotely and updated via the notecard
// typedef struct {
//     char serial_number[32];
//     float kp = 20.0;
//     float ki = 1.0;
//     float kd = 0.0;
//     float defrost_thr_ambient = 5.0;
//     float comp_speed_transition = 20.0;
//     float comp_speed_max = 100.0;
//     float comp_speed_min = 0.0;
//     float fan_speed_max = 100.0;
//     float fan_speed_min = 0.0;
//     float pump_speed_max = 100.0;
//     float pump_speed_min = 0.0;
//     float tw_flex_min = 20.0;
//     float tw_flex_max = 40.0;
// } env_variables_t;

// extern db_variables_t db_vars;
// extern qo_variables_t qo_vars;
// extern env_variables_t env_vars;



#endif