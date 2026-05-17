#pragma once
#include <iostream>
class Color {
  public:
    Color();
    Color(double red, double green, double blue);
    double red() const;
    double green() const;
    double blue() const;

  
    double r{};
    double g{};
    double b{};
};


inline std::istream& operator>>(std::istream& stream, Color& c)
{
  return stream >> c.r >> c.g >> c.b;
}