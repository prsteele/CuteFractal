#ifndef EVALUATOR_MANAGER_HH
#define EVALUATOR_MANAGER_HH

#include "evaluator.hh"

class EvaluatorManager
{
public:
  EvaluatorManager();
  ~EvaluatorManager();

  Evaluator *linear_interpolator;
};

#endif
