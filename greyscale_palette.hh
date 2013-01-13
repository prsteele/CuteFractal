#ifndef GREYSCALE_PALETTE_HH
#define GREYSCALE_PALETTE_HH

#include "palette.hh"

class GreyscalePalette : public Palette
{
public:
  
  GreyscalePalette();
  ~GreyscalePalette();

  virtual unsigned int color(double value);
};

#endif
