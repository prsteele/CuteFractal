#ifndef MANDELBROT_HH
#define MANDELBROT_HH

#include "iterated_fractal.hh"

class Mandelbrot : public IteratedFractal
{
public:
  Mandelbrot(Viewport *view, int max_iterations, double max_radius,
	     Evaluator *eval, Palette *palette);

  ~Mandelbrot();

  virtual void iterate_point(double x, double y, Result *result);
};

#endif
