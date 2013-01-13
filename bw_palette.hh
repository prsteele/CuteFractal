#ifndef BW_PALETTE_HH
#define BW_PALETTE_HH

#include "palette.hh"

class BWPalette : public Palette
{
public:
  BWPalette();
  BWPalette(double cutoff);
  ~BWPalette();
  
  virtual unsigned int color(double value);

  void setCutoff(double value);

private:
  double cutoff;
};

#endif
