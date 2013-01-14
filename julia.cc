#include <math.h>
#include "julia.hh"

Julia::Julia(Viewport *view, int max_iterations, double max_radius,
	     Evaluator *eval, Palette *palette, double param_re, double param_im)
  : IteratedFractal(view, max_iterations, max_radius, eval, palette)
{
  this->param_re = param_re;
  this->param_im = param_im;
}

Julia::~Julia() {
}

void Julia::iterate_point(double x, double y, Result *result)
{
  double c_re = x;
  double c_im = y;

  double max_radius_sq = this->max_radius * this->max_radius;
  
  int iters = 0;
  double radius_sq = 0;
  
  while (iters < this->max_iterations && radius_sq < max_radius_sq) {
    double next_re = c_re * c_re - c_im * c_im + this->param_re;
    double next_im = 2 * c_re * c_im + this->param_im;

    c_re = next_re;
    c_im = next_im;

    iters++;
    radius_sq = c_re * c_re + c_im * c_im;
  }

  result->iterations = iters;
  result->radius = sqrt(radius_sq);
  result->max_iterations = this->max_iterations;
  result->max_radius = this->max_radius;
}
