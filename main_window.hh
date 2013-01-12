#ifndef MAIN_WINDOW_HH
#define MAIN_WINDOW_HH

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>

#include "fractal_view.hh"

class MainWindow : public QMainWindow
{
  Q_OBJECT;

public:
  MainWindow(FractalView *fview);
  ~MainWindow();

  QMenu *fileMenu;
  QMenu *editMenu;
  QMenu *helpMenu;
  FractalView *fview;
};

#endif
