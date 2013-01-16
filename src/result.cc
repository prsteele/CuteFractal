#include "result.hh"

Result::Result()
{
  this->iterations = 0;
  this->radius = 0;
  this->max_iterations = 1;
  this->max_radius = 1;
}

Result::Result(int iterations, double radius,
	       int max_iterations, double max_radius)
{
  this->iterations = iterations;
  this->radius = radius;
  this->max_iterations = max_iterations;
  this->max_radius = max_radius;
}
