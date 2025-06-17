#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string text;
    std::cout << "Введите строку: ";
    std::getline(std::cin, text);

    std::regex pattern(R"(\+7-\d{3}-\d{3}-\d{2}-\d{2})");
    bool found = false;

    auto begin = std::sregex_iterator(text.begin(), text.end(), pattern);
    auto end = std::sregex_iterator();
    for (auto it = begin; it != end; ++it) {
        std::cout << "Найдено: " << it->str() << std::endl;
        found = true;
    }
    if (!found)
        std::cout << "Совпадений не найдено." << std::endl;

    return 0;
}
