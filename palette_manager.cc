#include "palette_manager.hh"
#include "bw_palette.hh"
#include "greyscale_palette.hh"

PaletteManager::PaletteManager()
{
  this->bw_cutoff = new BWPalette;
  this->greyscale = new GreyscalePalette;
}

PaletteManager::~PaletteManager()
{
  delete this->bw_cutoff;
  delete this->greyscale;
}
