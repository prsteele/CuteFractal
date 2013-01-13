#ifndef FRACTAL_MANAGER_HH
#define FRACTAL_MANAGER_HH

#include "fractal.hh"
#include "viewport.hh"
#include "palette.hh"
#include "evaluator.hh"

class FractalManager
{
public:
  FractalManager(Evaluator *evaluator, Palette *palette);
  ~FractalManager();

  Viewport *view;
  Fractal *mandelbrot;
  Fractal *julia;
};

#endif
