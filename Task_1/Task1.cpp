#include "/Users/personal/Documents/453504/ОАиП/LR7/source/header.h"
#include <iostream>
#include <string>
int main() {
    std::string str;
    std::cout << "Введите число в виде прямого кода, учитывая следующий формат - 'знак числа(1 если -, 0 если +) + '0' + число в двоичном виде:\n";
    std::cin >> str;
    std::cout << "Исходное число " << str << " будет в обратном коде так:\n" << convert_to_reverse(str) << std::endl;
    return 0;
}