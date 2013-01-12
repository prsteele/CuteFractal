#include "iterated_fractal.hh"

#include <iostream>

IteratedFractal::IteratedFractal(Viewport *view, int max_iterations, double max_radius,
				 Evaluator eval, Palette palette)
  : Fractal(view)
{
  this->max_iterations = max_iterations;
  this->max_radius = max_radius;
  this->eval = eval;
  this->palette = palette;
}

IteratedFractal::IteratedFractal(int max_iterations, double max_radius,
				 Evaluator eval, Palette palette)
  : Fractal()
{
  this->max_iterations = max_iterations;
  this->max_radius = max_radius;
  this->eval = eval;
  this->palette = palette;
}

void IteratedFractal::render(int im_width, int im_height, int *image)
{
  double coor_height = im_height * this->view->coor_width / im_width;
  double dx = this->view->coor_width / im_width;
  double dy = coor_height / im_height;

  int ndx = 0;
  double x;
  double y;

  y = this->view->center_im + coor_height / 2;
  for (int row = 0; row < im_height; row++, y -= dy) {

    x = this->view->center_re - this->view->coor_width / 2;
    for (int col = 0; col < im_width; col++, x += dx) {
      Result res;
      this->iterate_point(x, y, &res);

      double value = this->eval(&res, this->max_iterations, this->max_radius);
      int color = this->palette(value);

      image[ndx] = color;
      ndx++;
    }
  }
}
