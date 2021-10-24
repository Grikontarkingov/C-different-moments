#include "PhoneBook_Test.h"
void PhoneBook_Test::SetUp(){
    phoneBookTest = new PhoneBook::PhoneBook("Kozlovskii Artem Daniilovich", "81 8281 7420182 1");
}

void PhoneBook_Test::TearDown(){
    delete phoneBookTest;
}