#ifndef FRACTAL_HH
#define FRACTAL_HH

#include "viewport.hh"
#include "palette.hh"

class Fractal
{
public:
  virtual void render(Viewport *view, Palette::Color *image)=0;
};

#endif
