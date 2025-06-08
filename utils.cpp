#include <iostream>
#include <ctime>
#include "utils.h"
#include <vector>

void dash(int num) {
    for (int i = 0; i < num; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

int rando(int min, int max) {
    return rand() % (max - min +1) + min;
}

double randoPercent() {
    return static_cast<double>(rand()) / RAND_MAX * 100.0;
}

Customer generate(double satisfaction) {
    double roll = randoPercent();
    
    //probability changes based on store satisfaction
    double rich = 10.0 + std::max(0.0, satisfaction - 50) * 0.5;
    double reporter = 5.0;
    double celebrity = 0.5;
    double ddhuang = 0.00000000001;
    double mano = 0.00000000001;
    double diddyBlud = 6.7;
    double normal = 60.0 - std::max(0.0, 50 - satisfaction) * 0.5;
    
    if (roll < celebrity) {
        return {"celebrity", rando(1, 3), 0.10, false};
    } else if (roll < celebrity + rich) {
        return {"rich", rando(4, 6), 0.0, false};
    } else if (roll < celebrity + rich + reporter) {
        return {"reporter", rando(1, 2), 0.0, rand() % 100 < 45};
    } else if (roll < celebrity + rich + reporter + ddhuang) {
        return {"ddhuang", 100, 0.0, false};
    } else if (roll < celebrity + rich + reporter + ddhuang + mano) {
        return {"mano", 100, 0.0, false};
    } else if (roll < celebrity + rich + reporter + ddhuang + mano + diddyBlud) {
        return {"diddy blud", 100, 0.0, false};
    } else {
        return {"normal", rando(1, 3), 0.0, false};
    }
}
