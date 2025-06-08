#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <string>

struct Customer {
    std::string type;
    int items;
    double tip;
    bool isgood;
};

void dash(int num);
int rando(int min, int max);
double randoPercent();
Customer generate(double satisfaction);

#endif