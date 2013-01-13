#ifndef MAIN_WINDOW_HH
#define MAIN_WINDOW_HH

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>

#include "qfractal_view.hh"
#include "fractal_manager.hh"

class QFractalWindow : public QMainWindow
{
  Q_OBJECT;

public:
  QFractalWindow();
  ~QFractalWindow();

private slots:
  void setMandelbrot();
  void setJulia();

protected:

  void setupCentralWidget();
  void setupLayout();
  void setupSize();
  void setupMenus();
  void setupActions();

  QMenu *fileMenu;
  QMenu *editMenu;
  QMenu *helpMenu;
  QFractalView *fview;

  QAction *mandelbrotAction;
  QAction *juliaAction;

private:
  FractalManager *fmanager;
};

#endif
