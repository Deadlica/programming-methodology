#include "person.h"

person::person(std::string name, double age):name(name), age(age) {}

bool operator==(const person& lhs, const person& rhs) {
    return lhs.name == rhs.name;
}

std::ostream& operator<<(std::ostream& out, person p) {
    return out << "Age = " << p.age << ", Name = " << p.name;
}

const std::string person::GetName() const {
    return name;
}
const double person::GetAge() const {
    return age;
}