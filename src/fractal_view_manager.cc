#include "fractal_view_manager.hh"

FractalViewManager::FractalViewManager(QWidget *parent, FractalManager *fractal_manager)
{
  QFractalView *mandelbrot_view = new QFractalView(parent);
  mandelbrot_view->setFractal(fractal_manager->mandelbrot);
  mandelbrot_view->setVisible(false);

  QFractalView *julia_view = new QFractalView(parent);
  julia_view->setFractal(fractal_manager->julia);
  julia_view->setVisible(false);
  
  // Build the map of views
  this->lookup = new std::map<std::string, QFractalView*>;
  std::pair<std::string, QFractalView *> pair;

  std::string mandelbrot_string ("mandelbrot");
  pair.first = mandelbrot_string;
  pair.second = mandelbrot_view;
  this->lookup->insert(pair);

  std::string julia_string ("julia");
  pair.first = julia_string;
  pair.second = julia_view;
  this->lookup->insert(pair);

  this->choose("mandelbrot");
}

FractalViewManager::~FractalViewManager()
{
  delete this->lookup;
}

QFractalView * FractalViewManager::getCurrent()
{
  return this->current;
}

void FractalViewManager::choose(const char* fview_name)
{
  std::string s (fview_name);
  this->choose(s);
}

void FractalViewManager::choose(std::string fview_name)
{
  std::map<std::string, QFractalView *>::iterator it;
  it = this->lookup->find(fview_name);

  if (it != this->lookup->end()) {
    this->current = it->second;
  }
}
