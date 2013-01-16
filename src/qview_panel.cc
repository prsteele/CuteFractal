#include "qview_panel.hh"

#include <QHBoxLayout>
#include <iostream>

QViewPanel::QViewPanel(QFractalView *fview, QWidget *parent)
  : QWidget(parent)
{
  this->fview = fview;

  this->zoom_in_button = new QPushButton(tr("Zoom in"), this);
  this->zoom_out_button = new QPushButton(tr("Zoom out"), this);

  this->setupLayout();
  this->setupActions();
}

QViewPanel::~QViewPanel()
{
}

void QViewPanel::zoomIn()
{
  this->fview->zoomIn();
}

void QViewPanel::zoomOut()
{
  this->fview->zoomOut();
}

QSize QViewPanel::sizeHint() const
{
  QSize *size = new QSize(300, 300);
  return *size;
}

void QViewPanel::setupLayout()
{
  QHBoxLayout *layout = new QHBoxLayout(this);
  layout->addWidget(this->zoom_in_button);
  layout->addWidget(this->zoom_out_button);
}

void QViewPanel::setupActions()
{
  this->connect(this->zoom_in_button, SIGNAL(clicked()),
		this, SLOT(zoomIn()));
  
  this->connect(this->zoom_out_button, SIGNAL(clicked()),
		this, SLOT(zoomOut()));
}
