#include <rtc_helpers.h>

void setSystemTime(){
    //To set the system time from the on-board RTC chip

    struct tm time_info;
    m5::rtc_datetime_t dt = M5.Rtc.getDateTime();

    time_info.tm_hour = dt.time.hours;
    time_info.tm_min = dt.time.minutes;
    time_info.tm_sec = dt.time.seconds;
    time_info.tm_wday = dt.date.weekDay;
    time_info.tm_mon = dt.date.month - 1;
    time_info.tm_mday = dt.date.date;
    time_info.tm_year = dt.date.year - 1900;

    struct timeval tv;
    tv.tv_sec = mktime(&time_info);
    USBSerial.printf("Setting sys time to %02d:%02d:%02d\n", dt.time.hours, dt.time.minutes, dt.time.seconds);
    settimeofday(&tv, NULL);
}

void setRTC(time_t epoch_time, int UTC_offset_minutes){
    //To set the on-board RTC chip from time obtained by notecard
    struct tm *time_info;

    epoch_time += UTC_offset_minutes * 60;
    time_info = localtime(&epoch_time);
    
    M5.Rtc.setDateTime(time_info);

    //Delay To allow the RTC chip to update, can see errors of ~+18 mins without this
    vTaskDelay(1 / portTICK_PERIOD_MS);
    setSystemTime();
}


