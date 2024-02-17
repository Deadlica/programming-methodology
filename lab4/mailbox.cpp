#include "mailbox.h"

void MailBox::print() const {
    for(auto e: m_MailBox) {
        std::cout << e;
    }
}

void MailBox::addMail(Email e) {
    m_MailBox.push_back(e);
}

Email MailBox::operator[](size_t index) {
    return m_MailBox[index];
}

void MailBox::SortWho() {
    std::sort(m_MailBox.begin(), m_MailBox.end(), CompWhoDateSubject());
}

void MailBox::SortDate() {
    std::sort(m_MailBox.begin(), m_MailBox.end(), CompDateWhoSubject());
}

void MailBox::SortSubject() {
    std::sort(m_MailBox.begin(), m_MailBox.end(), CompSubjectWhoDate());
}