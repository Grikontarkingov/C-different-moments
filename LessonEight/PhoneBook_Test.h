#pragma once

#ifndef LESSONEONE_PHONEBOOK_TEST_H
#define LESSONEONE_PHONEBOOK_TEST_H

#include "PhoneBook.h"
#include "gtest/gtest.h"
class PhoneBook_Test : public testing::Test{
protected:
    void SetUp() override;

    void TearDown() override;

    PhoneBook::PhoneBook *phoneBookTest;
};

#endif //LESSONEONE_PHONEBOOK_TEST_H
