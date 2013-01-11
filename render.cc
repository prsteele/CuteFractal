#include <QPainter>

#include "render.hh"

#include "mandelbrot.hh"
#include "viewport.hh"
#include "evaluate.hh"
#include "palette.hh"

Render::Render(QWidget *parent)
  : QWidget(parent)
{
  this->image = new QImage(this->sizeHint(),
			   QImage::Format_ARGB32_Premultiplied);

  setBackgroundRole(QPalette::Base);
  setAutoFillBackground(true);
}

Render::~Render()
{
  delete this->image;
}

QSize Render::minimumSizeHint() const
{
  return QSize(100, 100);
}

QSize Render::sizeHint() const
{
  return QSize(1000, 1000);
}

void Render::paintEvent(QPaintEvent *event)
{

  QSize size = this->size();

  delete this->image;
  this->image = new QImage(size, QImage::Format_ARGB32_Premultiplied);

  Mandelbrot man(100, 8);
  Viewport view (0, 0, 4);

  int im_width = size.width();
  int im_height = size.height();

  int *image = new int [im_width * im_height];

  man.render(&view, im_width, im_height,
	     linear_interpolation, bw_cutoff, &image);
  
  for (int row = 0; row < im_height; row++) {
    for (int col = 0; col < im_width; col++) {
      this->image->setPixel(col, row, image[row * im_width + col]);
    }
  }

  QPainter painter (this);
  painter.drawImage(0, 0, *(this->image));

  delete image;
}
