#include "email.h"
#include "mailbox.h"



int main() {
    system("clear");
    MailBox list;
    list.addMail(Email("Anders", "2002-02-28", "lab 2"));
    list.addMail(Email("Anders", "2002-02-28", "lab 2"));
    list.addMail(Email("Hossen", "2004-02-28", "lab 6"));
    list.addMail(Email("Marcus", "2002-02-28", "lab 1"));
    list.addMail(Email("Samuel", "2009-02-28", "lab 2"));
    list.addMail(Email("Anders", "2002-02-28", "lab 2"));
    list.addMail(Email("An98ders", "2002-02-28", "lab 2"));

    list.print();

    std::cout << std::endl;

    list.SortSubject();

    list.print();
    
    return 0;
}