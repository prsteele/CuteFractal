#ifndef ITERATED_FRACTAL_HH
#define ITERATED_FRACTAL_HH

#include "evaluate.hh"
#include "palette.hh"
#include "viewport.hh"

class IteratedFractal
{
public:

  IteratedFractal(int max_iterations, double max_radius);

  /*
    Render the fractal for the given viewport and image size, storing
    the results in an array of integers of length im_width *
    im_height, where each pixel is stored as a RGBA sequence. Index 0
    corresponds to the top left pixel, and indices increase across
    columns then down rows.
   */
  void render(Viewport *viewport, int im_width, int im_height,
	      Evaluator eval, Palette palette, int **image);

protected:

  int max_iterations;
  double max_radius;

  /*
    Iterate the given point in the complex plane, storing the results
    in the result object.
   */
  virtual void iterate_point(double x, double y, Result *result)=0;
};

#endif
