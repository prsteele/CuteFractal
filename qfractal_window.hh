#ifndef MAIN_WINDOW_HH
#define MAIN_WINDOW_HH

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>

#include "qfractal_view.hh"
#include "fractal_manager.hh"
#include "palette_manager.hh"
#include "evaluator_manager.hh"

class QFractalWindow : public QMainWindow
{
  Q_OBJECT;

public:
  QFractalWindow(QApplication *app, QWidget *parent=0);
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
  QAction *quitAction;

private:
  FractalManager *fractal_manager;
  PaletteManager *palette_manager;
  EvaluatorManager *evaluator_manager;
  QApplication *application;
};

#endif
