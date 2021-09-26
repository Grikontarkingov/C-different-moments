#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H
#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>
#include "Person.h"
#include "PhoneNumber.h"


class PhoneBook {
public:
    PhoneBook(std::ifstream& file);

    void SortByName();
    void SortByPhone();

    std::tuple<std::string, PhoneNumber> GetPhoneNumber(const std::string& surname);
    void ChangePhoneNumber(const Person& person, const PhoneNumber& phoneNumber){
        auto result = std::find_if(m_phoneBook.begin(), m_phoneBook.end(), [&person](std::pair<Person, PhoneNumber>& found){
            return found.first == person;
        });

        if(!(result == m_phoneBook.end())){
            result->second = phoneNumber;
        }
    }


    friend std::ostream& operator<< (std::ostream& out, PhoneBook& phoneBook);

private:
    std::vector<std::pair<Person, PhoneNumber>> m_phoneBook;

    void InsertToPhoneBook(std::ifstream& file);
};

std::ostream& operator<< (std::ostream& out, PhoneBook& phoneBook);


#endif //_PHONEBOOK_H
