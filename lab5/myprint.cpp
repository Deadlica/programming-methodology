#include "myprint.h"

struct agePredicate {
    bool operator()(const person& p) {
        return p.GetAge() > 22.0;
    }
};

void MyPrint::operator()(std::vector<person> people) {
    for(auto e: people) {
        std::cout << e << std::endl;
    }
    return;
}

void MyPrint::for_each_print(std::vector<person> people) {
    auto print = [](const person& p) {std::cout << p << std::endl;};
    std::for_each(people.begin(), people.end(), print);
}

void MyPrint::find_if_print(std::vector<person> people) {
    auto firstPersonFound = std::find_if(people.begin(), people.end(), agePredicate());
    std::cout << firstPersonFound->GetName() << ", " << firstPersonFound->GetAge() << std::endl;
}

void MyPrint::adjacent_find_print(std::vector<person> people) {
    auto match = [](person lhs, person rhs) {return lhs.GetAge() == rhs.GetAge();};
    auto firstOfPair = std::adjacent_find(people.begin(), people.end(), match);
    std::cout << "The matching pair is " << firstOfPair->GetName() <<
    std::endl << "Which is found at index " << std::distance(people.begin(), firstOfPair) << std::endl;
}

void MyPrint::search_print(std::vector<person> people, person* first, person* last) {
    std::string s = "Marcus";
    auto it = std::search(people.begin(), people.end(), first, last);
    for(int i = 0; i <= std::distance(first, last); i++) {
        std::cout << *(it + i) << std::endl;
    }
}