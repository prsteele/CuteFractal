#include "palette.hh"

unsigned int bw_cutoff(double value)
{
  if (value < .5) {
    return toARGB(0xFF, 0xFF, 0xFF, 0xFF);
  }
  else {
    return toARGB(0xFF, 0x0, 0x0, 0x0);
  }
}

unsigned int greyscale(double value)
{
  return toARGB((double)0xFF, 1 - value, 1 - value, 1 - value);
}

unsigned int toARGB(int a, int r, int g, int b)
{
  return (a << 24) + (r << 16) + (g << 8) + b;
  
}

unsigned int toARGB(double a, double r, double g, double b)
{
  return toARGB((int) (a * 0xFF), (int) (r * 0xFF),
		(int) (g * 0xFF), (int) (b * 0xFF));
}
