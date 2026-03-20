#ifndef CONFIG_H
#define CONFIG_H

#include <cstdint>

constexpr uint8_t DIRECTIONS = 5;
constexpr uint8_t ROWS = 6;
constexpr uint8_t COLS = 3;
constexpr uint8_t STATES = 3;
constexpr uint8_t OUTPUTS = 5;

constexpr uint8_t DIR_UP    = 1;
constexpr uint8_t DIR_DOWN  = 2;
constexpr uint8_t DIR_LEFT  = 3;
constexpr uint8_t DIR_RIGHT = 4;

constexpr uint8_t LED = 6;
constexpr uint8_t VERT_PIN = A6;
constexpr uint8_t HORZ_PIN = A7;
constexpr uint8_t rowPins[ROWS] = {13, 14, 15, 16, 17, 18};
constexpr uint8_t colPins[COLS] = {12, 11, 10};

constexpr int BPS = 115200;

#endif
