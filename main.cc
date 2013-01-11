#include <QtGui>
#include <QApplication>
#include "window.hh"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  Window window;

  window.show();
  
  return app.exec();
}
