#include "iterated_fractal.hh"

#include <iostream>

IteratedFractal::IteratedFractal(Viewport *view, int max_iterations, double max_radius,
				 Evaluator *evaluator, Palette *palette)
  : Fractal(view)
{
  this->max_iterations = max_iterations;
  this->max_radius = max_radius;
  this->evaluator = evaluator;
  this->palette = palette;
}

void IteratedFractal::render(int im_width, int im_height, int *image)
{
  this->view->setImageSize(im_width, im_height);

  double coor_width = this->view->coorWidth();
  double coor_height = this->view->coorHeight();
  double center_re = this->view->centerRe();
  double center_im = this->view->centerIm();
  
  double dx = coor_width / im_width;
  double dy = coor_height / im_height;

  int ndx = 0;
  double x;
  double y;

  y = center_im + coor_height / 2;
  for (int row = 0; row < im_height; row++, y -= dy) {

    x = center_re - coor_width / 2;
    for (int col = 0; col < im_width; col++, x += dx) {
      Result res;
      this->iterate_point(x, y, &res);

      double value = this->evaluator->eval(&res);
      int color = this->palette->color(value);

      image[ndx] = color;
      ndx++;
    }
  }
}
