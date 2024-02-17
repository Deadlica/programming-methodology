#include "rectangle.h"

rectangle::rectangle(std::string colour, double base, double height)
:shape(colour), base(base), height(height) {}

double rectangle::GetArea() const {
    return base * height;
}

std::string rectangle::GetShapeName() const {
    return "Rectangle";
}