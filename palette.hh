#ifndef PALETTE_HH
#define PALETTE_HH

#include <QColor>

/*
  Map a [0, 1] value to an ARGB color value, represented as an int
  (0xAARRGGBB).
 */
typedef unsigned int Palette(double);

/*
  We now define some palettes.
 */

unsigned int bw_cutoff(double value);

unsigned int greyscale(double value);

unsigned int toARGB(int a, int r, int g, int b);
unsigned int toARGB(double a, double r, double g, double b);

#endif
