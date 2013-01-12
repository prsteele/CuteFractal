#ifndef FRACTAL_VIEW_HH
#define FRACTAL_VIEW_HH

#include <QWidget>
#include <QImage>

#include "fractal.hh"

class FractalViewWidget : public QWidget
{
  Q_OBJECT;

public:

  FractalViewWidget(QWidget *parent=0);
  ~FractalViewWidget();

  void setFractal(Fractal *fractal);
  
  QSize minimumSizeHint() const;
  QSize sizeHint() const;

protected:
  void paintEvent(QPaintEvent *event);

private:
  void renderFractal();

  Fractal *fractal;

  void toQImage(int *image, QImage *qimage);
};

#endif
