#ifndef MAILBOX_H
#define MAILBOX_H

#include <vector>
#include <algorithm>
#include "email.h"

class MailBox {
public:
    MailBox() = default;
    void print() const;
    void addMail(Email e);
    Email operator[](size_t index);

    void SortWho();
    void SortDate();
    void SortSubject();

private:
    std::vector<Email> m_MailBox;

};

#endif