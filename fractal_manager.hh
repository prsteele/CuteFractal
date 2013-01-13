#ifndef FRACTAL_MANAGER_HH
#define FRACTAL_MANAGER_HH

#include "fractal.hh"
#include "viewport.hh"
#include "palette.hh"

class FractalManager
{
public:
  FractalManager();
  ~FractalManager();

  Viewport *view;
  Fractal *mandelbrot;
  Fractal *julia;

  Palette *bw;
  Palette *grey;
};

#endif
