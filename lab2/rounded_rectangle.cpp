#include "rounded_rectangle.h"

rounded_rectangle::rounded_rectangle(std::string colour, double base, double height, double radius)
:rectangle(colour, base, height), radius(radius) {}

double rounded_rectangle::GetArea() const {
    return base * height - radius * radius * (4 - PI);
}

std::string rounded_rectangle::GetShapeName() const {
    return "Rounded Rectangle";
}