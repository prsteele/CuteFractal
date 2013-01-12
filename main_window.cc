#include "main_window.hh"

#include <QtGui>
#include <QWidget>
#include <QString>

MainWindow::MainWindow(FractalView *fview)
{
  this->fview = fview;
  fview->setParent(this);
  
  QWidget *centralWidget = new QWidget;
  this->setCentralWidget(centralWidget);

  QVBoxLayout *layout = new QVBoxLayout;
  layout->setMargin(5);
  layout->addWidget(this->fview);
  centralWidget->setLayout(layout);
  
  this->fileMenu = this->menuBar()->addMenu(tr("&File"));

  this->setWindowTitle(tr("CuteFractal"));
  this->setMinimumSize(600, 600);
}

MainWindow::~MainWindow()
{
}
