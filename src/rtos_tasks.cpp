#include "rtos_tasks.h"

SemaphoreHandle_t nc_mutex = xSemaphoreCreateMutex();


void setup_rtos_tasks(void){

    xTaskCreate(
        notecard_time_sync, // task function
        "Notecard Time Sync", // task name
        32768, // stack size in bytes
        NULL, // pointer to parameters
        1, // priority
        NULL); // out pointer to task handle


    xTaskCreate(
        computePID, // task function
        "Compute PID ", // task name
        16384, // stack size in bytes
        NULL, // pointer to parameters
        1, // priority
        NULL); // out pointer to task handle

    xTaskCreate(
        runStateMachine, // task function
        "State Machine", // task name
        16384, // stack size in bytes
        NULL, // pointer to parameters
        1, // priority
        NULL); // out pointer to task handle

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

    xTaskCreate(
        read_pulses, // task function
        "Read Pulses", // task name
        1024, // stack size in bytes
        NULL, // pointer to parameters
        1, // priority
        NULL); // out pointer to task handle
}

void gui_service(void * pvParameters){
    while(1){
        int delay_ms = lv_timer_handler();
        vTaskDelay(delay_ms / portTICK_PERIOD_MS);
    }
}

void runStateMachine(void * pvParameters){
    while(1){
        stateMachine.run();
        vTaskDelay(100 / portTICK_PERIOD_MS);
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
        serialDisplay.printf("1 second debug print %d\n", millis());

        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    
}

void computePID(void * pvParameters){
    while(1){
        stateMachine.compressorPID.Compute();
        // vTaskDelay(100 / portTICK_PERIOD_MS);
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