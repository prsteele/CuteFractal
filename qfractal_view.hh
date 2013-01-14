#ifndef FRACTAL_VIEW_HH
#define FRACTAL_VIEW_HH

#include <QWidget>
#include <QImage>
#include <QMouseEvent>

#include "fractal.hh"

class QFractalView : public QWidget
{
  Q_OBJECT;

public:

  QFractalView(QWidget *parent=0);
  ~QFractalView();

  void setFractal(Fractal *fractal);
  
  QSize minimumSizeHint() const;
  QSize sizeHint() const;

protected:
  void paintEvent(QPaintEvent *event);

private:

  void renderFractal();
  Fractal *fractal;

  void toQImage(int *image, QImage *qimage);

  // Handle click and drag events
  bool isDragging;
  int mouseStartX;
  int mouseStartY;
  int startRe;
  int startIm;
  void mousePressEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
};

#endif
