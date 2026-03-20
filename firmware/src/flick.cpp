#include <cstdint>
#include <string.h>

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include "flick.h"
#include "config.h"


static constexpr int JOYSTICK_LOW_THRESHOLD  = 300;
static constexpr int JOYSTICK_HIGH_THRESHOLD = 700;

typedef struct {
    FlickDirection direction;
    uint32_t       press_time_ms;
} KeyFlickState;

static KeyFlickState key_state;

void flickInit(void) {
    key_state.direction = FLICK_DIR_NONE;
    key_state.press_time_ms = 0;
}

static FlickDirection detectDirection() {
    int vert = analogRead(VERT_PIN);
    int horz = analogRead(HORZ_PIN);
    if (vert < JOYSTICK_LOW_THRESHOLD)  return FLICK_DIR_DOWN;
    if (vert > JOYSTICK_HIGH_THRESHOLD) return FLICK_DIR_UP;
    if (horz < JPYSTICK_LOW_THRESHOLD)  return FLICK_DIR_LEFT;
    if (vert > JOYSTICK_HIGH_THRESHOLD) return FLICK_DIR_RIGHT;
    return FLICK_DIR_NONE;
}

void flickProcess() {
    FlickDirection direction = detectDirection();
    if (direction != FLICK_DIR_NONE) {
        key_state.direction = direction;
        key_state.press_time_ms = to_ms_since_boot(get_absolute_time()); 
    }
}
