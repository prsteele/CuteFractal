#include <QtGui>
#include "window.hh"


Window::Window()
{
  this->fractalReParam = new QLabel("real param");
  this->fractalImParam = new QLabel("real param");
  this->render = new Render;

  QGridLayout *mainLayout = new QGridLayout;
  mainLayout->addWidget(this->render, 0, 0, 1, 4);
  setLayout(mainLayout);
  setWindowTitle("Test");
}

Window::~Window()
{
  delete this->render;
}
