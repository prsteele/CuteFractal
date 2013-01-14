#include "qfractal_window.hh"

#include <QtGui>
#include <QWidget>
#include <QString>
#include <QAction>

QFractalWindow::QFractalWindow(QApplication *app, QWidget *parent)
  : QMainWindow(parent)
{
  this->application = app;
  this->palette_manager = new PaletteManager;
  this->evaluator_manager = new EvaluatorManager;
  this->fractal_manager =
    new FractalManager(this->evaluator_manager->linear_interpolator,
		       this->palette_manager->greyscale);

  this->fview = new QFractalView(this);
  this->fview->setFractal(this->fractal_manager->mandelbrot);
  
  this->setupCentralWidget();
  this->setupLayout();
  this->setupMenus();
  this->setupActions();
  this->setupSize();
  
  this->setWindowTitle(tr("CuteFractal"));
}

QFractalWindow::~QFractalWindow()
{
  delete this->fractal_manager;
  delete this->palette_manager;
  delete this->evaluator_manager;
}

void QFractalWindow::setupCentralWidget()
{
  QWidget *centralWidget = new QWidget;
  this->setCentralWidget(centralWidget);
}

void QFractalWindow::setupLayout()
{
  QVBoxLayout *layout = new QVBoxLayout;
  layout->setMargin(5);
  layout->addWidget(this->fview);
  this->centralWidget()->setLayout(layout);
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

void QFractalWindow::setMandelbrot()
{
  this->fview->setFractal(this->fractal_manager->mandelbrot);
  this->update();
}

void QFractalWindow::setJulia()
{
  this->fview->setFractal(this->fractal_manager->julia);
  this->update();
}
