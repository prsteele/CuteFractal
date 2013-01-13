#ifndef PALETTE_HH
#define PALETTE_HH

#include <QColor>



class Palette
{
public:
  /*
    Convert a [0, 1] value to an ARGB color value, represented as an
    integer 0xAARRGGBB.
   */
  virtual unsigned int color(double value)=0;

  unsigned int toARGB(int a, int r, int g, int b);
  unsigned int toARGB(double a, double r, double g, double b);
};

#endif
