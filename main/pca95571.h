#ifndef _PCA95571_H_
#define _PCA95571_H_
#include <stdint.h>
#include <esp_err.h>
#include "driver/gpio.h"

#define PCA9557_ADDR  0x19  //I2C地址
#define sda_gpio    GPIO_NUM_1  //SDA引脚
#define scl_gpio    GPIO_NUM_2  //SCL引脚



#define IO0          (1<<0)
#define IO1          (1<<1)
#define IO2          (1<<2) 
#define IO3          (1<<3)
#define IO4          (1<<4)     
#define IO5          (1<<5)
#define IO6          (1<<6)
#define IO7          (1<<7)


#define Input_port_registe              0x00
#define Output_port_registe             0x01
#define Polarity_inversion_registe      0x02  //输入极性反转寄存器
#define Configuration_register          0x03

esp_err_t pca9557_init(gpio_num_t sda, gpio_num_t scl);
esp_err_t pca9557_write(uint8_t address, uint8_t data);
esp_err_t pca9557_read(uint8_t address, uint8_t *data);

esp_err_t pca9557_configure(uint8_t config);
esp_err_t pca9557_read_io(uint8_t pin);  
esp_err_t pca9557_write_io(uint8_t pin, uint8_t level);

#endif /* _PCA9557_H_ */