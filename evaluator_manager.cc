#include "evaluator_manager.hh"
#include "linear_interpolator.hh"

EvaluatorManager::EvaluatorManager()
{
  this->linear_interpolator = new LinearInterpolator;
}

EvaluatorManager::~EvaluatorManager()
{
  delete this->linear_interpolator;
}

