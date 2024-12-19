#include "/Users/personal/Documents/453504/ОАиП/LR7/source/header.h"
#include <iostream>
#include <vector>
#include <cmath>
int main() {
    bool slaves[COUNT_SLAVES] = {true, true, true, true, true};
    bool barrels[COUNT_BARRELS];
    for(int i = 0; i < COUNT_BARRELS; ++i) {
        barrels[i] = true;
    }
    std::cout << "\nВведи номер отравленной бочки: ";
    short index_poison;
    std::cin >> index_poison;
    barrels[index_poison-1] = false;
    short count_survived = 0;
    DAY1(slaves, barrels, count_survived);
    int num_possible_options = pow(2, count_survived);
    DAY2(num_possible_options,slaves,barrels);
    return 0;
}