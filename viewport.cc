#include "viewport.hh"

Viewport::Viewport(double center_re, double center_im,
		   double coor_width)
{
  this->center_re = center_re;
  this->center_im = center_im;
  this->coor_width = coor_width;
}
