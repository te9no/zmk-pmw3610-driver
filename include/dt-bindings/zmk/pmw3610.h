#pragma once

#define BALL_ACTION(name, up_key, down_key, left_key, right_key) \
    ball_action_##name { \
        compatible = "zmk,behavior-ball-action"; \
        #binding-cells = <0>; \
        up-keycode = <up_key>; \
        down-keycode = <down_key>; \
        left-keycode = <left_key>; \
        right-keycode = <right_key>; \
    };
