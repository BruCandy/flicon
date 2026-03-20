#include "keymap.h"
#include "config.h"


static constexpr char* keymap[ROWS][COLS][STATES][OUTPUTS] = {
    {
        {
            {"", "", "", "", ""},
            {"", "", "", "", ""},
            {"", "", "", "", ""}
        },
        {
            {KEY_CHANGE_STATE, KEY_CHANGE_STATE, KEY_CHANGE_STATE, KEY_CHANGE_STATE, KEY_CHANGE_STATE},
            {KEY_CHANGE_STATE, KEY_CHANGE_STATE, KEY_CHANGE_STATE, KEY_CHANGE_STATE, KEY_CHANGE_STATE},
            {KEY_CHANGE_STATE, KEY_CHANGE_STATE, KEY_CHANGE_STATE, KEY_CHANGE_STATE, KEY_CHANGE_STATE},
        },
        {
            {KEY_HENKAN, KEY_HENKAN, KEY_HENKAN, KEY_HENKAN, KEY_HENKAN},
            {KEY_HENKAN, KEY_HENKAN, KEY_HENKAN, KEY_HENKAN, KEY_HENKAN},
            {KEY_HENKAN, KEY_HENKAN, KEY_HENKAN, KEY_HENKAN, KEY_HENKAN},
        }
    },

    {
        {
            {" ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " "}
        },
        {
            {KEY_KAKUTEI, KEY_KAKUTEI, KEY_KAKUTEI, KEY_KAKUTEI, KEY_KAKUTEI},
            {KEY_KAKUTEI, KEY_KAKUTEI, KEY_KAKUTEI, KEY_KAKUTEI, KEY_KAKUTEI},
            {KEY_KAKUTEI, KEY_KAKUTEI, KEY_KAKUTEI, KEY_KAKUTEI, KEY_KAKUTEI},
        },
        {
            {KEY_SAKUJO, KEY_SAKUJO, KEY_SAKUJO, KEY_SAKUJO, KEY_SAKUJO},
            {KEY_SAKUJO, KEY_SAKUJO, KEY_SAKUJO, KEY_SAKUJO, KEY_SAKUJO},
            {KEY_SAKUJO, KEY_SAKUJO, KEY_SAKUJO, KEY_SAKUJO, KEY_SAKUJO},
        },
    },

    {
        {
            {"a", "i", "u", "e", "o"}, 
            {"@", "#", "/", "&", "_"},
            {"1", "", "", "", ""}
        },
        {
            {"ka", "ki", "ku", "ke", "ko"},
            {"a", "b", "c", "", ""},
            {"2", "", "", "", ""}
        },
        {
            {"sa", "shi", "su", "se", "so"},
            {"d", "e", "f", "", ""},
            {"3", "", "", "", ""}
        }
    },

    {
        {
            {"ta", "chi", "tsu", "te", "to"},
            {"g", "h", "i", "", ""},
            {"4", "", "", "", ""}
        },
        {
            {"na", "ni", "nu", "ne", "no"},
            {"j", "k", "l", "", ""},
            {"5", "", "", "", ""}
        },
        {
            {"", "", "", "", ""},
            {"", "", "", "", ""},
            {"", "", "", "", ""}
        }
    },

    {
        {
            {"ha", "hi", "fu", "he", "ho"},
            {"m", "n", "o", "", ""},
            {"6", "", "", "", ""}
        },
        {
            {"ma", "mi",  "mu",  "me",  "mo" },
            {"p", "q", "r", "s", ""},
            {"7", "", "", "", ""}
        },
        {
            {"ya", "lya", "yu",  "lye", "yo" },
            {"t", "u", "v", "", ""},
            {"8", "", "", "", ""}
        }
    },

    {
        {
            {"ltu", "la", "li", "lu", "le"},
            {"", "", "", "", ""},
            {"(", ")", "[", "]", ""}
        },
        {
            {"ra", "ri", "ru", "re", "ro"},
            {"w", "x", "y", "z", ""},
            {"9", "", "", "", ""}
        },
        {
            { "wa", "wi",  "nn",  "we",  "wo" },
            {"", "", "(", ")", ""},
            {"0", "", "", "", ""}
        }
    }
};

static STATE state;

SpecialKey toSpecialKey(const char* s) {
  if (strcmp(s, KEY_CHANGE_STATE) == 0) return SPECIAL_CHANGE_STATE;
  if (strcmp(s, KEY_HENKAN) == 0)       return SPECIAL_HENKAN;
  if (strcmp(s, KEY_KAKUTEI) == 0)      return SPECIAL_KAKUTEI;
  if (strcmp(s, KEY_SAKUJO) == 0)       return SPECIAL_SAKUJO;
  return SPECIAL_NONE;
}

const char *keymap_get_romaji(uint8_t row, uint8_t col, FlickDirection direction) {
    return keymap[row][col][state][direction];
}
