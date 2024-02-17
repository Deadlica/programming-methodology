#include "parallelpiped.h"

parallelpiped::parallelpiped(std::string colour, double base, double height, double depth)
:rectangle(colour, base, height), depth(depth) {}

double parallelpiped::GetArea() const {
    return base * height * depth;
}

std::string parallelpiped::GetShapeName() const {
    return "Parallelpiped";
}