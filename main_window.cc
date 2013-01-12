#include "main_window.hh"

#include <QtGui>
#include <QWidget>
#include <QString>
#include <QAction>

MainWindow::MainWindow()
{
  this->fmanager = new FractalManager;
  this->fview = new FractalView(this);
  this->fview->setFractal(this->fmanager->mandelbrot);
  
  this->setupCentralWidget();
  this->setupLayout();
  this->setupMenus();
  this->setupActions();
  this->setupSize();
  
  this->setWindowTitle(tr("CuteFractal"));
}

MainWindow::~MainWindow()
{
  delete this->fmanager;
}

void MainWindow::setupCentralWidget()
{
  QWidget *centralWidget = new QWidget;
  this->setCentralWidget(centralWidget);
}

void MainWindow::setupLayout()
{
  QVBoxLayout *layout = new QVBoxLayout;
  layout->setMargin(5);
  layout->addWidget(this->fview);
  this->centralWidget()->setLayout(layout);
}

void MainWindow::setupSize()
{
  this->setMinimumSize(600, 600);
}

void MainWindow::setupMenus()
{
  this->fileMenu = this->menuBar()->addMenu(tr("&File"));
  this->editMenu = this->menuBar()->addMenu(tr("&Edit"));
  this->helpMenu = this->menuBar()->addMenu(tr("&Help"));
}

void MainWindow::setupActions()
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
}

void MainWindow::setMandelbrot()
{
  this->fview->setFractal(this->fmanager->mandelbrot);
  this->update();
}

void MainWindow::setJulia()
{
  this->fview->setFractal(this->fmanager->julia);
  this->update();
}
