#include "palette.hh"

unsigned int Palette::toARGB(int a, int r, int g, int b)
{
  return (a << 24) + (r << 16) + (g << 8) + b;
  
}

unsigned int Palette::toARGB(double a, double r, double g, double b)
{
  return this->toARGB((int) (a * 0xFF), (int) (r * 0xFF),
		      (int) (g * 0xFF), (int) (b * 0xFF));
}
