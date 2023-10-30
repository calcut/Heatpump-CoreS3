#include "globals.h"

char log_display_buffer[TERMINAL_LOG_LENGTH + 1];

size_t SerialDisplay::write(const uint8_t *buffer, size_t size){

    // This intercepts SerialDisplay.print() and similar.
    // It captures the text and appends it to the end of a log buffer for display on the screen

    char *txt_in = (char*)buffer;
    uint16_t txt_len = strlen(txt_in);
    uint16_t old_len = strlen(log_display_buffer); 

    //Append the new text to the end of the log, deleting the oldest text if necessary
    if (old_len + txt_len > TERMINAL_LOG_LENGTH){
        //If the new text is longer than the log, then delete the oldest text
        uint16_t new_start = old_len - (TERMINAL_LOG_LENGTH - txt_len);
        uint16_t new_len = old_len - new_start;
        memcpy(log_display_buffer, &log_display_buffer[new_start], new_len);
        memcpy(&log_display_buffer[new_len], txt_in, txt_len);

        log_display_buffer[new_len+txt_len] = '\0';
    }
    else{
        //If the new text is shorter than the log, then append it to the end
        memcpy(&log_display_buffer[old_len], txt_in, txt_len);
        log_display_buffer[old_len + txt_len] = '\0';
    }

    return HWCDC::write(buffer, size);
}
SerialDisplay serialDisplay;