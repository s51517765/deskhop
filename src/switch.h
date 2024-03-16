#include "main.h"
#define PIN_SW 10
#define SPEED_CHG_RATE 1.4
#define MOUSE_SPEED_MAX 1024
#define MOUSE_SPEED_MIN 6
#define MOUSE_SPEED_REPORT_LENGTH 1

bool read_SW(uint8_t sw);
void update_mouse_speed(device_t *state);
void init_push_swicth();
