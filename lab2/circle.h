#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <cmath>

class circle : public shape {
public:
    circle(std::string colour, double radius);
    double GetArea() const override;
    std::string GetShapeName() const;

protected:
    double radius;
    static constexpr auto PI = M_PI;
};

#endif