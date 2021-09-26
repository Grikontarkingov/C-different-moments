#include <fstream>
#include "PhoneBook.h"

int main() {
    std::ifstream in("F:\\GBTest\\CLion\\LessoneOne\\cmake-build-debug\\PhoneBook.txt");

    PhoneBook phoneBook(in);
    std::cout << phoneBook;

    std::cout << "------SortByPhone-------" << std::endl;
    phoneBook.SortByName();
    std::cout << phoneBook;

    std::cout << "------SortByName--------" << std::endl;
    phoneBook.SortByPhone();
    std::cout << phoneBook;

    auto print_phone_number = [&phoneBook](const std::string& surname) {
        std::cout << surname << "\t";
        auto answer = phoneBook.GetPhoneNumber(surname);
        if (std::get<0>(answer).empty())
            std::cout << std::get<1>(answer);
        else
            std::cout << std::get<0>(answer);
        std::cout << std::endl;
    };

    print_phone_number("Ivanov");
    print_phone_number("Petrov");
    print_phone_number("Solovev");

    std::cout << "----ChangePhoneNumber----" << std::endl;
    phoneBook.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },PhoneNumber{7, 123, "15344458", std::nullopt});
    phoneBook.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" }, PhoneNumber{ 16, 465, "9155448", 13 });
    std::cout << phoneBook;


    return 0;
}