#pragma once

#include <zephyr/kernel.h>
#include <zephyr/input/input.h>

// Ball action definitions
struct ball_event {
    uint32_t keycode;
    int32_t threshold;
    uint32_t direction;
};

struct ball_action_config {
    struct ball_event up;
    struct ball_event down;
    struct ball_event left;
    struct ball_event right;
    bool enabled;
};

// Simplified motion event structure
struct ball_motion_event {
    int16_t dx;
    int16_t dy;
};

typedef void (*ball_motion_callback_t)(const struct ball_motion_event *evt);

// Function declaration
void ball_motion_register_callback(ball_motion_callback_t callback);
