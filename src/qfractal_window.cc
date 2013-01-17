#include "qfractal_window.hh"

#include <QtGui>
#include <QWidget>
#include <QString>
#include <QAction>

#include <map>
#include <string>

QFractalWindow::QFractalWindow(QApplication *app, QWidget *parent)
  : QMainWindow(parent)
{
  this->application = app;
  this->fview = NULL;

  this->setupCentralWidget();
  this->setupManagers();
  this->setupLayout();
  this->setupMenus();
  this->setupActions();
  this->setupSize();
  
  this->setWindowTitle(tr("CuteFractal"));

  // This should be relocated, or managed better somehow...
  this->view_panel = new QViewPanel(&(this->fview));
  view_panel->show();
}

QFractalWindow::~QFractalWindow()
{
  delete this->fractal_manager;
  delete this->palette_manager;
  delete this->evaluator_manager;
}

void QFractalWindow::closeEvent(QCloseEvent *event)
{
  this->view_panel->close();
  QMainWindow::closeEvent(event);
}

void QFractalWindow::setupManagers()
{
  this->palette_manager = new PaletteManager;
  this->evaluator_manager = new EvaluatorManager;
  this->fractal_manager =
    new FractalManager(this->evaluator_manager->linear_interpolator,
		       this->palette_manager->greyscale);

  // FractalViewManager needs to use FractalManager, and so must be create
  this->fractal_view_manager = new FractalViewManager(this->centralWidget(), this->fractal_manager);
}

void QFractalWindow::setupCentralWidget()
{
  QWidget *centralWidget = new QWidget;
  this->setCentralWidget(centralWidget);
}

void QFractalWindow::setupLayout()
{
  QVBoxLayout *layout = new QVBoxLayout(this->centralWidget());
  layout->setMargin(5);

  // Add the current QFractalView as the sole child
  this->fview = this->fractal_view_manager->getCurrent();

  layout->addWidget(this->fview);
  this->fview->setVisible(true);
}

void QFractalWindow::setupSize()
{
  this->setMinimumSize(600, 600);
}

void QFractalWindow::setupMenus()
{
  this->fileMenu = this->menuBar()->addMenu(tr("&File"));
  this->editMenu = this->menuBar()->addMenu(tr("&Edit"));
  this->helpMenu = this->menuBar()->addMenu(tr("&Help"));
}

void QFractalWindow::setupActions()
{
  this->mandelbrotAction = new QAction(tr("Mandelbrot set"), this);
  this->mandelbrotAction->setStatusTip(tr("Create a new Mandelbrot set"));
  this->connect(this->mandelbrotAction, SIGNAL(triggered()),
		this, SLOT(setMandelbrot()));
  this->editMenu->addAction(this->mandelbrotAction);

  this->juliaAction = new QAction(tr("Julia set"), this);
  this->juliaAction->setStatusTip(tr("Create a new Julia set"));
  this->connect(this->juliaAction, SIGNAL(triggered()),
		this, SLOT(setJulia()));
  this->editMenu->addAction(this->juliaAction);

  this->quitAction = new QAction(tr("&Quit"), this);
  this->quitAction->setStatusTip(tr("Close the application"));
  this->connect(this->quitAction, SIGNAL(triggered()),
		this->application, SLOT(quit()));
  this->fileMenu->addAction(this->quitAction);
}

void QFractalWindow::setFractal(const char* fview_name)
{
  QLayout *layout = this->centralWidget()->layout();
  
  // Remove the current fractal from the central widget
  if (this->fview != NULL) {
    layout->removeWidget(this->fview);
    this->fview->setVisible(false);
  }

  this->fractal_view_manager->choose(fview_name);

  // Add the new fractal to the central widget
  this->fview = this->fractal_view_manager->getCurrent();
  layout->addWidget(this->fview);
  this->fview->setVisible(true);
}

void QFractalWindow::setMandelbrot()
{
  this->setFractal("mandelbrot");
}

void QFractalWindow::setJulia()
{
  this->setFractal("julia");
}
