# NI-watch

NI-watch is an embedded watch project based on the STM32F0 MCU family. The firmware is designed for a custom hardware platform with RTC support, button input, LED feedback, alarm management, and UART-based debug logging.

## Project Structure

A compact overview of the main repository layout:

```text
NI-watch/
├── hardware/
│   ├── doc/
│   └── zegarek/
├── README.md
└── software/
    └── TheWatch/
        ├── Core/
        │   ├── Inc/
        │   │   ├── bsp/
        │   │   ├── logger/
        │   │   └── Manager/
        │   └── Src/
        ├── Debug/
        ├── Drivers/
        ├── STM32F091RCTX_FLASH.ld
        ├── TheWatch Debug.launch
        └── TheWatch.ioc
```

The main firmware path is `software/TheWatch/Core/`, where the primary application, peripheral drivers, and helpers are located.

## Features

- 24-hour RTC operation using the on-chip RTC peripheral
- Alarm support using RTC Alarm A
- Button press detection with short press and long press events
- LED toggling for user feedback and heartbeat status
- UART logging for debug and runtime information

## User Interaction

### Buttons

- Blue button (configured on GPIOC pin 13)
  - Short press: read current RTC time and print it to the logger
  - Long press: set the RTC alarm to one minute ahead of the current time and log the alarm value
- Additional buttons on GPIOA and GPIOB toggle onboard LEDs for quick manual feedback

### LEDs

- LEDs connected to `GPIO_LED0`, `GPIO_LED1`, and `GPIO_LED2` toggle when their respective buttons are pressed
- `LD2` is toggled periodically by a non-blocking timer to provide a simple heartbeat indicator

## RTC and Alarm Behavior

- RTC is initialized with default time and date values
- Alarm A is enabled at startup and can be updated by user input
- Alarm behavior and interrupt handling are logged through the UART debug logger

## Debugging and Logging

- Logging is implemented through `logger/logger.h` and `logger/logger.c`
- Log levels include `INFO`, `WARN`, `ERROR`, and `DEBUG`
- The firmware prints time reads, alarm configuration, button events, and interrupt notices

## Build Notes

- The firmware is built using STM32Cube-generated HAL code and project files
- The target MCU is an STM32F091RCTX device
- `software/TheWatch/STM32F091RCTX_FLASH.ld` contains the linker script for flash layout

## Notes

This README describes the current firmware behavior as implemented in the provided source files. The project is a work in progress and can be extended with additional watch features such as display output, time setting via buttons, battery management, and advanced alarm scheduling.
