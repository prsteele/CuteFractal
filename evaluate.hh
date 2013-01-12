#ifndef EVALUATE_HH
#define EVALUATE_HH

#include "result.hh"

/*
  Take a Result object, a maximum number of iterations, and a maximum
  radius, and compute a [0, 1] value. 1 should indicate set
  membership.
*/
typedef double Evaluator(Result *, int, double);

/*
  We now define some evaluators.
 */

double linear_interpolation(Result *res, int max_iterations, double max_radius);

#endif
