#include "bw_palette.hh"

BWPalette::BWPalette()
{
  this->setCutoff(0.5);
}

BWPalette::BWPalette(double cutoff)
{
  this->setCutoff(cutoff);
}

BWPalette::~BWPalette()
{
}

void BWPalette::setCutoff(double cutoff)
{
  this->cutoff = cutoff;
}

unsigned int BWPalette::color(double value)
{
  if (value < .5) {
    return this->toARGB(0xFF, 0xFF, 0xFF, 0xFF);
  }
  else {
    return this->toARGB(0xFF, 0x0, 0x0, 0x0);
  }
}
