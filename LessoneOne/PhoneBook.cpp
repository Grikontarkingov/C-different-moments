#include "PhoneBook.h"

PhoneBook::PhoneBook(std::ifstream& file){
    if(file.is_open()){
        InsertToPhoneBook(file);
    }
}

void PhoneBook::InsertToPhoneBook(std::ifstream& file){
    std::string line;
    while(std::getline(file, line)){
        std::istringstream issLine(line);
        Person person;
        person.SetPerson(issLine);
        PhoneNumber phoneNumber;
        phoneNumber.SetPhoneNumber(issLine);

        m_phoneBook.push_back(std::make_pair(person, phoneNumber));
    }
}

void PhoneBook::SortByName(){
    std::sort(m_phoneBook.begin(), m_phoneBook.end(),
              [](std::pair<Person, PhoneNumber>& current, std::pair<Person, PhoneNumber>& next){return current.first < next.first;});
}


void PhoneBook::SortByPhone(){
    std::sort(m_phoneBook.begin(), m_phoneBook.end(),
              [](std::pair<Person, PhoneNumber>& current, std::pair<Person, PhoneNumber>& next){return current.second < next.second;});
}

std::tuple<std::string, PhoneNumber> PhoneBook::GetPhoneNumber(const std::string& surname){
    std::tuple<std::string, PhoneNumber> out;
    std::string text;
    int count = 0;

    for(auto& sN : m_phoneBook){
        if(sN.first.GetSurname() == surname){
            count++;
            std::get<1>(out) = sN.second;
        }
    }

    if(count == 1){
        return out;
    }
    else if(count > 1){
        std::get<0>(out) = "found more than 1";
        return out;
    }
    else{
        std::get<0>(out) = "not found";
        return out;
    }
}

std::ostream& operator<< (std::ostream& out, PhoneBook& phoneBook){
    for(auto& pB : phoneBook.m_phoneBook){
        out << pB.first << " " << pB.second << std::endl;
    }

    out << std::endl;

    return out;
}