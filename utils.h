#pragma once
#include <vector>

struct game
{
    int day = 1;
    double picklePrice = 0.5;
    double stickPrice = 0.1;
    double batterPrice = 0.27;
    double jarPrice = 1.0;

    int baseCustomers = 15; // start at 10, increase by .5% for every satisfaction point above 50%
    double satisfaction = 50.0;

    double jarredPicklePrice = 3.0;       // price for jarred pickles
    double pickleOnStickPrice = 2.0;      // price for pickle on a stick
    double friedPickleOnStickPrice = 4.0; // price for fried pickle on a stick
};

struct inven
{
    double munyun = 100.00;

    int pickles = 0;
    int sticks = 0;
    int batter = 0;
    int jars = 0;
};

struct Customer
{
    std::string type;
    bool buying;
    int numItemsBuying;
    std::vector<int> whatBuying; // 0 - jarred pickle, 1 - pickle on a stick, 2 - fried pickle on a stick

    void decideCustomer(game &game);
    void decideBuying(game &game, inven &inven);
    void decideWhatBuying(game &game, inven &inven);
};

struct Events
{
    std::string type; // type of event

    void decideEvent();
};

void restock(game &game, inven &inven);
void dash(int num);
void sleep(int ms);