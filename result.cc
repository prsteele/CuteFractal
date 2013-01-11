#include "result.hh"

Result::Result()
{
  this->iterations = 0;
  this->radius = 0;
}

Result::Result(int iterations, double radius)
{
  this->iterations = iterations;
  this->radius = radius;
}
