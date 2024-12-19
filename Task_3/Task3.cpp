#include <iostream>
#include <string>
#include <algorithm>
#include "/Users/personal/Documents/453504/ОАиП/LR7/source/header.h"
typedef long long ll;
const std::string ascii_end =  "\x1b[0m";
const std::string ascii_green = "\x1b[0;32m";
int main() {
    std::string final;
    ll number1, number2;
    char sign;
    short base;
    std::cout << "Введите систему исчисления: ";
    std::cin >> base;
    if (base < 2 || base > 36) {std::cout << "Система исчисления должна быть в диапазаоне от 2 до 36";}
    else {
        std::cout << "В выбранной системе исчисления присутствуют следующие символы: " << ascii_green << base_symbols.substr(0,base) << ascii_end;
        std::cout << "\n\nВведите первое число в десятичной форме: ";
        std::cin >> number1;
        std::cout << "Введите второе число в десятичной форме: ";
        std::cin >> number2;
        std::cout << "Хотите сложить(напишите +), вычесть(любой другой символ(-)): ";
        std::cin >> sign;
        std::cout << "\nПервое число в данной системе исчисления - " << convert_to_any_base(number1,base);
        std::cout << "\nВторое число в данной системе исчисления - " << convert_to_any_base(number2,base);
        if (sign == '+') {
            if (number1 >= 0 && number2 >= 0) {
                final = add_in_base(convert_to_any_base(number1,base),convert_to_any_base(number2,base),base);
            } else if (number1 >= 0 && number2 <0) {
                final = subtract_in_base(convert_to_any_base(number1,base),convert_to_any_base(number2*-1,base),base,number1,number2*-1);
            } else if (number1 < 0 && number2 >= 0) {
                final = subtract_in_base(convert_to_any_base(number2,base),convert_to_any_base(number1*-1,base),base,number2,number1*-1);
            } else if (number1 < 0 && number2 < 0) {
                final = "-" + add_in_base(convert_to_any_base(number1*-1,base),convert_to_any_base(number2*-1,base),base);
            }
        std::cout << "\nСумма ваших чисел в данной системе исчисления - " << final;
        } else {
            if (number1 >= 0 && number2 >= 0) {
                final = subtract_in_base(convert_to_any_base(number1,base),convert_to_any_base(number2,base),base,number1,number2);
            } else if (number1 >= 0 && number2 <0) {
                final = add_in_base(convert_to_any_base(number1,base),convert_to_any_base(number2*-1,base),base);
            } else if (number1 < 0 && number2 >= 0) {
                final = "-" + add_in_base(convert_to_any_base(number1*-1,base),convert_to_any_base(number2,base),base);
            } else if (number1 < 0 && number2 < 0) {
                final = subtract_in_base(convert_to_any_base(number2*-1,base),convert_to_any_base(number1*-1,base),base,number2*-1,number1*-1);
            }
        std::cout << "\nРазность ваших чисел в данной системе исчисления - " << final;
        }
    }
    return 0;
}