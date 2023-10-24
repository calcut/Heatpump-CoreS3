#include "rtos_tasks.h"

SemaphoreHandle_t nc_mutex = xSemaphoreCreateMutex();
int previous_mode = STANDBY;

TaskHandle_t TaskHandle_Control;



void setup_rtos_tasks(void){

    // xTaskCreate(
    //     poll, // task function
    //     "Poll Yotta Module", // task name
    //     16384, // stack size in bytes
    //     NULL, // pointer to parameters
    //     1, // priority
    //     NULL); // out pointer to task handle

    xTaskCreate(
        notecard_time_sync, // task function
        "Notecard Time Sync", // task name
        32768, // stack size in bytes
        NULL, // pointer to parameters
        1, // priority
        NULL); // out pointer to task handle


    xTaskCreate(
        control, // task function
        "PID Control", // task name
        16384, // stack size in bytes
        NULL, // pointer to parameters
        1, // priority
        &TaskHandle_Control); // out pointer to task handle

    // xTaskCreate(
    //     state_machine, // task function
    //     "State Machine", // task name
    //     16384, // stack size in bytes
    //     NULL, // pointer to parameters
    //     1, // priority
    //     NULL); // out pointer to task handle

    xTaskCreate(
        notecard_service, // task function
        "Notecard Service", // task name
        16384, // stack size in bytes
        NULL, // pointer to parameters
        1, // priority
        NULL); // out pointer to task handle

    xTaskCreate(
        gui_service, // task function
        "LVGL GUI Service", // task name
        16384, // stack size in bytes
        NULL, // pointer to parameters
        1, // priority
        NULL); // out pointer to task handle

    // xTaskCreate(
    //     read_pulses, // task function
    //     "Read Pulses", // task name
    //     1024, // stack size in bytes
    //     NULL, // pointer to parameters
    //     1, // priority
    //     NULL); // out pointer to task handle
}

void gui_service(void * pvParameters){
    while(1){
        int delay_ms = lv_timer_handler();
        vTaskDelay(delay_ms / portTICK_PERIOD_MS);
    }
}

void notecard_service(void * pvParameters){
    while(1){

        if (nc_service_enable){
            USBSerial.printf("Notecard info service\n");
            xSemaphoreTake(nc_mutex, portMAX_DELAY);
            notecardManager.hubGet();
            vTaskDelay(10 / portTICK_PERIOD_MS);
            notecardManager.cardStatus();
            vTaskDelay(10 / portTICK_PERIOD_MS);
            notecardManager.getEnvironment();
            vTaskDelay(10 / portTICK_PERIOD_MS);
            notecardManager.hubStatus();
            vTaskDelay(10 / portTICK_PERIOD_MS);
            notecardManager.hubSyncStatus();
            vTaskDelay(10 / portTICK_PERIOD_MS);
            notecardManager.cardWireless();
            vTaskDelay(10 / portTICK_PERIOD_MS);

            nc_service_tick = !nc_service_tick;
            xSemaphoreGive(nc_mutex);

            vTaskDelay(db_vars.nc_info_interval_s*1000 / portTICK_PERIOD_MS);
        }
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

void notecard_time_sync(void * pvParameters){
  while(1) {
    xSemaphoreTake(nc_mutex, portMAX_DELAY);
    notecardManager.cardStatus();

    if(notecardManager.connected){
        USBSerial.printf("Notecard time sync\n");

        notecardManager.getTime();
        setRTC(notecardManager.epoch_time, notecardManager.utc_offset_minutes);
    }
    else{
        USBSerial.printf("Notecard not connected, skipping time sync\n");
    }
    xSemaphoreGive(nc_mutex);
    vTaskDelay(db_vars.nc_time_sync_interval_s*1000 / portTICK_PERIOD_MS);
  }
}

void control(void * pvParameters){
    while(1){
        // if (db_vars.enabled == true){
        //     compressorPID.Compute();
        //     set_compressor_speed(qo_vars.compressor_target_speed);
        // }
        // USBSerial.printf("1 second debug print\n");


        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    
}

bool check_limits(){
    // Check if the compressor speed is within limits etc
    return true;
}


void standby_mode(void){
    if (previous_mode != STANDBY){
        USBSerial.printf("Entering standby mode\n");
        vTaskSuspend(TaskHandle_Control);
        set_compressor_speed(0); 
        open_evaporator_valve();
        close_defrost_valve();
        set_reversing_valve_forward();
    }
}

void discharging_mode(void){
    if (previous_mode != DISCHARGING){
        USBSerial.printf("Entering discharging mode\n");
        vTaskSuspend(TaskHandle_Control);
        set_compressor_speed(env_vars.comp_speed_transition); 
        close_evaporator_valve();
        close_defrost_valve();
        set_reversing_valve_reverse();
        vTaskResume(TaskHandle_Control);
    }
}

void charging_mode(void){
    if (previous_mode != CHARGING){
        USBSerial.printf("Entering charging mode\n");
        vTaskSuspend(TaskHandle_Control);
        set_compressor_speed(env_vars.comp_speed_transition); 
        open_evaporator_valve();
        close_defrost_valve();
        set_reversing_valve_forward();
        vTaskResume(TaskHandle_Control);
    }
}

void defrost_mode(void){
    if (previous_mode != DEFROST){
        USBSerial.printf("Entering defrost mode\n");
        vTaskSuspend(TaskHandle_Control);
        set_compressor_speed(env_vars.comp_speed_transition); 
        open_evaporator_valve();
        open_defrost_valve();
        set_reversing_valve_reverse();
        vTaskResume(TaskHandle_Control);


        // Start defrost Timer here
    }
}

void open_evaporator_valve(void){
    USBSerial.println("Evaporator valve opened");
}

void close_evaporator_valve(void){
    USBSerial.println("Evaporator valve closed");
}

void open_defrost_valve(void){
    USBSerial.println("Defrost valve opened");
}

void close_defrost_valve(void){
    USBSerial.println("Defrost valve closed");
}

void set_reversing_valve_forward(void){
    USBSerial.println("Reversing valve set to forward");
}

void set_reversing_valve_reverse(void){
    USBSerial.println("Reversing valve set to reverse");
}

void set_compressor_speed(float percent){
    USBSerial.printf("Setting compressor speed: %d%%\n", percent);
} 

void set_fan_speed(float percent){
    USBSerial.printf("Setting fan speed: %d%%\n", percent);
}


void state_machine(void * pvParameters){
    while(1){
        vTaskDelay(100 / portTICK_PERIOD_MS);

        previous_mode = db_vars.mode;

        if(db_vars.enabled == false){
            db_vars.mode = STANDBY;
            continue;
        }

        if(check_limits() == false){
            // Add logging or error handling
            db_vars.enabled = false;
            db_vars.mode = ERROR;
            continue;
        }

        if(qo_vars.tw_dhw > db_vars.dhw_setpoint){
            //DHW is above setpoint, no heating requested
            db_vars.mode = STANDBY;
            continue;
        }

        if(db_vars.mode == DEFROST){
            //This means a defrost timer is still running
            defrost_mode();
            continue;
        }

        if(qo_vars.t_ambient < env_vars.defrost_thr_ambient){
            //Ambient temperature is below defrost threshold
            db_vars.mode = DEFROST;
            defrost_mode();
            continue;
        }

        if(qo_vars.tw_flex > db_vars.thr_flex){
            //Flex store is above threshold
            db_vars.mode = DISCHARGING;
            discharging_mode();
            continue;
        }
        if(qo_vars.tw_flex < db_vars.thr_flex){
            //Flex store is below threshold
            db_vars.mode = CHARGING;
            charging_mode();
            continue;
        }
    }
}

void poll(void * pvParameters){
    while(1){
        USBSerial.printf("Polling at %d ms\n", db_vars.poll_interval_ms);
        yottaModule.readTC_float(qo_vars.tc);
        time_t now;
        time(&now);
        qo_vars.last_poll_time = now;
        vTaskDelay(db_vars.poll_interval_ms / portTICK_PERIOD_MS);
    }
    
}

void read_pulses(void *pvParameters)
{
    (void)pvParameters;

    pcnt_config_t pcntCh1 = {
        .pulse_gpio_num = PIN_PULSE_COUNT,
        .ctrl_gpio_num = PCNT_PIN_NOT_USED,
        .lctrl_mode = PCNT_MODE_KEEP,
        .hctrl_mode = PCNT_MODE_KEEP,
        .pos_mode = PCNT_COUNT_DIS,
        .neg_mode = PCNT_COUNT_INC,
        .counter_h_lim = 32767,
        .counter_l_lim = -32768,
        .unit = PCNT_UNIT_0,
        .channel = PCNT_CHANNEL_0,
    };
    pcnt_unit_config(&pcntCh1);
    pcnt_counter_clear(PCNT_UNIT_0);

    static int previous_pulse_count = 0;
    static int previous_pulse_time = 0;
    int16_t counterVal;

    while (true) {

        pcnt_get_counter_value(PCNT_UNIT_0, &counterVal);

        if (millis() - previous_pulse_time != 0){
            qo_vars.water_flow_pps = ((counterVal - previous_pulse_count)*1000)/(millis() - previous_pulse_time);
            qo_vars.water_flow_lpm = qo_vars.water_flow_pps * 60 / 4600; //4600 pulses per litre
        }

        previous_pulse_count = counterVal;
        previous_pulse_time = millis();

        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}