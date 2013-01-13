#ifndef JULIA_HH
#define JULIA_HH

#include "iterated_fractal.hh"
#include "evaluate.hh"
#include "palette.hh"

class Julia : public IteratedFractal
{

public:
  Julia(Viewport *view, int max_iterations, double max_radius,
	Evaluator eval, Palette *palette, double c_re, double c_im);

  Julia(int max_iterations, double max_radius,
	Evaluator eval, Palette *palette, double c_re, double c_im);

  ~Julia();

  virtual void iterate_point(double x, double y, Result *result);

protected:
  double param_re;
  double param_im;
};

#endif
