#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "st7789.h"
#include "PCA9557.h"
//#include "yingwu.h"
#include "fei.h"
void app_main(void)
{
    bsp_i2c_init();
    pca9557_init(); 
    lcd_init();
    lcd_set_color(0x11FF); 
    bsp_display_brightness_set(100);
    lcd_draw_pictrue(0, 0, 320, 240, gImage_fei); 
}

