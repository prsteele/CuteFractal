#ifndef LINEAR_INTERPOLATOR_HH
#define LINEAR_INTERPOLATOR_HH

#include "evaluator.hh"
#include "result.hh"

class LinearInterpolator : public Evaluator
{
public:
  LinearInterpolator();
  ~LinearInterpolator();

  virtual double eval(Result *result);
};

#endif
