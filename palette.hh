#ifndef PALETTE_HH
#define PALETTE_HH

/*
  Map a [0, 1] value to an ARGB color value, represented as an int
  (0xAARRGGBB).
 */
typedef int Palette(double);

/*
  We now define some palettes.
 */

int bw_cutoff(double value);

#endif
