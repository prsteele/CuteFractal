#include "fractal.hh"

Fractal::Fractal()
{
  this->view = new Viewport(0, 0, 4);
}

Fractal::Fractal(Viewport *view)
{
  this->setViewport(view);
}

Fractal::~Fractal()
{
}

void Fractal::setViewport(Viewport *view)
{
  this->view = view;
}
