#include "header.h"
#include <iostream>
#include <string>
int main() {
    std::string str;
    std::cout << "Введите число в виде прямого кода, учитывая следующий формат - 'знак числа(1 если -, 0 если +) + '0' + число в двоичном виде:\n";
    std::cin >> str;
    std::cout << "Исходное число " << str << " будет в дополнительном коде так:\n" << convert_to_complement(str) << std::endl;
    return 0;
}
