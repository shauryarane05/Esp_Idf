#include "blink.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>
void blink(void){
    gpio_reset_pin(GPIO_NUM_5);
    gpio_reset_pin(GPIO_NUM_4);
    gpio_set_direction(GPIO_NUM_4,GPIO_MODE_INPUT);
    gpio_set_direction(GPIO_NUM_5,GPIO_MODE_OUTPUT);
    gpio_set_pull_mode(GPIO_NUM_4,GPIO_PULLDOWN_ONLY);
    while (1)
    {   
        int level=gpio_get_level(GPIO_NUM_4);
        if(level==1){
            gpio_set_level(GPIO_NUM_5,1);
            printf("%d",level);
        }
        if(level==0){                                                                                   
            gpio_set_level(GPIO_NUM_5,0);
            printf("%d",level);

        }
    
    }
    

}