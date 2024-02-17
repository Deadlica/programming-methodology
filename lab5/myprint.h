#ifndef MYPRINT_H
#define MYPRINT_H

#include "person.h"
#include <vector>
#include <algorithm>

class MyPrint {
public:
    void operator()(std::vector<person> people);
    void for_each_print(std::vector<person> people);
    void find_if_print(std::vector<person> people);
    void adjacent_find_print(std::vector<person> people);
    void search_print(std::vector<person> people, person* first, person* last);

private:


};

struct agePredicate;

#endif