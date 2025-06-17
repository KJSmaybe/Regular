#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string pwd;
    std::cout << "Введите пароль: ";
    std::getline(std::cin, pwd);

    // Только латинские буквы, цифры, спецсимволы ^$%*@#!?'
    std::regex allowed("^[A-Za-z0-9^$%*@#!?']+$");
    // Минимум 8 символов
    if (!std::regex_match(pwd, allowed) || pwd.size() < 8) {
        std::cout << "Некорректно (запрещённые символы или слишком коротко)!" << std::endl;
        return 0;
    }
    // Минимум одна строчная, одна заглавная, одна цифра, один спецсимвол
    std::regex re_low("[a-z]");
    std::regex re_up("[A-Z]");
    std::regex re_dig("\\d");
    std::regex re_spec("[\\^\\$%\\*@#!\\?']");
    // Нет двух одинаковых подряд
    std::regex re_dup("(.)\\1");

    if (!std::regex_search(pwd, re_low)) std::cout << "Нет строчной буквы!" << std::endl;
    else if (!std::regex_search(pwd, re_up)) std::cout << "Нет заглавной буквы!" << std::endl;
    else if (!std::regex_search(pwd, re_dig)) std::cout << "Нет цифры!" << std::endl;
    else if (!std::regex_search(pwd, re_spec)) std::cout << "Нет спецсимвола!" << std::endl;
    else if (std::regex_search(pwd, re_dup)) std::cout << "Есть повторяющиеся символы!" << std::endl;
    else std::cout << "Корректно!" << std::endl;
    return 0;
}
