#ifndef EMAIL_H
#define EMAIL_H

#include <string>
#include <iostream>

class Email {
public:
    Email(std::string who, std::string date, std::string subject);

    friend std::ostream& operator<<(std::ostream& out, Email e);

    friend struct CompWhoDateSubject;
    friend struct CompDateWhoSubject;
    friend struct CompSubjectWhoDate;
    friend struct CompWDS;

private:
    std::string who;
    std::string date;
    std::string subject;
};

struct CompWDS {
    Email lhs, rhs;
    bool result = false;
    bool resolved = false;

    CompWDS(Email lhs, Email rhs):lhs(lhs), rhs(rhs) {}

    operator bool() {
        return result;
    }

    void updateBools(std::string lhs, std::string rhs) {
        result = lhs < rhs;
        resolved = lhs != rhs;
    }

    CompWDS& who(){
        if(!resolved) {
            updateBools(lhs.who, rhs.who);
        }
        return *this;
    }

    CompWDS& date(){
        if(!resolved) {
            updateBools(lhs.date, rhs.date);
        }
        return *this;
    }

    CompWDS& subject(){
        if(!resolved) {
            updateBools(lhs.subject, rhs.subject);
        }
        return *this;
    }
};

struct CompWhoDateSubject {
    bool operator()(Email lhs, Email rhs) {
        CompWDS compare(lhs, rhs);
        return compare.who().date().subject();
    }
};

struct CompDateWhoSubject {
    bool operator()(Email lhs, Email rhs) {
        CompWDS compare(lhs, rhs);
        return compare.date().who().subject();
    }
};

struct CompSubjectWhoDate {
    bool operator()(Email lhs, Email rhs) {
        CompWDS compare(lhs, rhs);
        return compare.subject().who().date();
    }
};

#endif