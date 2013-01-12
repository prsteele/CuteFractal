#ifndef VIEWPORT_HH
#define VIEWPORT_HH

class Viewport
{
public:

  Viewport(double center_re, double center_im,
	   double coor_width);

  double center_re;
  double center_im;
  double coor_width;
};

#endif
