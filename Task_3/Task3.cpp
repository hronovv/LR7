#include <iostream>
#include <string>
#include <algorithm>
#include "/Users/personal/Documents/453504/ОАиП/LR7/source/header.h"
typedef long long ll;
const std::string ascii_end =  "\x1b[0m";
const std::string ascii_green = "\x1b[0;32m";
std::string add_in_base(const std::string& num1, const std::string& num2, short base) {
    std::string result;
    int carry = 0;
    int maxLength = std::max(num1.size(), num2.size());
    for (int i = 0; i < maxLength || carry; i++) {
        int digit1 = (i < num1.size()) ? base_symbols.find(num1[num1.size() - 1 - i]) : 0;
        int digit2 = (i < num2.size()) ? base_symbols.find(num2[num2.size() - 1 - i]) : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / base;
        result += base_symbols[sum % base];
    }
    std::reverse(result.begin(), result.end());
    return result;
}
std::string subtract_in_base(const std::string& num1, const std::string& num2, short base, ll number1, ll number2) {
    if (number2 > number1) {
        return "-" + subtract_in_base(num2, num1,base,number2,number1);
    }
    std::string result;
    int difference;
    int borrow = 0;
    int maxLength = std::max(num1.size(), num2.size());
    for (int i = 0; i < maxLength; i++) {
        int digit1 = (i < num1.size()) ? base_symbols.find(num1[num1.size() - 1 - i]) : 0;
        int digit2 = (i < num2.size()) ? base_symbols.find(num2[num2.size() - 1 - i]) : 0;
        digit1 -= borrow;
        if (digit1 < digit2) {
            digit1 += base;
            borrow = 1;
        } else {
            borrow = 0;
        }
        difference = digit1 - digit2;
        result += base_symbols[difference];
    }
    while (result.size() > 1 && result.back() == base_symbols[0]) {
        result.pop_back();
    }
    std::reverse(result.begin(), result.end());
    return result;
}
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