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

#endif
