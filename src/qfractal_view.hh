#ifndef FRACTAL_VIEW_HH
#define FRACTAL_VIEW_HH

#include <QWidget>
#include <QImage>
#include <QMouseEvent>

#include "fractal.hh"

#define QFRACTALVIEW_FORMAT QImage::Format_ARGB32_Premultiplied

class QFractalView : public QWidget
{
  Q_OBJECT;

public:

  QFractalView(QWidget *parent=0);
  ~QFractalView();

  void setFractal(Fractal *fractal);
  
  QSize minimumSizeHint() const;
  QSize sizeHint() const;

  // Zooming
  void zoomIn();
  void zoomOut();
  void setZoomScale(double scale);
  double getZoomScale();

protected:
  void resizeEvent(QResizeEvent *event);
  void paintEvent(QPaintEvent *event);

private:
  Viewport *view;
  bool fractal_rendered;
  
  void renderFractal();
  
  /*
    Render the current fractal over a portion of the screen; paint the
    results using the provided painter
   */
  void renderRegion(QPainter *painter, QRect rect);
  Fractal *fractal;

  QImage *current_image;

  void toQImage(Palette::Color *image, QImage *qimage);

  // Handle click and drag events
  bool isDragging;
  int mouseStartX;
  int mouseStartY;
  int startRe;
  int startIm;
  void mousePressEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);

  // Zooming
  double zoom_scale;
};

#endif
