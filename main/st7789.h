#pragma once
#include "driver/gpio.h"
#include "esp_err.h"
#include "esp_check.h"
#include "driver/ledc.h"
#include "PCA9557.h"
#define BSP_LCD_SPI_NUM    SPI3_HOST

#define LCD_LEDC_CH          LEDC_CHANNEL_0

typedef void(*lcd_flush_done_cb)(void* param);
#define BSP_LCD_BITS_PER_PIXEL     (16)
#define BSP_LCD_H_RES              (320)
#define BSP_LCD_V_RES              (240)

typedef struct
{
    gpio_num_t  mosi;       //数据
    gpio_num_t  clk;        //时钟
    gpio_num_t  cs;         //片选
    gpio_num_t  dc;         //命令
    gpio_num_t  rst;        //复位
    gpio_num_t  bl;         //背光
    uint32_t    spi_fre;    //spi总线速率
    uint16_t    width;      //宽
    uint16_t    height;     //长
    uint8_t     spin;       //选择方向(0不旋转，1顺时针旋转90, 2旋转180，3顺时针旋转270)
    lcd_flush_done_cb   done_cb;    //数据传输完成回调函数
    void*       cb_param;   //回调函数参数
}st7789_cfg_t;
void lcd_init(void);
esp_err_t st7789_driver_hw_init(st7789_cfg_t* cfg);
esp_err_t bsp_display_brightness_set(int brightness_percent);
esp_err_t bsp_display_backlight_off(void);
esp_err_t bsp_display_backlight_on(void);
void lcd_set_color(uint16_t color);
void lcd_draw_pictrue(int x_start, int y_start, int x_end, int y_end, const unsigned char *gImage);