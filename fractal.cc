#include "fractal.hh"

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

Viewport* Fractal::getViewport()
{
  return this->view;
}

