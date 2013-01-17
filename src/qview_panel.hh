#ifndef QVIEW_PANEL_HH
#define QVIEW_PANEL_HH

#include <QWidget>
#include <QSize>
#include <QPushButton>
#include "qfractal_view.hh"

class QViewPanel : public QWidget
{
  Q_OBJECT;

public:
  QViewPanel(QFractalView **fview, QWidget *parent=0);
  ~QViewPanel();

  QSize sizeHint() const;

private slots:
  void zoomIn();
  void zoomOut();  

private:
  QFractalView **fview;

  QPushButton *zoom_in_button;
  QPushButton *zoom_out_button;

  void setupLayout();
  void setupActions();
};

#endif
