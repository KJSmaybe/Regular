#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string text;
    std::cout << "Введите строку: ";
    std::getline(std::cin, text);

    std::regex pattern(R"([А-Яа-яЁё])");
    if (std::regex_search(text, pattern))
        std::cout << "В строке есть русские буквы!" << std::endl;
    else
        std::cout << "Русских букв не найдено." << std::endl;

    return 0;
}
