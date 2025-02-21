## Running a Code for blinking LED from scratch in esp idf

STEP 1 MAKING A FOLDER WHICH IS COMPLIANT WITH THE ESPIDF AS IT USED CMAKE build system

- [CMake](https://cmake.org/), which configures the project to be built.
- [Ninja](https://ninja-build.org/), which builds the project.
- [esptool.py](https://github.com/espressif/esptool/#readme), which flashes the target.
1. we make a folder and run [`idf.py](http://idf.py) create-project test`

as a project shld look like this

```markdown
/ESPIDF_Project/
│-- CMakeLists.txt         <-- Main CMake file for the project
│-- sdkconfig              <-- Configuration file (auto-generated)
│-- /build/                <-- Compiled output files (created after build)
│-- /components/           <-- Optional custom components
│-- /main/                 <-- Contains your application code
│   │-- CMakeLists.txt     <-- CMake file for the main application
│   │-- blink.c            <-- Your LED blink code
│-- /idf.py                <-- ESP-IDF build system script
│-- /flash_project.sh      <-- Script to flash project (optional)

```

1. we write our code in the main file
2. pull up means the pin is by default high
3. pull down means the pin is by default low

## how to write led blink

1. [idf.py](http://idf.py) create-project name
2. in the main folder make files accding to your needs
3. we needed blink.c blink.h and main.c
4. in blink.c

```c
#include"driver/gpio.h"
#include"freertos/task.h"
#include"freertos/FreeRTOS.h"
#include "blink.h"
void blink(void){
gpio_reset_pin(GPIO_NUM_5);//GPIO_NUM5 IS IN GPIO.H ENUM
gpio_set_direction_pin(GPIO_NUM_5,GPIO_MODE_OUTPUT);
while(1){
gpio_set_level(GPIO_NUM_5,1);
VTaskDelay(PdMS_TO_TICKS(1000));
gpio_set_level(GPIO_NUM_5,0);
VTaskDelay(PdMS_TO_TICKS(1000));
}

}

```

THEREFORE FUNCTION TO REMEBER\

- gpio_reset_pin(GPIO_NUM_5);//GPIO_NUM5 IS IN GPIO.H ENUM
- gpio_set_direction_pin(GPIO_NUM_5,GPIO_MODE_OUTPUT);
- gpio_set_level(GPIO_NUM_5,1);
- VTaskDelay(PdMS_TO_TICKS(1000));
1. IN BLINK.H

```c
#ifndef BLINK_H
#define BLINK_H
void blink(void);
#endif

```

1. in main.c

```c
#include "blink.h"
void app_main(void){
blink();
}
```

7 in make file

```c
idf_component_register(SRCS "main.c" "blink.c"
												INCLUDE_DIRS "." )
```
add button documentation and code then next time look into interrupts and adc

## TAKE INPUT SENSOR VALUES
