#include "greyscale_palette.hh"

GreyscalePalette::GreyscalePalette()
{
}

GreyscalePalette::~GreyscalePalette()
{
}

unsigned int GreyscalePalette::color(double value)
{
  return this->toARGB(1.0, 1 - value, 1 - value, 1 - value);
}
