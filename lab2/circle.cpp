#include "circle.h"

circle::circle(std::string colour, double radius): shape(colour), radius(radius) {}

double circle::GetArea() const {
    return PI * radius * radius;
}

std::string circle::GetShapeName() const {
    return "Circle";
}