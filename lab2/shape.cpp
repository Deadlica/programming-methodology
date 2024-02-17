#include "shape.h"

int shape::count = 0;

shape::shape(std::string colour):colour(colour) {
    count++;
}

const double shape::GetCount() const {
    return count;
}

std::string shape::GetColour() const {
    return colour;
}