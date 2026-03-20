#ifndef KEYMAP_H
#define KEYMAP_H

#include <stdint.h>


enum SpecialKey {
  SPECIAL_NONE,
  SPECIAL_CHANGE_STATE,
  SPECIAL_HENKAN,
  SPECIAL_KAKUTEI,
  SPECIAL_SAKUJO
};

enum STATE {
  HIRAGANA,
  ROMAJI,
  NUMBER
}

static constexpr const char* KEY_CHANGE_STATE = "CHANGE_STATE";
static constexpr const char* KEY_HENKAN       = "HENKAN";
static constexpr const char* KEY_KAKUTEI      = "KAKUTEI";
static constexpr const char* KEY_SAKUJO       = "SAKUJO";

const char *keymap_get_romaji(uint8_t key_col, FlickDirection direction);

#endif
