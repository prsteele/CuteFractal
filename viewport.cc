#include "viewport.hh"
#include <QtGlobal>

Viewport::Viewport(double center_re, double center_im,
		   int im_width, int im_height, double coor_width)
{
  if (coor_width <= 0) {
    qWarning("Coordinate width must be positive");
    coor_width = 4;
  }

  this->center_re = center_re;
  this->center_im = center_im;
  this->im_width = im_width;
  this->im_height = im_height;
  this->coor_width = coor_width;

  this->d_im_width = im_width;
  this->d_im_height = im_height;
  this->coor_height = this->d_im_height / this->d_im_width * this->coor_width;
}

void Viewport::setCenter(double re, double im)
{
  this->center_re = re;
  this->center_im = im;
}

void Viewport::setImageSize(int w, int h)
{
  if (w <= 0) {
    qWarning("Image width must be positive");
    w = 1;
  }

  if (h <= 0) {
    qWarning("Image height must be positive");
    h = 1;
  }
  
  this->im_width = w;
  this->im_height = h;
  this->d_im_width = this->im_width;
  this->d_im_height = this->im_height;

  this->coor_height = this->d_im_height / this->d_im_width * this->coor_width;
}

void Viewport::setCoordinateWidth(double coor_width)
{
  if (coor_width <= 0) {
    qWarning("Coordinate width must be positive");
    coor_width = 4;
  }
  
  this->coor_width = coor_width;
  this->coor_height = this->d_im_height / this->d_im_width * this->coor_width;
}

void Viewport::setCoordinateHeight(double coor_height)
{
  if (coor_height <= 0) {
    qWarning("Coordinate height must be positive");
    coor_height = 4;
  }
    
  this->coor_height = coor_height;
  this->coor_width = this->d_im_width / this->d_im_height * this->coor_height;
}

void Viewport::move(double dRe, double dIm)
{
  this->center_re += dRe;
  this->center_im += dIm;
}

void Viewport::moveByPixel(int dx, int dy)
{
  this->center_re += dx / this->d_im_width * this->coor_width;
  this->center_im -= dy / this->d_im_height * this->coor_height;
}

double Viewport::centerRe() const
{
  return this->center_re;
}

double Viewport::centerIm() const
{
  return this->center_im;
}

double Viewport::coorWidth() const
{
  return this->coor_width;
}

double Viewport::coorHeight() const
{
  return this->coor_height;
}

int Viewport::imageWidth() const
{
  return this->im_width;
}

int Viewport::imageHeight() const
{
  return this->im_height;
}


void Viewport::imageToCoor(int x, int y, double *re, double *im)
{
  *re = this->center_re + this->coor_width * (x / this->d_im_width - 0.5);
  *im = this->center_im - this->coor_height * (y / this->d_im_height - 0.5);
}

void Viewport::coorToImage(double re, double im, int *x, int *y)
{
  *x = ((re - this->center_re) / this->coor_width + 0.5) * this->im_width;
  *y = ((this->center_im - im) / this->coor_height + 0.5) * this->im_height;
}
