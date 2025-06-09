#include <iostream>
#include "utils.h"

void dash(int num)
{
    for (int i = 0; i < num; i++)
    {
        std::cout << "-";
    }
    std::cout << std::endl;
}

void restock(game &game, inven &inven)
{
    int num; // used as intermediate before adding things to inven
    // buy pickles
    while (true)
    {
        std::cout << "Pickles cost " << game.picklePrice * 100 << " cents to buy. How many would you like to buy for today? (max that you can afford: " << inven.munyun / game.picklePrice << ") ";
        std::cin >> num;

        if (num < 0)
        {
            std::cout << "You cannot buy a negative amount of pickles." << std::endl;
            // {
            //     retFlag = -1;
            //     return;
            // };
        }
        else if (num > inven.munyun / game.picklePrice)
        {
            std::cout << "You cannot afford that many pickles." << std::endl;
            // {
            //     retFlag = -1;
            //     return;
            // };
        }
        else
        {
            inven.pickles += num;
            inven.munyun -= num * game.picklePrice;
            std::cout << "You bought " << num << " pickles." << std::endl;
            std::cout << "You now have $" << inven.munyun << " left." << std::endl;
            break;
        }
    }

    // buy sticks
    while (true)
    {
        std::cout << "Sticks cost " << game.stickPrice * 100 << " cents to buy. How many would you like to buy for today? (max that you can afford: " << inven.munyun / game.stickPrice << ") ";
        std::cin >> num;

        if (num < 0)
        {
            std::cout << "You cannot buy a negative amount of sticks." << std::endl;
            // {
            //     retFlag = -1;
            //     return;
            // };
        }
        else if (num > inven.munyun / game.stickPrice)
        {
            std::cout << "You cannot afford that many sticks." << std::endl;
            // {
            //     retFlag = -1;
            //     return;
            // };
        }
        else
        {
            inven.sticks += num;
            inven.munyun -= num * game.stickPrice;
            std::cout << "You bought " << num << " sticks." << std::endl;
            std::cout << "You now have $" << inven.munyun << " left." << std::endl;
            break;
        }
    }

    // buy batter
    while (true)
    {
        std::cout << "Batter costs " << game.batterPrice * 100 << " cents to buy. How many would you like to buy for today? (max that you can afford: " << inven.munyun / game.batterPrice << ") ";
        std::cin >> num;

        if (num < 0)
        {
            std::cout << "You cannot buy a negative amount of batter." << std::endl;
            // {
            //     retFlag = -1;
            //     return;
            // };
        }
        else if (num > inven.munyun / game.batterPrice)
        {
            std::cout << "You cannot afford that many batter." << std::endl;
            // {
            //     retFlag = -1;
            //     return;
            // };
        }
        else
        {
            inven.batter += num;
            inven.munyun -= num * game.batterPrice;
            std::cout << "You bought " << num << " batter." << std::endl;
            std::cout << "You now have $" << inven.munyun << " left." << std::endl;
            break;
        }
    }
    // buy jars
    while (true)
    {
        std::cout << "Jars cost " << game.jarPrice << " dollar to buy. How many would you like to buy for today? (max that you can afford: " << inven.munyun / game.jarPrice << ") ";
        std::cin >> num;

        if (num < 0)
        {
            std::cout << "You cannot buy a negative amount of jars." << std::endl;
            // {
            //     retFlag = -1;
            //     return;
            // };
        }
        else if (num > inven.munyun / game.jarPrice)
        {
            std::cout << "You cannot afford that many jars." << std::endl;
            // {
            //     retFlag = -1;
            //     return;
            // };
        }
        else
        {
            inven.jars += num;
            inven.munyun -= num * game.jarPrice;
            std::cout << "You bought " << num << " jars." << std::endl;
            std::cout << "You now have $" << inven.munyun << " left." << std::endl;
            break;
        }
    }
}