#ifndef VIEWPORT_HH
#define VIEWPORT_HH

class Viewport
{
public:
  double center_re;
  double center_im;
  double coor_width;
  double coor_height;

  Viewport(double center_re, double center_im,
	   double coor_width, double coor_height);
};

#endif
