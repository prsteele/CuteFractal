#ifndef PALETTE_MANAGER_HH
#define PALETTE_MANAGER_HH

#include "palette.hh"

class PaletteManager
{
public:
  PaletteManager();
  ~PaletteManager();

  Palette *bw_cutoff;
  Palette *greyscale;
};

#endif
