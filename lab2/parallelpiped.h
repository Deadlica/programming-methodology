#ifndef PARALLELPIPED_H
#define PARALLELPIPED_H

#include "rectangle.h"

class parallelpiped : public rectangle {
public:
    parallelpiped(std::string colour, double base, double height, double depth);
    double GetArea() const;
    std::string GetShapeName() const;
    
private:
    double depth;
};

#endif