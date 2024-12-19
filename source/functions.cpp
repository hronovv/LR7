#include "header.h"
#include <iostream>
#include <algorithm>
#include <string>
typedef unsigned long long ull;
typedef long long ll;
std::string back_convert(const std::string& bin_str) {
    if (bin_str[0] == '0') { return bin_str; }
    std::string number = bin_str.substr(1);  
    for (char &bit : number)
        bit^=1;
    return "1"+number;
}
std::string compelement_to_reverse(const std::string& bin_str) {
    if (bin_str[0] == '0') { return bin_str; } 
    std::string invertedCode = bin_str;
    for (int i = bin_str.length() - 1; i >= 0; --i) {
        if (bin_str[i] == '1') {
            invertedCode[i] = '0';
            break;
        } else {
            invertedCode[i] = '1';
        }
    }
    return invertedCode;
}
std::string add(const std::string& num1, const std::string& num2) {
    std::string result(num1.length(), '0');
    bool carry = false;
    for (int i = num1.length() - 1; i >= 0; --i) {
        bool bit1 = num1[i] == '1';
        bool bit2 = num2[i] == '1';
        bool sum = bit1 ^ bit2 ^ carry;
        carry = (bit1 && bit2) || (carry && (bit1 || bit2));
        result[i] = sum ? '1' : '0';
    }
    return result; 
}
std::string pad_with_zeros(const std::string& bin_str, size_t target_length) {
    if (bin_str.length() >= target_length) {
        return bin_str; 
    }
    size_t zeros_to_add = target_length - bin_str.length();
    std::string padded_str = bin_str;
    std::string number_part = padded_str.substr(1);
    padded_str = padded_str[0] + std::string(zeros_to_add, '0') + number_part; 
    return padded_str;
}
std::pair<std::string, std::string> equalize_lengths(const std::string& num1, const std::string& num2) {
    size_t max_length = std::max(num1.length(), num2.length());
    std::string padded_num1 = pad_with_zeros(num1, max_length);
    std::string padded_num2 = pad_with_zeros(num2, max_length);
    return {padded_num1, padded_num2}; 
}
std::string convert_to_reverse(const std::string& bin_str) {
    if (bin_str.length() < 3 || (bin_str[0] != '0' && bin_str[0] != '1') || (bin_str.find_first_not_of("01") != std::string::npos)) {
        return "Число в прямом коде введено неверным образом";}
    if (bin_str[0] == '0') { return bin_str; }
    std::string number = bin_str.substr(1);  
    for (char &bit : number)
        bit^=1;
    return "1"+number;
}
std::string convert_to_complement(const std::string& bin_str) {
    if (bin_str[0] == '0') { return bin_str; }
    std::string complement = bin_str.substr(1);  
    bool carry = true; 
    for (int i = complement.length() - 1; i >= 0; --i) {
        if (carry) {
            if (complement[i] == '0') {
                complement[i] = '1'; 
                carry = false; 
            } else {
                complement[i] = '0'; 
            }
        }
    }
    if (carry) {
        complement = '1' + complement;
    }
    return "1" + complement;
}
std::string binary_converting(const std::string digit_str) {
    std::string binary = "";
    bool negative_sign = false;
    ull remainder_of_2 = 0;
    std::string number_no_sign = digit_str;
    if (digit_str[0] == '-') {
        negative_sign = true;
        number_no_sign = digit_str.substr(1); 
    }
    std::string temp = number_no_sign;
    while (temp != "0") {
        remainder_of_2 = 0;
        std::string newTemp = "";
        for (auto digit : temp) {
            ll current = remainder_of_2 * 10 + (digit - '0');
            newTemp += (current / 2) + '0';
            remainder_of_2 = current % 2;
        }
        while (newTemp.length() > 1 && newTemp[0] == '0') {
            newTemp.erase(0, 1);
        }
        binary.push_back(remainder_of_2 + '0');
        temp = newTemp;
    }
    std::reverse(binary.begin(), binary.end());
    if (negative_sign) { binary = "10" + binary; } 
    else { binary = "00" + binary;}
    return binary;
}
bool is_divide(long long num, long long divider) 
{
    long long magic_num = (divider + 1) >> 1;
    if (num < 0)
        num = ~num + 1;
    while (num > divider)
    {
        if ((bool)(num & 1))
            num = magic_num + (num >> 1);
        else
            num >>= 1;
    }
    return num == divider;
}
std::string convert_to_any_base(ll number_in_10, short base) {
    if (number_in_10 == 0) { return "0";}
    int remainder;
    std::string result = "";
    ll number_in_10_abs = std::abs(number_in_10);
    while (number_in_10_abs > 0) {
        remainder = number_in_10_abs % base;
        result = base_symbols[remainder] + result;
        number_in_10_abs /= base;
    }
    if (number_in_10 < 0) {
        result = "-" + result;
    }
    return result;
}
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
void DAY1(bool slaves[COUNT_SLAVES], const bool barrels[COUNT_BARRELS], short &count_survived) {
    std::string barrels_3 = "10000";
    for(int k = 0; k < COUNT_BARRELS; ++k) {
        for(int i = 0; i < COUNT_SLAVES; ++i) {
            if(barrels_3[i] == '0') {
                slaves[i] *= barrels[k];
            }
        }
        for(int i = 0; i < COUNT_SLAVES; ++i) {
            if(barrels_3[i] == '2') {
                barrels_3[i] = '0';
            } else {
                barrels_3[i]++;
                break;
            }
        }

    }
    std::cout << "\n\nПрошел 1-ый день...\n\n";
    for(int i = 0; i < COUNT_SLAVES; ++i) {
        if(slaves[i]) {
            count_survived++;
            std::cout << "Раб " << '<' << i+1 << '>' << " выжил\n";
        } else {
            std::cout << "Раб " << '<' << i+1 << '>' << " погиб\n";
        }
    }
}
void GET_LAST_SURVIVED(bool slaves[COUNT_SLAVES], bool last_survived[COUNT_SLAVES]) {
    for(int i = 0; i < COUNT_SLAVES; ++i) {
        if(slaves[i]) {
            last_survived[i] = true;
        } else {
            last_survived[i] = false;  
        }
    }
}
void GET_RESULT(const bool slaves[COUNT_SLAVES], bool last_survived[COUNT_SLAVES]) {
    std::string result_str;
    for(int i = 0; i < COUNT_SLAVES; ++i) {
        if(slaves[i] && last_survived[i]) {
            result_str.push_back('2');
        } else if(slaves[i] && !last_survived[i]) {
            result_str.push_back('1');
        } else {
            result_str.push_back('0');
        }
    }
    short result = 0;
    for(int k = 0; k < COUNT_SLAVES; ++k) {
        result += pow(3, k) * (result_str[k] - '0');
    }
    std::cout << "\n\nПрошел 2-ой день...\n\n";
    for(int i = 0; i < COUNT_SLAVES; ++i) {
        if(last_survived[i]) {
            std::cout << "Раб " << '<' << i+1 << '>' << " выжил\n";
        } else {
            std::cout << "Раб " << '<' << i+1 << '>' << " погиб\n";
        }
        
    }
    std::cout << "\n\nЯд находится в бочке под номером " << '[' << result << ']' << '\n';
}
void DAY2(const int num_possible_options, bool slaves[COUNT_SLAVES], const bool barrels[COUNT_BARRELS]) {
    char maybe_index_poison_3[num_possible_options][COUNT_SLAVES];
    bool last_survived[COUNT_SLAVES];
    std::vector<short> maybe_index_poison;
    std::string str_possible_options = "11111111111111111111111111111111";
    for(int k = 0; k < num_possible_options; ++k) {
        for(int i = 0; i < 32; ++i) {
            if(str_possible_options[i] == '2') {
                str_possible_options[i] = '1';
            } else {
                str_possible_options[i]++;
                break;
            }
        }
        for(int j = 0, s = 0; j < COUNT_SLAVES; ++j) {
            if(!slaves[j]) {
                maybe_index_poison_3[k][j] = '0';
            } else {
                maybe_index_poison_3[k][j] = str_possible_options[s++];
            }
        }
        
    }
    short sum = 0;
    for(int i = 0; i < num_possible_options; ++i) {
        for(int k = 0; k < COUNT_SLAVES; ++k) {
            sum += pow(3, k) * (maybe_index_poison_3[i][k] - '0');
        }
        maybe_index_poison.push_back(sum);
        sum = 0;
    }
    std::cout << "\n\nВозможно отравлены следующие бочки: ";
    for(auto i : maybe_index_poison) {
        std::cout << '[' << i << ']' << ',' << ' ';
    }
    GET_LAST_SURVIVED(slaves, last_survived);
    for(int j = 0; j < num_possible_options; ++j) {
        for(int i = 0; i < COUNT_SLAVES; ++i) {
            if(maybe_index_poison_3[j][i] == '1') {
                last_survived[i] *= barrels[maybe_index_poison[j] - 1];
            }
        }
    }
    GET_RESULT(slaves, last_survived);
}