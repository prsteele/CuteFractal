#include "qfractal_view.hh"
#include <QPainter>
#include "palette.hh"

QFractalView::QFractalView(QWidget *parent)
  : QWidget(parent)
{
  QSize size = this->size();
  this->view = new Viewport(0, 0, size.width(), size.height(), 4);
  this->current_image = new QImage;
  this->fractal_rendered = false;
  this->fractal = NULL;
}

QFractalView::~QFractalView() {
  delete this->view;
}

void QFractalView::setFractal(Fractal *fractal)
{
  if (this->fractal != fractal) {
    this->fractal_rendered = false;
  }
  
  this->fractal = fractal;
}

QSize QFractalView::minimumSizeHint() const
{
  return QSize(100, 100);
}

QSize QFractalView::sizeHint() const
{
  return QSize(1000, 1000);
}

void QFractalView::resizeEvent(QResizeEvent *event)
{
  QSize size = event->size();
  this->view->setImageSize(size.width(), size.height());

  // Propagate the event upwards
  QWidget::resizeEvent(event);
}

void QFractalView::paintEvent(QPaintEvent *event)
{
  if (!this->fractal_rendered) {
    this->renderFractal();
  }

  QRect rect = event->rect();

  QPainter painter (this);
  painter.drawImage(rect.x(), rect.y(), *(this->current_image));
}

void QFractalView::renderFractal()
{
  if (this->fractal == NULL) {
    qWarning("No fractal specified");
    return;
  }

  this->fractal_rendered = true;
  this->current_image = new QImage (this->size(), QFRACTALVIEW_FORMAT);

  QPainter painter (this->current_image);

  this->renderRegion(&painter, this->rect());
}

void QFractalView::renderRegion(QPainter *painter, QRect rect)
{
  // Get the size of the requested rectangle on screen, and allocate
  // memory for the fractal
  QSize size = rect.size();
  int im_width = size.width();
  int im_height = size.height();

  if (im_width * im_height <= 0) {
    return;
  }
  
  Palette::Color *image = new Palette::Color [im_width * im_height];

  // Create a Viewport for this rectangle
  double center_re;
  double center_im;
  this->view->imageToCoor(rect.x() + im_width / 2, rect.y() + im_height / 2,
			  &center_re, &center_im);

  double x1;
  double x2;
  double garbage;
  this->view->imageToCoor(rect.x(), rect.y(), &x1, &garbage);
  this->view->imageToCoor(rect.x() + im_width, rect.y(), &x2, &garbage);
  double coor_width = x2 - x1;
  Viewport view (center_re, center_im, im_width, im_height, coor_width);

  // Render the fractal
  this->fractal->render(&view, image);

  // Paint the fractal to master_image
  QImage tmp (im_width, im_height, QFRACTALVIEW_FORMAT);
  this->toQImage(image, &tmp);

  painter->drawImage(rect, tmp);
  delete image;
}

void QFractalView::toQImage(Palette::Color *image, QImage *qimage)
{
  int im_width = qimage->width();
  int im_height = qimage->height();

  int ndx = 0;
  for (int row = 0; row < im_height; row++) {
    QRgb *rowpx = (QRgb*) qimage->scanLine(row);
    for (int col = 0 ; col < im_width; col++) {
      Palette::Color color = image[ndx];
      Palette::Color a = (color & 0xFF000000) >> 24;
      Palette::Color r = (color & 0x00FF0000) >> 16;
      Palette::Color g = (color & 0x0000FF00) >> 8;
      Palette::Color b = (color & 0x000000FF);
      rowpx[col] = qRgba(r, g, b, a);
      ndx++;
    }
  }  
}

void QFractalView::mousePressEvent(QMouseEvent *event)
{
  this->isDragging = true;
  this->mouseStartX = event->x();
  this->mouseStartY = event->y();
  this->startRe = this->view->centerRe();
  this->startIm = this->view->centerIm();
}

void QFractalView::mouseReleaseEvent(QMouseEvent *event)
{
  this->isDragging = false;
}

void QFractalView::mouseMoveEvent(QMouseEvent *event)
{
  if (this->isDragging) {
    int dX = event->x() - this->mouseStartX;
    int dY = event->y() - this->mouseStartY;

    // Update the Viewport
    this->view->moveByPixel(-dX, -dY);

    // Paint onto a new image
    QImage *new_image = new QImage(this->size(), QFRACTALVIEW_FORMAT);
    QPainter painter (new_image);

    // Move the existing piece of the fractal
    if (dX >= 0) {
      if (dY >= 0) {
	painter.drawImage(dX, dY, *(this->current_image));
      }
      else {
	painter.drawImage(dX, 0, *(this->current_image), 0, -dY);
      }
    }
    else {
      if (dY >= 0) {
	painter.drawImage(0, dY, *(this->current_image), -dX, 0);
      }
      else {
	painter.drawImage(0, 0, *(this->current_image), -dX, -dY);
      }
    }

    // Render the new pieces
    if (dX >= 0) {
      if (dY >= 0) {
	QRect top_left (0, 0, dX, dY);
	QRect top (dX, 0, this->view->imageWidth() - dX, dY);
	QRect left (0, dY, dX, this->view->imageHeight() - dY);
	
	this->renderRegion(&painter, top_left);
	this->renderRegion(&painter, top);
	this->renderRegion(&painter, left);
      }
      else {
	QRect bottom_left (0, this->view->imageHeight() + dY,
			   dX, -dY);
	QRect bottom (dX, this->view->imageHeight() + dY,
		      this->view->imageWidth() - dX, -dY);
	QRect left (0, 0,
		    dX, this->view->imageHeight() + dY);
	
	this->renderRegion(&painter, bottom_left);
	this->renderRegion(&painter, bottom);
	this->renderRegion(&painter, left);
      }
    }
    else {
      if (dY >= 0) {
	QRect top_right (this->view->imageWidth() + dX, 0, -dX, dY);
	QRect top (0, 0, this->view->imageWidth() + dX, dY);
	QRect right (this->view->imageWidth() + dX, dY,
		     -dX, this->view->imageHeight() - dY);
	
	this->renderRegion(&painter, top_right);
	this->renderRegion(&painter, top);
	this->renderRegion(&painter, right);
      }
      else {
	QRect bottom_right (this->view->imageWidth() + dX,
			    this->view->imageHeight() + dY,
			   -dX, -dY);
	QRect bottom (0, this->view->imageHeight() + dY,
		      this->view->imageWidth() + dX, -dY);
	QRect right (this->view->imageWidth() + dX, 0,
		     -dX, this->view->imageHeight() + dY);
	
	this->renderRegion(&painter, bottom_right);
	this->renderRegion(&painter, bottom);
	this->renderRegion(&painter, right);
      }
    }

    // Copy the new image onto current_image, and update the widget
    QPainter p (this->current_image);
    p.drawImage(0, 0, *new_image);
    this->update();

    this->mouseStartX = event->x();
    this->mouseStartY = event->y();


    // // Subtract the changes, since we want to simulate dragging paper
    // this->fractal->getViewport()->setCenter(this->startRe, this->startIm);
    // this->fractal->getViewport()->moveByPixel(-dRe, -dIm);
    // this->update();
  }
}
