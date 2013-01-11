#include "iterated_fractal.hh"
#include <iostream>

IteratedFractal::IteratedFractal(int max_iterations, double max_radius)
{
  this->max_iterations = max_iterations;
  this->max_radius = max_radius;;
}

void IteratedFractal::render(Viewport *viewport, int im_width, int im_height,
			     Evaluator eval, Palette palette, int **image)
{
  double dx = viewport->coor_width / im_width;
  double dy = viewport->coor_height / im_height;

  int ndx = 0;
  double x;
  double y;
  
  y = viewport->center_im + viewport->coor_height / 2;
  for (int col = 0; col < im_width; col++, y -= dy) {

    x = viewport->center_re - viewport->coor_width / 2;
    for (int row = 0; row < im_height; row++, x += dx) {
      Result res;
      this->iterate_point(x, y, &res);

      double value = eval(&res, this->max_iterations, this->max_radius);
      int color = palette(value);

      (*image)[ndx] = color;
      ndx++;
    }
  }
}
