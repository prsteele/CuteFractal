#include "fractal_manager.hh"
#include "mandelbrot.hh"
#include "julia.hh"
#include "evaluate.hh"
#include "palette.hh"

FractalManager::FractalManager()
{
  this->view = new Viewport(0, 0, 4);
  this->mandelbrot =
    new Mandelbrot(view, 200, 8, linear_interpolation, greyscale);
  this->julia =
    new Julia(view, 1000, 8, linear_interpolation, greyscale, -.8, .156);
}

FractalManager::~FractalManager()
{
  delete this->view;
  delete this->mandelbrot;
  delete this->julia;
}
