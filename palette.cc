#include "palette.hh"

unsigned int bw_cutoff(double value)
{
  if (value < .5) {
    return 0xFFFFFFFF;
  }
  else {
    return 0xFF000000;
  }
}
