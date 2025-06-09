// Neel, Ayaan, Paul
// Final Project - Papas Pickleria
// 6-3-25
#include <iostream>
#include "utils.h"

int main()
{
    game game;
    inven inven;

    std::cout << "Start your papas pickleria!" << std::endl;

    while (game.day < 8 && inven.munyun > 0)
    {
        std::cout << "Day " << game.day << ": " << std::endl;
        std::cout << "Your current inventory is: " << std::endl;
        std::cout << "Pickles: " << inven.pickles << std::endl;
        std::cout << "Sticks: " << inven.sticks << std::endl;
        std::cout << "Jars: " << inven.jars << std::endl;
        std::cout << "Batter: " << inven.batter << std::endl;
        std::cout << "You have $" << inven.munyun << " to spend." << std::endl;
        dash(100);

        int num; // used as intermediate before adding things to inven

        // BUYING STUFF

        int retFlag;
        restock(game, inven, num, retFlag);
        if (retFlag == 3)
            continue;

        // open the store for the day
        std::cout << "Your store is now open for the day!" << std::endl;

        game.day++;
    }

    return 0;
}
