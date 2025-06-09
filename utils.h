#pragma once

struct game
{
    int day = 1;
    double picklePrice = 0.5;
    double stickPrice = 0.1;
    double batterPrice = 0.27;
    double jarPrice = 1.0;
};

struct inven
{
    double munyun = 100.00;

    int pickles = 0;
    int sticks = 0;
    int batter = 0;
    int jars = 0;
};

void restock(game &game, inven &inven, int &num, int &retFlag);
void dash(int num);