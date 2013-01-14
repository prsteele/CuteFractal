#include "fractal_manager.hh"
#include "mandelbrot.hh"
#include "julia.hh"
#include "palette.hh"
#include "evaluator.hh"

FractalManager::FractalManager(Evaluator *evaluator, Palette *palette)
{
  this->view = new Viewport(0, 0, 100, 100, 4);
  this->mandelbrot =
    new Mandelbrot(200, 8, evaluator, palette);
  this->julia =
    new Julia(1000, 8, evaluator, palette, -.8, .156);
}

FractalManager::~FractalManager()
{
  delete this->view;
  delete this->mandelbrot;
  delete this->julia;
}
