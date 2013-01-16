#ifndef EVALUATOR_HH
#define EVALUATOR_HH

#include "result.hh"

class Evaluator
{
public:
  virtual double eval(Result *result)=0;
};

#endif
