#ifndef FRACTAL_VIEW_MANAGER_HH
#define FRACTAL_VIEW_MANAGER_HH

#include "fractal_manager.hh"
#include "qfractal_window.hh"
#include "qfractal_view.hh"
#include <QWidget>

#include <map>
#include <string>

class FractalViewManager
{
public:
  FractalViewManager(QWidget *parent, FractalManager *fractal_manager);
  ~FractalViewManager();

  QFractalView * getCurrent();

  void choose(const char* fview_name);
  void choose(std::string fview_name);

  std::map<std::string, QFractalView*> *lookup;

private:

  QFractalView *current;
  
};

#endif
