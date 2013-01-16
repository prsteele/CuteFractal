#ifndef RESULT_HH
#define RESULT_HH

class Result
{
public:
  int iterations;
  int max_iterations;
  double radius;
  double max_radius;

  Result();
  
  Result(int iterations, double radius, int max_iterations, double max_radius);
};

#endif
