#include <QtGui>
#include <QApplication>

#include "qfractal_window.hh"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QFractalWindow window(&app);
  window.show();
  
  return app.exec();
}
