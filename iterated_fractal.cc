#include "iterated_fractal.hh"
#include "palette.hh"

IteratedFractal::IteratedFractal(int max_iterations, double max_radius,
				 Evaluator *evaluator, Palette *palette)
{
  this->max_iterations = max_iterations;
  this->max_radius = max_radius;
  this->evaluator = evaluator;
  this->palette = palette;
}

void IteratedFractal::render(Viewport *view, Palette::Color *image)
{
  double coor_width = view->coorWidth();
  double coor_height = view->coorHeight();
  double center_re = view->centerRe();
  double center_im = view->centerIm();
  int im_width = view->imageWidth();
  int im_height = view->imageHeight();
  
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
      Palette::Color color = this->palette->color(value);
      
      image[ndx] = color;
      ndx++;
    }
  }
}
