#ifndef FRACTAL_HH
#define FRACTAL_HH

#include "viewport.hh"

class Fractal
{
public:

  Fractal(Viewport *view);
  ~Fractal();

  void setViewport(Viewport *view);
  Viewport* getViewport();
  
  virtual void render(int im_width, int im_height, int *image)=0;

protected:
  Viewport *view;
};

#endif
