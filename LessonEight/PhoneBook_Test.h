#pragma once

#ifndef _PHONEBOOK_TEST_H
#define _PHONEBOOK_TEST_H

#include "PhoneBook.h"
#include "gtest/gtest.h"

class PhoneBook_Test : public testing::Test{
protected:
    void SetUp() override{
        personTest = new PhoneBook::Person("Kozlovskii", "Artem", "Daniilovich");
        phoneNumberTest = new PhoneBook::PhoneNumber(81, 8281, "7420182", 1);
        phoneBookTest = new PhoneBook::PhoneBook("Kozlovskii Artem Daniilovich", "81 8281 7420182 1");
    }

    void TearDown() override{
        delete phoneBookTest;
        delete personTest;
        delete phoneNumberTest;
    }

    PhoneBook::PhoneNumber *phoneNumberTest;
    PhoneBook::Person *personTest;
    PhoneBook::PhoneBook *phoneBookTest;
};

TEST_F(PhoneBook_Test, FullName){
    char const *surname = "Kozlovskii";
    char const *name = "Artem";
    char const *patronymic = "Daniilovich";
    ASSERT_STREQ(personTest->GetSurname().c_str(), surname);
    ASSERT_STRNE(personTest->GetSurname().c_str(), name);
    ASSERT_STREQ(personTest->GetName().c_str(), name);
    ASSERT_STRNE(personTest->GetName().c_str(), surname);
    ASSERT_STREQ(personTest->GetPatronymic().c_str(), patronymic);
    ASSERT_STRNE(personTest->GetPatronymic().c_str(), surname);
}

#endif //_PHONEBOOK_TEST_H
