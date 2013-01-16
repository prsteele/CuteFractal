#include "linear_interpolator.hh"
#include <QtGlobal>

LinearInterpolator::LinearInterpolator()
{
}

double LinearInterpolator::eval(Result *result)
{
  return ((double)result->iterations) / ((double)result->max_iterations);
}
