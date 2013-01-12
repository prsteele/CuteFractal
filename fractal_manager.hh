#ifndef FRACTAL_MANAGER_HH
#define FRACTAL_MANAGER_HH

#include "fractal.hh"
#include "viewport.hh"

class FractalManager
{
public:
  FractalManager();
  ~FractalManager();

  Viewport *view;
  Fractal *mandelbrot;
  Fractal *julia;
};

#endif
