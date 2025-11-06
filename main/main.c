#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "pca9557.h"

void app_main(void)
{
    ESP_ERROR_CHECK(pca9557_init(sda_gpio, scl_gpio));
    ESP_ERROR_CHECK(pca9557_configure(0x00)); //配置为输出模式

    while (1)
    {
        ESP_ERROR_CHECK(pca9557_write_io(IO0, 1)); //设置IO0高电平
        vTaskDelay(pdMS_TO_TICKS(500));
        ESP_ERROR_CHECK(pca9557_write_io(IO0, 0)); //设置IO0低电平
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
