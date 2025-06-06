#include <iostream>
#include "utils.h"

void dash(int num) {
    for (int i = 0; i < num; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}
