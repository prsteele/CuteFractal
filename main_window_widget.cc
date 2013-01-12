#include "main_window_widget.hh"

#include <QtGui>
#include <QWidget>
#include <QString>
#include <QAction>

MainWindowWidget::MainWindowWidget()
{
  this->fmanager = new FractalManager;
  this->fview = new FractalViewWidget(this);
  this->fview->setFractal(this->fmanager->mandelbrot);
  
  this->setupCentralWidget();
  this->setupLayout();
  this->setupMenus();
  this->setupActions();
  this->setupSize();
  
  this->setWindowTitle(tr("CuteFractal"));
}

MainWindowWidget::~MainWindowWidget()
{
  delete this->fmanager;
}

void MainWindowWidget::setupCentralWidget()
{
  QWidget *centralWidget = new QWidget;
  this->setCentralWidget(centralWidget);
}

void MainWindowWidget::setupLayout()
{
  QVBoxLayout *layout = new QVBoxLayout;
  layout->setMargin(5);
  layout->addWidget(this->fview);
  this->centralWidget()->setLayout(layout);
}

void MainWindowWidget::setupSize()
{
  this->setMinimumSize(600, 600);
}

void MainWindowWidget::setupMenus()
{
  this->fileMenu = this->menuBar()->addMenu(tr("&File"));
  this->editMenu = this->menuBar()->addMenu(tr("&Edit"));
  this->helpMenu = this->menuBar()->addMenu(tr("&Help"));
}

void MainWindowWidget::setupActions()
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

void MainWindowWidget::setMandelbrot()
{
  this->fview->setFractal(this->fmanager->mandelbrot);
  this->update();
}

void MainWindowWidget::setJulia()
{
  this->fview->setFractal(this->fmanager->julia);
  this->update();
}
