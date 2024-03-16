#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "main.h"
#include "switch.h"

bool BisLinux = true;

void init_push_swicth()
{
    gpio_init(PIN_SW);
    gpio_set_dir(PIN_SW, 0);
    gpio_pull_up(PIN_SW);
}

void update_mouse_speed(device_t *state)
{
#if BOARD_ROLE == PICO_B
    // state->active_output どちらのPCか？
    output_t *current = &state->config.output[PICO_B];

    // 状態を反転
    BisLinux = !BisLinux;

    if (BisLinux)
    {
        current->speed_x = MOUSE_SPEED_B_FACTOR_X;
        current->speed_y = MOUSE_SPEED_B_FACTOR_Y;
    }
    else
    {
        current->speed_x = MOUSE_SPEED_A_FACTOR_X;
        current->speed_y = MOUSE_SPEED_A_FACTOR_Y;
    }
#endif
}

bool read_SW(uint8_t sw)
{
    // if push swich is pushed
    if (!gpio_get(sw))
    {
        while (!gpio_get(sw))
        {
            // wait for release
        }
        return 1;
    }
    return 0;
}