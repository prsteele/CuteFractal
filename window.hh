#ifndef WINDOW_HH
#define WINDOW_HH

#include <QWidget>
#include <QLabel>
#include "render.hh"

class Window : public QWidget
{
  Q_OBJECT;

public:
  Window();
  ~Window();

private slots:
  //void fractalChanged();

private:
  QLabel *fractalLabel;
  QLabel *fractalReParam;
  QLabel *fractalImParam;
  Render *render;
};

#endif
