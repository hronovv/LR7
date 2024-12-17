#include <iostream>
#include <string>
#include <algorithm>
#include "/Users/personal/Documents/453504/ОАиП/LR7/source/header.h"
typedef unsigned long long ull;
typedef long long ll;
int main() {
    std::string digit_str1;
    std::string digit_str2;
    std::cout << "Введи число 1: ";
    std::cin >> digit_str1;
    std::cout << "Введи число 2: ";
    std::cin >> digit_str2;
    if (digit_str1 == "-0") {
        digit_str1 = "0";
    }
    if (digit_str2 == "-0") {
        digit_str2 = "0";
    }
    if (digit_str1 == "0" && digit_str2 == "0") {
        std::cout << "Сумма двух нулей(неважно какого знака) в прямом коде - " << "00";
    }
    else {
        std::string binary1 = binary_converting(digit_str1);
        std::string binary2 = binary_converting(digit_str2);
        auto [binary1_1, binary2_2] = equalize_lengths(binary1, binary2);
        std::cout << "Число " << digit_str1 << " в прямом коде : " << binary1_1 << std::endl;
        std::cout << "Число " << digit_str2 << " в прямом коде : " << binary2_2 << std::endl;
        binary1_1 = convert_to_complement(convert_to_reverse(binary1_1));
        binary2_2 = convert_to_complement(convert_to_reverse(binary2_2));
        std::cout << "Число " << digit_str1 << " в дополнительном коде : " << binary1_1 << std::endl;
        std::cout << "Число " << digit_str2 << " в дополнительном коде : " << binary2_2 << std::endl;
        std::string sum = add(binary1_1,binary2_2);
        std::cout << "Сумма чисел " << digit_str1 << " и " << digit_str2 << " в дополнительном коде - " << sum << std::endl;
        std::cout << "Сумма чисел " << digit_str1 << " и " << digit_str2 << ", переведенная из доп. кода в прямой - " << back_convert(compelement_to_reverse(sum));
    }
    return 0;
}