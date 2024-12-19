#include "/Users/personal/Documents/453504/ОАиП/LR7/source/header.h"
#include <iostream>
#include <string>
int main() 
{
    long long num = 0;
    long long divider = 0;
    std::cout << "Напишите число, которое хотите поделить: ";
    std::cin >> num;
    std::cout << "Напишите делитель(простое число): ";
    std::cin >> divider;
    if (divider == 0)
    {
        std::cout << "На 0 нельзя делить!" << std::endl;
        return 0;
    }
    std::cout << "Число делимо на делитель: ";
    if (is_divide(num, divider))
        std::cout << "правда";
    else
        std::cout << "ложь";
    std::cout << std::endl;
    return 0;
}