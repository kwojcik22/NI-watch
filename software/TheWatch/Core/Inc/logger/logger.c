/*
 * logger.c
 *
 *  Created on: Feb 11, 2026
 *      Author: kwojcik
 */
#include <logger/logger.h>
//#include "cmsis_os2.h"
#include <stdarg.h>
//#include "FreeRTOS.h"
//#include "task.h"
#include <inttypes.h>
#include "stm32f0xx_hal.h"

//osMutexId_t loggerMutex;

/**
 * @brief logger module initialization
 */
//void Logger_Init(void)
//{
//    loggerMutex = osMutexNew(NULL);
//};

/**
 * @brief Send formatted log message via UART.
 *
 * Thread-safe (uses mutex).
 *
 * @param level Log level
 * @param fmt   printf-style format string
 * @note ex. usage: log_printf(LOG_INFO,"Default task start");
 */
void log_printf(log_level_t level, const char *fmt, ...)
{
    va_list args;

    //osMutexAcquire(loggerMutex, osWaitForever);

char timestamp[9];
    get_time(timestamp, sizeof(timestamp));

    printf("[%s]  [%s] - ", timestamp, level_str[level]);

    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);

    printf("\r\n");
    //osMutexRelease(loggerMutex);
};

/**
 * @brief convert xTaskGetTickCount to hh:mm:ss string format
 *
 * @param buf output buffer hh:mm:ss
 * @param len buf length
 */
void get_time(char *buf, size_t len)
{
	uint32_t ms = HAL_GetTick();
    uint32_t total_sec = ms / 1000;
    uint32_t h = total_sec / 3600;
    uint32_t m = (total_sec % 3600) / 60;
    uint32_t s = total_sec % 60;

    snprintf(buf, len, "%02lu:%02lu:%02lu", h, m, s);
}

