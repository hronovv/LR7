#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef unsigned long long ull;
typedef long long ll;
const int COUNT_BARRELS = 240;
const int COUNT_SLAVES = 5;
const std::string base_symbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string compelement_to_reverse(const std::string& bin_str);
std::string back_convert(const std::string& bin_str);
std::string add(const std::string& num1, const std::string& num2);
std::string convert_to_reverse(const std::string& bin_str);
std::string binary_converting(const std::string digit_str);
std::string convert_to_complement(const std::string& bin_str);
std::string pad_with_zeros(const std::string& bin_str, size_t target_length);
std::pair<std::string, std::string> equalize_lengths(const std::string& num1, const std::string& num2);
bool is_divide(long long num, long long divider);
std::string convert_to_any_base(ll number_in_10, short base);
std::string add_in_base(const std::string& num1, const std::string& num2, short base);
std::string subtract_in_base(const std::string& num1, const std::string& num2, short base, ll number1, ll number2);
void DAY1(bool slaves[COUNT_SLAVES], const bool barrels[COUNT_BARRELS], short &count_survived);
void GET_LAST_SURVIVED(bool slaves[COUNT_SLAVES], bool last_survived[COUNT_SLAVES]);
void GET_RESULT(const bool slaves[COUNT_SLAVES], bool last_survived[COUNT_SLAVES]);
void DAY2(const int num_possible_options, bool slaves[COUNT_SLAVES], const bool barrels[COUNT_BARRELS]);