#include <iostream>
#include "person.h"
#include "myprint.h"
#include <numeric>

double meanAccumulatePersons(std::vector<person> people);
std::vector<double> personAgeVector(std::vector<person> people);
void v2ReplaceValues(std::vector<double>& v2, double mean);
void sortAndPrintV2(std::vector<double> v2);

struct MyBinOp {
    double operator()(double initValue, person p) {
        return initValue + p.GetAge();
    }
};

struct MyUnOp {
    double operator()(person p) {
        return p.GetAge();
    }
};

struct MyFunc {
    double mean;
    double operator()(double age) {
        return age - mean;
    }
};

int main() {
    system("clear");
    person peopleArr[] = {{"Samuel Greenberg", 21.8},
                          {"Can Kupeli", 23.1},
                          {"Hossen Mansour", 22.4},
                          {"Samuel Greenberg", 21.8},
                          {"Samuel Greenberg", 21.8},
                          {"Marcus Jakobsson", 20.1},
                          {"Karl Backan", 20.5},
                          {"Angelica Engström", 22.7}};
    auto peopleArrLast = peopleArr + 8;

    std::vector<person> people(peopleArr, peopleArrLast);
    MyPrint printer;

    printer.for_each_print(people); //Step 1
    std::cout << std::endl;

    printer.find_if_print(people); //Step 2
    std::cout << std::endl;

    printer.adjacent_find_print(people); //Step 3
    std::cout << std::endl;

    if(std::equal(peopleArr, peopleArrLast, people.begin(), people.end())) { //Step 4
        std::cout << "peopleArr and people have the same contents" << std::endl << std::endl;
    }
    else {
        std::cout << "peopleArr and people do not have the same contents" << std::endl << std::endl;
    }

    printer.search_print(people, peopleArr, peopleArr + 3); //Step 5
    std::cout << std::endl;

    double mean = meanAccumulatePersons(people);
    std::cout << mean << std::endl << std::endl; //Step 6

    std::vector<double> v2 = personAgeVector(people); //Step 7
    for(auto e: v2) {
        std::cout << e << ", ";
    }
    std::cout << std::endl << std::endl;

    v2ReplaceValues(v2, mean); //Step 8
    for(auto e: v2) {
        std::cout << e << ", ";
    }
    std::cout << std::endl << std::endl;

    sortAndPrintV2(v2); //Step 9

    return 0;
}

double meanAccumulatePersons(std::vector<person> people) {
    double sum = std::accumulate(people.begin(), people.end(), 0, MyBinOp());
    double mean = sum / (people.end() - people.begin());
    return mean;
}


std::vector<double> personAgeVector(std::vector<person> people) {
    std::vector<double> v2(people.size());
    std::transform(people.begin(), people.end(), v2.begin(), MyUnOp());
    return v2;
}

void v2ReplaceValues(std::vector<double>& v2, double mean) {
    std::transform(v2.begin(), v2.end(), v2.begin(), MyFunc() = {mean});
}

void sortAndPrintV2(std::vector<double> v2) {
    std::sort(v2.begin(), v2.end());
    for(auto e: v2) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}