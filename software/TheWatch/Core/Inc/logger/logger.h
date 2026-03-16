/*
 * logger.h
 *
 *  Created on: Feb 11, 2026
 *      Author: kwojcik
 */

#ifndef INC_LOGGER_LOGGER_H_
#define INC_LOGGER_LOGGER_H_

#include <stdio.h>

#define COLOR_RESET  "\x1b[0m"
#define COLOR_INFO   "\x1b[32m"  // zielony
#define COLOR_WARN   "\x1b[33m"  // żółty
#define COLOR_ERROR  "\x1b[31m"  // czerwony
#define COLOR_DEBUG "\x1b[36m"  // niebieski

static const char *level_str[] = {
    COLOR_INFO  "INFO"  COLOR_RESET,
    COLOR_WARN  "WARN"  COLOR_RESET,
    COLOR_ERROR "ERROR" COLOR_RESET,
    COLOR_DEBUG "DEBUG" COLOR_RESET
};

typedef enum {
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
    LOG_DEBUG
} log_level_t;

void log_printf(log_level_t level, const char *fmt, ...);
void Logger_Init(void);
void get_time(char *buf, size_t len);

#endif /* INC_LOGGER_LOGGER_H_ */
