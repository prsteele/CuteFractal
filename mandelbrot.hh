#ifndef MANDELBROT_HH
#define MANDELBROT_HH

#include "iterated_fractal.hh"

class Mandelbrot : public IteratedFractal
{
public:
  Mandelbrot(int max_iterations, double max_radius);
  ~Mandelbrot();

  virtual void iterate_point(double x, double y, Result *result);
};

#endif
