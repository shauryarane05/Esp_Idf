#include "oled.h"
#include "sra_board.h"

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else 
    #include "lvgl/lvgl.h"
#endif

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_DVD
#define LV_ATTRIBUTE_IMG_DVD
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_DVD uint8_t dvd_map[] = {
    0xd5, 0xd5, 0xd5, 0xff, 	/Color of index 0/
    0x11, 0x11, 0x11, 0xff, 	/Color of index 1/
 
    0xff, 0xff, 0xff, 0xff, 
    0xf5, 0x57, 0xea, 0xff, 
    0xf0, 0x03, 0xc0, 0x1f, 
    0xf0, 0x03, 0xc0, 0x0f, 
    0xf7, 0x81, 0x8b, 0x8f, 
    0xf3, 0xc1, 0x81, 0xcf, 
    0xe3, 0x88, 0x13, 0xcf, 
    0xf3, 0x08, 0x11, 0x8f, 
    0xe0, 0x1c, 0x30, 0x1f, 
    0xf0, 0x3e, 0x30, 0x3f, 
    0xff, 0xfe, 0x7f, 0xff, 
    0xff, 0xd4, 0x57, 0xff, 
    0xfc, 0x00, 0x00, 0x3f, 
    0xe0, 0x00, 0x00, 0x07, 
    0xc0, 0x07, 0xe0, 0x03, 
    0xc0, 0x07, 0xe0, 0x03, 
    0xf0, 0x00, 0x00, 0x0f, 
    0xfe, 0x80, 0x01, 0x7f, 
    
    0xff, 0xff, 0xff, 0xff, 
    0xff, 0xfe, 0xf7, 0xef, 
    0xed, 0xdd, 0x67, 0xd7, 
    0xf3, 0xdd, 0x6f, 0xd7, 
    0xeb, 0xdd, 0x67, 0xd7, 
    0xf7, 0xdd, 0x6f, 0xd7, 
    0xff, 0xfe, 0xf3, 0xef, 
    0xff, 0xff, 0xff, 0xff, 
};

const lv_img_dsc_t dvd = {
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .header.always_zero = 0,
    .header.reserved = 0,
    .header.w = 32,
    .header.h = 26,
    .data_size = 112,
    .data = dvd_map,
};

lv_obj_t *icon;          
void app_main() {
    int x=0,y=0,speed_x=2,speed_y=2;
    lv_init();              
    init_oled();            
    vTaskDelay(pdMS_TO_TICKS(100));  

    lv_obj_clean(lv_scr_act()); 

    icon = lv_img_create(lv_scr_act());  
    lv_img_set_src(icon, &dvd);         
    lv_obj_align(icon, LV_ALIGN_TOP_LEFT, x, y);  
    while (1) {
    x+=speed_x;
    y+=speed_y;
    if(x<0||x+32>128){
    speed_x=-speed_x;
    }
    if (y<0||y+26>64)
    {
        speed_y=-speed_y;       
    }
    lv_obj_align(icon,LV_ALIGN_TOP_LEFT,x,y);
    lv_refr_now(NULL);
    vTaskDelay(pdMS_TO_TICKS(10));
}
}