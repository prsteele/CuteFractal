#include "viewport.hh"

Viewport::Viewport(double center_re, double center_im,
		   double coor_width, double coor_height)
{
  this->center_re = center_re;
  this->center_im = center_im;
  this->coor_width = coor_width;
  this->coor_height = coor_height;
}
