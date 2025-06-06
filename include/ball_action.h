#pragma once

#include <zephyr/input/input.h>
#include <zmk/event_manager.h>

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
};

// Ball event data structure
struct ball_motion_event {
    struct zmk_event_header header;
    int16_t dx;
    int16_t dy;
};

ZMK_EVENT_DECLARE(ball_motion_event);
