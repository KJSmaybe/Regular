#include <iostream>
#include <string>
#include <regex>
#include <set>

bool has_two_diff_specials(const std::string& str) {
    std::set<char> specials;
    for (char c : str) {
        if (std::string("^$%*@#!?'").find(c) != std::string::npos)
            specials.insert(c);
    }
    return specials.size() >= 2;
}

int main() {
    std::string password;
    std::cout << "Введите пароль: ";
    std::getline(std::cin, password);

    std::regex pattern(R"(^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[\^$%*@#!\?'])(?!.*(.)\1)[A-Za-z\d\^$%*@#!\?']{8,}$)");

    if (std::regex_match(password, pattern) && has_two_diff_specials(password))
        std::cout << "Корректный пароль!" << std::endl;
    else
        std::cout << "Некорректный пароль." << std::endl;

    return 0;
}
