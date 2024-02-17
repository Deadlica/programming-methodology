#include "email.h"

Email::Email(std::string who, std::string date, std::string subject)
:who(who), date(date), subject(subject){}


std::ostream& operator<<(std::ostream& out, Email e) {
    return out << "Who = " << e.who << ", Date = " << e.date << ", Subject = " << e.subject << std::endl;
}