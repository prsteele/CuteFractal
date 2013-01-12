#include <QtGui>
#include <QApplication>

#include "fractal_view.hh"
#include "mandelbrot.hh"
#include "evaluate.hh"
#include "palette.hh"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  FractalView fview;

  Viewport view (0, 0, 4);
  Mandelbrot man(&view, 100, 8, linear_interpolation, bw_cutoff);
  fview.setFractal(&man);

  fview.show();
  
  return app.exec();
}
