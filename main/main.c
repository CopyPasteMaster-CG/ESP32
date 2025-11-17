#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "st7789.h"
#include "PCA95571.h"
#include "fei.h"


void app_main(void)
{
    bsp_i2c_init();
    ESP_ERROR_CHECK(pca9557_init(sda_gpio, scl_gpio));
    ESP_ERROR_CHECK(pca9557_configure(0x00));
    
    lcd_init();
    bsp_display_brightness_set(100);
    lcd_draw_pictrue(0, 0, 320, 240, gImage_fei); 
    while(1)
    {
        
        
    }
   
}

