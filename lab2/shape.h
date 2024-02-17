#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class shape {
public:
    shape(std::string color);
    virtual double GetArea() const = 0;
    const double GetCount() const;
    virtual std::string GetShapeName() const = 0;
    std::string GetColour() const;

    std::string colour;
private:
    static int count;
};

#endif