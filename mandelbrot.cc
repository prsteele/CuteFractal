#include <math.h>
#include "mandelbrot.hh"

Mandelbrot::Mandelbrot(Viewport *view, int max_iterations, double max_radius,
		       Evaluator *eval, Palette *palette)
  : IteratedFractal(view, max_iterations, max_radius, eval, palette)
{
}

Mandelbrot::Mandelbrot(int max_iterations, double max_radius,
		       Evaluator *eval, Palette *palette)
  : IteratedFractal(max_iterations, max_radius, eval, palette)
{
}

Mandelbrot::~Mandelbrot() {
}

void Mandelbrot::iterate_point(double x, double y, Result *result)
{
  double c_re = 0;
  double c_im = 0;

  double max_radius_sq = this->max_radius * this->max_radius;
  
  int iters = 0;
  double radius_sq = 0;
  
  while (iters < this->max_iterations && radius_sq < max_radius_sq) {
    double next_re = c_re * c_re - c_im * c_im + x;
    double next_im = 2 * c_re * c_im + y;

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
