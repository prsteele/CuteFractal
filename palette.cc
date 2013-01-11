#include "palette.hh"

int bw_cutoff(double value)
{
  if (value < .5) {
    return 0xFF000000;
  }
  else {
    return 0xFFFFFFFF;
  }
}
