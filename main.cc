#include <QtGui>
#include <QApplication>

#include "main_window.hh"
#include "fractal_view.hh"
#include "mandelbrot.hh"
#include "julia.hh"
#include "evaluate.hh"
#include "palette.hh"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  FractalView *fview = new FractalView;

  Viewport view (0, 0, 4);
  Mandelbrot man(&view, 200, 8, linear_interpolation, bw_cutoff);
  Julia jul(&view, 1000, 8, linear_interpolation, greyscale, -.8, .156);
  fview->setFractal(&jul);

  //fview.show();
  MainWindow window (fview);
  window.show();
  
  return app.exec();
}
