#include "evaluate.hh"

double linear_interpolation(Result *res, int max_iterations, double max_radius)
{
  return ((double)res->iterations) / ((double)max_iterations);
}
