#include "pca95571.h"
#include "driver/i2c_master.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
i2c_master_bus_handle_t pca9557_bus_handle = NULL;
i2c_master_dev_handle_t pca9557_dev_handle = NULL;

esp_err_t pca9557_init(gpio_num_t sda, gpio_num_t scl)
{
    i2c_master_bus_config_t bus_conf =
        {
            .sda_io_num = sda,
            .scl_io_num = scl,
            .clk_source = I2C_CLK_SRC_DEFAULT,
            .glitch_ignore_cnt = 7,
            .i2c_port=1
        };
    i2c_new_master_bus(&bus_conf, &pca9557_bus_handle);

    i2c_device_config_t device_conf =
        {
            .device_address = 0x19,
            .scl_speed_hz = 100000,
            .dev_addr_length = I2C_ADDR_BIT_7};

    return i2c_master_bus_add_device(pca9557_bus_handle, &device_conf, &pca9557_dev_handle);
}

esp_err_t pca9557_write(uint8_t address, uint8_t data)
{
    uint8_t write_buf[2];
    write_buf[0] = address;
    write_buf[1] = data;
    return i2c_master_transmit(pca9557_dev_handle, write_buf, 2, 500);
}

esp_err_t pca9557_read(uint8_t address, uint8_t *data)
{
    uint8_t temp[1];
    temp[0] = address;
    return i2c_master_transmit_receive(pca9557_dev_handle, temp, 1, data, 1, 500);
}

esp_err_t pca9557_configure(uint8_t config)
{
    esp_err_t ret;
    do
    {
        ret = pca9557_write(Configuration_register, config);
        vTaskDelay(pdMS_TO_TICKS(150));
    } while (ret != ESP_OK);

    return ESP_OK;
}

esp_err_t pca9557_read_io(uint8_t pin)
{
    uint8_t data = 0;
    pca9557_read(Input_port_registe, &data);
    return (pin & data) ? 1 : 0;
}

esp_err_t pca9557_write_io(uint8_t pin, uint8_t level)
{
    uint8_t data = 0;
    pca9557_read(Output_port_registe, &data);
    if (level)
    {
        data |= pin;
    }
    else
    {
        data &= ~pin;
    }
    return pca9557_write(Output_port_registe, data);
}