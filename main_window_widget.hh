#ifndef MAIN_WINDOW_HH
#define MAIN_WINDOW_HH

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>

#include "fractal_view_widget.hh"
#include "fractal_manager.hh"

class MainWindowWidget : public QMainWindow
{
  Q_OBJECT;

public:
  MainWindowWidget();
  ~MainWindowWidget();

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
  FractalViewWidget *fview;

  QAction *mandelbrotAction;
  QAction *juliaAction;

private:
  FractalManager *fmanager;
};

#endif
