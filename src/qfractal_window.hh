#ifndef MAIN_WINDOW_HH
#define MAIN_WINDOW_HH

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QCloseEvent>

#include "qview_panel.hh"
#include "qfractal_view.hh"
#include "fractal_manager.hh"
#include "palette_manager.hh"
#include "evaluator_manager.hh"
#include "fractal_view_manager.hh"

// We need a forward declaration of FractalViewManager, since these two
// files are mutually dependent. TODO: Fix this, this represents an
// underlying problem with ownership
class FractalViewManager;

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

  void setupManagers();
  void setupCentralWidget();
  void setupLayout();
  void setupSize();
  void setupMenus();
  void setupActions();

  void closeEvent(QCloseEvent *event);

  QMenu *fileMenu;
  QMenu *editMenu;
  QMenu *helpMenu;

  QAction *mandelbrotAction;
  QAction *juliaAction;
  QAction *quitAction;

private:
  PaletteManager *palette_manager;
  EvaluatorManager *evaluator_manager;
  FractalManager *fractal_manager;
  FractalViewManager *fractal_view_manager;
  QFractalView *fview;
  QApplication *application;
  QViewPanel *view_panel;

  void setFractal(const char* fview_name);
};

#endif
