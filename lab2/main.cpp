#include <iostream>
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "cylinder.h"
#include "parallelpiped.h"
#include "rounded_rectangle.h"
#include <vector>

void printInfo(const shape& s);
const double GetData(std::vector<shape*> cont);

int main() {
    std::vector<shape*> indirect;

    rectangle r("green", 5, 2);
    indirect.push_back(&r);
    
    circle c("red", 2);
    indirect.push_back(&c);
    
    cylinder cy("red", 2, 2);
    indirect.push_back(&cy);
    
    parallelpiped p("yellow", 2, 4, 2);
    indirect.push_back(&p);

    rounded_rectangle rr("purple", 4, 4, 1);
    indirect.push_back(&rr);

    GetData(indirect);

    return 0;
}

void printInfo(const shape& s) {
    std::cout << "Colour: " << s.GetColour() << std::endl
    << "Area: " << s.GetArea() << std::endl
    << "Shapes Created: " << s.GetCount() << std::endl;
}

const double GetData(std::vector<shape*> cont) {
    if(cont[0]->GetCount() <= cont.capacity()) {
        double totalArea = 0;
        for(auto e: cont) {
            totalArea += e->GetArea();
            std::cout << e->GetShapeName() << ": colour = " << e->GetColour() << ", area = " << e->GetArea() << std::endl;
        }
        std::cout << "Shapes created: " << cont[0]->GetCount() << std::endl
        << "Total area = " << totalArea << std::endl;
        return totalArea;
    }
    std::cerr << "Number of shapes exceed containers capacity." << std::endl;
    return -1;
}