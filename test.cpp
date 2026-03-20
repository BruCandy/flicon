#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <Keyboard.h>

const uint8_t ROWS = 6;
const uint8_t COLS = 3;

const uint8_t rowPins[ROWS] = {11, 10, 9, 8, 7, 6};
const uint8_t colPins[COLS] = {4, 3, 2};

bool prevState[ROWS][COLS];

const int led = 12;

Adafruit_NeoPixel pixel(1, led, NEO_GRB + NEO_KHZ800);

const int VERT_PIN = A5;
const int HORZ_PIN = A6;

char keymap[ROWS][COLS] = {
  {'_', 'a', 'b'},
  {'c', 'd', 'e'},
  {'f', 'g', 'h'},
  {'i', 'j', '_'},
  {'k', 'l', 'm'},
  {'n', 'o', 'p'}
};

void setup() {
  pixel.begin();
  pixel.setPixelColor(0, pixel.Color(255, 0, 0)); 
  pixel.show();

  pinMode(VERT_PIN, INPUT);
  pinMode(HORZ_PIN, INPUT);
  
  Serial.begin(115200);

  for (uint8_t r = 0; r < ROWS; r++) {
    pinMode(rowPins[r], OUTPUT);
    digitalWrite(rowPins[r], HIGH);
  }

  for (uint8_t c = 0; c < COLS; c++) {
    pinMode(colPins[c], INPUT_PULLUP);
  }

  for (uint8_t r = 0; r < ROWS; r++) {
    for (uint8_t c = 0; c < COLS; c++) {
      prevState[r][c] = false;
    }
  }
}

void scanMatrix() {
  for (uint8_t r = 0; r < ROWS; r++) {

    for (uint8_t i = 0; i < ROWS; i++) {
      digitalWrite(rowPins[i], HIGH);
    }

    digitalWrite(rowPins[r], LOW);
    delayMicroseconds(5);

    for (uint8_t c = 0; c < COLS; c++) {
      bool pressed = (digitalRead(colPins[c]) == LOW);

      if (pressed != prevState[r][c]) {
        prevState[r][c] = pressed;

        Serial.print("row=");
        Serial.print(r);
        Serial.print(" col=");
        Serial.print(c);
        Serial.print(" key=");
        Serial.print(keymap[r][c]);

        if (pressed) {
          Serial.println(" pressed");
        } else {
          Serial.println(" released");
        }
      }
    }
  }
}

void scanJoicon() {
  int vert = analogRead(VERT_PIN);
  int horz = analogRead(HORZ_PIN);
  if (horz < 300) {
    Serial.print("→");
  } else if (horz > 700) {
    Serial.print("←");
  }
  if (vert < 300) {
    Serial.print("↓");
  } else if (vert > 700) {
    Serial.print("↑");
  }
}

void loop() {
  scanJoicon();
  scanMatrix();
  delay(10);
}