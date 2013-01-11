#include "evaluate.hh"

double linear_interpolation(Result *res, int max_iterations, double max_radius)
{
  return res->iterations / max_iterations;
}
