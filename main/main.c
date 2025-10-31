#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "st7789.h"
#include "PCA9557.h"
#include "camera.h"
#include "fei.h"
#include "esp_camera.h"

void app_main(void)
{
    bsp_i2c_init();
    pca9557_init(); 
    lcd_init();
    bsp_display_brightness_set(100);
    lcd_draw_pictrue(0, 0, 320, 240, gImage_fei); 
    vTaskDelay(1000);
    app_camera_lcd();
}

