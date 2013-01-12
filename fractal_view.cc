#include "fractal_view.hh"

#include <QPainter>

FractalView::FractalView(QWidget *parent)
  : QWidget(parent)
{
  
}

FractalView::~FractalView() {

}

void FractalView::setFractal(Fractal *fractal)
{
  this->fractal = fractal;
}

QSize FractalView::minimumSizeHint() const
{
  return QSize(100, 100);
}

QSize FractalView::sizeHint() const
{
  return QSize(1000, 1000);
}

void FractalView::paintEvent(QPaintEvent *event)
{
  this->renderFractal();
}

void FractalView::renderFractal()
{
  QSize size = this->size();
  int im_width = size.width();
  int im_height = size.height();

  int *image = new int [im_width * im_height];
  
  this->fractal->render(im_width, im_height, image);

  QImage qimage (im_width, im_height, QImage::Format_ARGB32_Premultiplied);
  this->toQImage(image, &qimage);

  QPainter painter (this);
  painter.drawImage(0, 0, qimage);
  delete image;
}

void FractalView::toQImage(int *image, QImage *qimage)
{
  int im_width = qimage->width();
  int im_height = qimage->height();

  int ndx = 0;
  for (int row = 0; row < im_height; row++) {
    QRgb *rowpx = (QRgb*) qimage->scanLine(row);
    for (int col = 0 ; col < im_width; col++) {
      int color = image[ndx];
      int a = (color & 0xFF000000) >> 24;
      int r = (color & 0x00FF0000) >> 16;
      int g = (color & 0x0000FF00) >> 8;
      int b = (color & 0x000000FF);
      rowpx[col] = qRgba(r, g, b, a);
      ndx++;
    }
  }  
}
