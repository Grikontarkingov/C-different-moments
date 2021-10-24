#include <fstream>
#include "PhoneBook.h"
#include "PhoneBook_Test.h"

TEST_F(PhoneBook_Test, get_methods){
    ASSERT_EQ(phoneBookTest->GetPhoneNumberTest("Kozlovskii Artem Daniilovich"), "81 8281 7420182 1");
    ASSERT_EQ(phoneBookTest->GetPersonTest("81 8281 7420182 1"), "Kozlovskii Artem Daniilovich");
}

int main() {
    std::ifstream in("PhoneBook.txt");

    PhoneBook::PhoneBook phoneBook(in);
    std::cout << phoneBook;

    /*std::cout << "------SortByPhone-------" << std::endl;
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
    phoneBook.ChangePhoneNumber(PhoneBook::Person{ "Kotov", "Vasilii", "Eliseevich" },PhoneBook::PhoneNumber{7, 123, "15344458", std::nullopt});
    phoneBook.ChangePhoneNumber(PhoneBook::Person{ "Mironova", "Margarita", "Vladimirovna" }, PhoneBook::PhoneNumber{ 16, 465, "9155448", 13 });
    std::cout << phoneBook;*/

    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}