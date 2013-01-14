#ifndef VIEWPORT_HH
#define VIEWPORT_HH

class Viewport
{
public:

  Viewport(double center_re, double center_im, int im_width, int im_height,
	   double coor_width);

  void setCenter(double re, double im);

  /*
    If the image aspect ratio disagrees with what is implied by
    coor_width and coor_height, coor_width is assumed to be correct.
   */
  void setImageSize(int w, int h);
  void setCoordinateWidth(double coor_width);
  void setCoordinateHeight(double coor_width);

  void move(double dRe, double dIm);
  void moveByPixel(int dx, int dy);

  double centerRe() const;
  double centerIm() const;
  double coorWidth() const;
  double coorHeight() const;
  int imageWidth() const;
  int imageHeight() const;

  void imageToCoor(int x, int y, double *re, double *im);
  void coorToImage(double re, double im, int *x, int *y);
  
private:
  
  double center_re;
  double center_im;
  double coor_width;
  double coor_height;
  int im_width;
  int im_height;
  double d_im_width;
  double d_im_height;
};

#endif
