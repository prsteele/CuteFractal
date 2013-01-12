#include <QtGui>
#include <QApplication>

#include "main_window_widget.hh"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  MainWindowWidget window;
  window.show();
  
  return app.exec();
}
