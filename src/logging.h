#pragma once

#include "pch.h"

void log(int messageType, const char* text, va_list args)
{
    char timeStr[64] = {0};

    time_t now = time(&now);

    struct tm *tm_info = localtime(&now);

    switch(messageType)
    {
        case LOG_INFO: printf("[INFO]: "); break;
        case LOG_ERROR: printf("[ERROR]: "); break;
        case LOG_WARNING: printf("[WARN] : "); break;
        case LOG_DEBUG: printf("[DEBUG]: "); break;
        default: break;
    }

    vprintf(text, args);
    printf("\n");
}