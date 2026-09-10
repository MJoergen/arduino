#include <Adafruit_GFX.h>
#include <RGBmatrixPanel.h>

#define CLK  8   // pin 11 on a Mega 2560
#define LAT  A3
#define OE   9
#define A    A0
#define B    A1
#define C    A2

// 7 arguments = 16 rows. false = single-buffered.
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

void setup() {
  matrix.begin();

  matrix.fillScreen(0);
  matrix.drawRect(0, 0, 32, 16, matrix.Color333(0, 0, 7));   // blue border
  matrix.fillCircle(16, 8, 4, matrix.Color333(7, 0, 0));     // red dot

  matrix.setTextColor(matrix.Color333(0, 7, 0));
  matrix.setCursor(2, 4);
  matrix.print("Hi");
}

void loop() {
  // Nothing here: a timer interrupt refreshes the panel by itself.
}

