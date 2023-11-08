#include "rtos_tasks.h"

SemaphoreHandle_t nc_mutex = xSemaphoreCreateMutex();

void setupRtos(void){

    xTaskCreate(
        timeSyncNotecard, // task function
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
        serviceNotecard, // task function
        "Notecard Service", // task name
        16384, // stack size in bytes
        NULL, // pointer to parameters
        1, // priority
        NULL); // out pointer to task handle

#ifdef USE_GUI
    xTaskCreate(
        serviceGUI, // task function
        "LVGL GUI Service", // task name
        16384, // stack size in bytes
        NULL, // pointer to parameters
        1, // priority
        NULL); // out pointer to task handle
#endif

    xTaskCreate(
        readFlowMeters, // task function
        "Read Flow Meters", // task name
        1024, // stack size in bytes
        NULL, // pointer to parameters
        1, // priority
        NULL); // out pointer to task handle

    xTaskCreate(
        debugTask, // task function
        "Debug Task", // task name
        16384, // stack size in bytes
        NULL, // pointer to parameters
        1, // priority
        NULL); // out pointer to task handle

}

#ifdef USE_GUI
void serviceGUI(void * pvParameters){
    while(1){
        int delay_ms = lv_timer_handler();
        vTaskDelay(delay_ms / portTICK_PERIOD_MS);
    }
}
#endif

void runStateMachine(void * pvParameters){
    while(1){
        stateMachine.run();
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

void serviceNotecard(void * pvParameters){
    while(1){

        if (notecardManager.serviceEnabled){
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

            notecardManager.serviceTick = !notecardManager.serviceTick;
            xSemaphoreGive(nc_mutex);

            vTaskDelay(notecardManager.serviceInterval_s*1000 / portTICK_PERIOD_MS);
        }
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

void timeSyncNotecard(void * pvParameters){
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
    vTaskDelay(notecardManager.timeSyncInterval_s*1000 / portTICK_PERIOD_MS);
  }
}

void debugTask(void * pvParameters){
    while(1){
        // if (db_vars.enabled == true){
        //     compressorPID.Compute();
        //     set_compressor_speed(qo_vars.compressor_target_speed);
        // }
        USBSerial.printf("1 second debug print %d\n", millis());

        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    
}

void computePID(void * pvParameters){
    while(1){
        stateMachine.compressorPID.Compute();
        // vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}


void readFlowMeters(void *pvParameters)
{
    while (1)
    {
        stateMachine.inputs.serviceFlowMeters();
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}