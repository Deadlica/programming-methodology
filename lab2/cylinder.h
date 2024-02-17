#ifndef CYLINDER_H
#define CYLINDER_H

#include "circle.h"

class cylinder : public circle {
public:
    cylinder(std::string colour, double radius, double height);
    double GetArea() const;
    std::string GetShapeName() const;

private:
    double height;
};

#endif