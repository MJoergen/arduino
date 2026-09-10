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

// #define COL_BRIGHT_RED   matrix.Color333(7, 0, 0)
// #define COL_BRIGHT_GREEN matrix.Color333(0, 7, 0)
#define COL_BRIGHT_BLUE  matrix.Color333(0, 0, 7)
// #define COL_DARK_RED     matrix.Color333(3, 0, 0)
// #define COL_DARK_GREEN   matrix.Color333(0, 3, 0)
// #define COL_DARK_BLUE    matrix.Color333(0, 0, 3)

unsigned int r = 0;
unsigned int g = 7;
unsigned int b = 0;

typedef enum {
  st_inc_r,
  st_dec_r,
  st_inc_g,
  st_dec_g,
  st_inc_b,
  st_dec_b
} t_state;

t_state state = st_inc_r;


void setup() {
  matrix.begin();

  matrix.fillScreen(0);
  matrix.drawRect(0, 0, 32, 16, COL_BRIGHT_BLUE);   // blue border
  state = st_inc_r;
}

void loop() {
  delay(10);
  matrix.setTextColor(matrix.Color333(r, g, b));
  matrix.setCursor(1, 1);
  matrix.print("Maker");
  matrix.setTextColor(matrix.Color333(g, b, r));
  matrix.setCursor(1, 7);
  matrix.print("Space");

  switch (state) {
    case st_inc_r:
      if (r < 7)
        r += 1;
      else
        state = st_inc_g;
      break;

    case st_dec_r:
      if (r > 0)
        r -= 1;
      else
        state = st_dec_g;
      break;

    case st_inc_g:
      if (g < 7)
        g += 1;
      else
        state = st_inc_b;
      break;

    case st_dec_g:
      if (g > 0)
        g -= 1;
      else
        state = st_dec_b;
      break;

    case st_inc_b:
      if (b < 7)
        b += 1;
      else
        state = st_dec_r;
      break;

    case st_dec_b:
      if (b > 0)
        b -= 1;
      else
        state = st_inc_r;
      break;
  }
}

