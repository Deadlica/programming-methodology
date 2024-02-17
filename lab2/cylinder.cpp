#include "cylinder.h"

cylinder::cylinder(std::string colour, double radius, double height)
:circle(colour, radius), height(height) {}

double cylinder::GetArea() const {
    return PI * radius * radius * height;
}

std::string cylinder::GetShapeName() const {
    return "Cylinder";
}