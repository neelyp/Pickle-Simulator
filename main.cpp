// Neel, Ayaan, Paul
// Final Project - Papas Pickleria
// 6-3-25
#include <iostream>
#include "utils.h"

int main()
{
    struct
    {
        int day = 1;
        double picklePrice = 0.5;
        double stickPrice = 0.1;
        double batterPrice = 0.27;
        double jarPrice = 1.0;

    } game;

    struct
    {
        double munyun = 100.00;

        int pickles = 0;
        int sticks = 0;
        int batter = 0;
        int jars = 0;
    } inven;

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

        // buy pickles
        std::cout << "Pickles cost " << game.picklePrice * 100 << " cents to buy. How many would you like to buy for today? (max that you can afford: " << inven.munyun / game.picklePrice << ") ";
        std::cin >> num;

        if (num < 0)
        {
            std::cout << "You cannot buy a negative amount of pickles." << std::endl;
            continue;
        }
        else if (num > inven.munyun / game.picklePrice)
        {
            std::cout << "You cannot afford that many pickles." << std::endl;
            continue;
        }
        else
        {
            inven.pickles += num;
            inven.munyun -= num * game.picklePrice;
            std::cout << "You bought " << num << " pickles." << std::endl;
            std::cout << "You now have $" << inven.munyun << " left." << std::endl;
        }

        // buy sticks
        std::cout << "Sticks cost " << game.stickPrice * 100 << " cents to buy. How many would you like to buy for today? (max that you can afford: " << inven.munyun / game.stickPrice << ") ";
        std::cin >> num;

        if (num < 0)
        {
            std::cout << "You cannot buy a negative amount of sticks." << std::endl;
            continue;
        }
        else if (num > inven.munyun / game.stickPrice)
        {
            std::cout << "You cannot afford that many sticks." << std::endl;
            continue;
        }
        else
        {
            inven.sticks += num;
            inven.munyun -= num * game.stickPrice;
            std::cout << "You bought " << num << " sticks." << std::endl;
            std::cout << "You now have $" << inven.munyun << " left." << std::endl;
        }

        // buy batter
        std::cout << "Batter costs " << game.batterPrice * 100 << " cents to buy. How many would you like to buy for today? (max that you can afford: " << inven.munyun / game.batterPrice << ") ";
        std::cin >> num;

        if (num < 0)
        {
            std::cout << "You cannot buy a negative amount of batter." << std::endl;
            continue;
        }
        else if (num > inven.munyun / game.batterPrice)
        {
            std::cout << "You cannot afford that many batter." << std::endl;
            continue;
        }
        else
        {
            inven.batter += num;
            inven.munyun -= num * game.batterPrice;
            std::cout << "You bought " << num << " batter." << std::endl;
            std::cout << "You now have $" << inven.munyun << " left." << std::endl;
        }
        // buy jars
        std::cout << "Jars cost " << game.jarPrice << " dollar to buy. How many would you like to buy for today? (max that you can afford: " << inven.munyun / game.jarPrice << ") ";
        std::cin >> num;

        if (num < 0)
        {
            std::cout << "You cannot buy a negative amount of jars." << std::endl;
            continue;
        }
        else if (num > inven.munyun / game.jarPrice)
        {
            std::cout << "You cannot afford that many jars." << std::endl;
            continue;
        }
        else
        {
            inven.jars += num;
            inven.munyun -= num * game.jarPrice;
            std::cout << "You bought " << num << " jars." << std::endl;
            std::cout << "You now have $" << inven.munyun << " left." << std::endl;
        }

        // open the store for the day
        std::cout << "Your store is now open for the day!" << std::endl;

        game.day++;
    }

    return 0;
}