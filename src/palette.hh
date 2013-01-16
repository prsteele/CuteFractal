#ifndef PALETTE_HH
#define PALETTE_HH

#include <QColor>

class Palette
{
public:
  typedef unsigned int Color;

  /*
    Convert a [0, 1] value to an ARGB color value, represented as an
    integer 0xAARRGGBB.
   */
  virtual Color color(double value)=0;

  Color toARGB(int a, int r, int g, int b);
  Color toARGB(double a, double r, double g, double b);
};

#endif
