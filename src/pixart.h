#pragma once

/**
 * @file pixart.h
 *
 * @brief Common header file for all optical motion sensor by PIXART
 */

#include <zephyr/device.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/sensor.h>

#ifdef __cplusplus
extern "C" {
#endif

enum pixart_input_mode { MOVE = 0, SCROLL, SNIPE, BALL_ACTION };


/* device data structure */
struct pixart_data {
    const struct device          *dev;
    bool                         sw_smart_flag; // for pmw3610 smart algorithm

    struct gpio_callback         irq_gpio_cb; // motion pin irq callback
    struct k_work                trigger_work; // realtrigger job

    struct k_work_delayable      init_work; // the work structure for delayable init steps
    int                          async_init_step;

    bool                         ready; // whether init is finished successfully
    int                          err; // error code during async init
    
    int32_t ball_action_delta_x;
    int32_t ball_action_delta_y;
    enum pixart_input_mode      input_mode;
    bool                        input_mode_changed;

};

struct ball_action_cfg {
    size_t bindings_len;
    struct zmk_behavior_binding *bindings;
    uint8_t layers[ZMK_KEYMAP_LAYERS_LEN];
    size_t layers_len;
    uint32_t tick;
    uint32_t wait_ms;
    uint32_t tap_ms;
};

// device config data structure
struct pixart_config {
	struct spi_dt_spec spi;
    struct gpio_dt_spec irq_gpio;
    uint16_t cpi;
    uint8_t evt_type;
    uint8_t x_input_code;
    uint8_t y_input_code;
    bool force_awake;
    
    uint8_t *scroll_layers;
    size_t scroll_layers_len;
    uint8_t *snipe_layers;
    size_t snipe_layers_len;
    
    struct ball_action_cfg **ball_actions;
    size_t ball_actions_len;
};

#ifdef __cplusplus
}
#endif

/**
 * @}
 */
