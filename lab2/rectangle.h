#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class rectangle : public shape {
public:
    rectangle(std::string colour, double base, double height);
    double GetArea() const override;
    std::string GetShapeName() const;

protected:
    double base;
    double height;

};

#endif