#ifndef ROUNDED_RECTANGLE_H
#define ROUNDED_RECTANGLE_H

#include "rectangle.h"
#include <cmath>

class rounded_rectangle : public rectangle {
public:
    rounded_rectangle(std::string colour, double base, double height, double radius);
    double GetArea() const;
    std::string GetShapeName() const;
    
private:
    double radius;
    static constexpr auto PI = M_PI;

};

#endif