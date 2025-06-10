#include <iostream>
#include <cstdlib>
#include <vector>

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

void Customer::decideCustomer(game &game)
{
    std::string types[] = {"Normal", "Rich Person", "News Reporter", "Celebrity", "Dih Dih Huang"};
    // percentages for each type
    // normal: 75%
    // rich person: 15%
    // news reporter: 9%
    // celebrity: 0.9%
    // dih dih huang: 0.1%

    double rand = std::rand() % 100;
    if (rand < 75) // normal
    {
        type = types[0];
    }
    else if (rand < 90) // rich
    {
        type = types[1];
    }
    else if (rand < 99) // news
    {
        type = types[2];
        int reportchance = std::rand() % 100;
        if (reportchance < 45){
            game.satisfaction += 10;
        } else{
            game.satisfaction -= 20;
        }
    }
    else if (rand < 99.9) // celebrity
    {
        type = types[3];
        game.satisfaction += 10;
    }
    else // dih dih huang
    {
        type = types[4];
        game.satisfaction += 100;
    }
}

void Customer::decideBuying(game &game, inven &inven)
{
    int rand = std::rand() % 100;
    if (rand < 50)
    {
        buying = true;
        // uhhhhh everyone except rich people and celebtiry buy 1-2 those big money movers buy 4-6

        if (type == "Celebrity" || type == "Rich Person")
        {
            numItemsBuying = std::rand() % 3 + 4; // buy between 4 and 6 items
        }
        else
        {
            numItemsBuying = std::rand() % 2 + 1; // buy between 1 and 2 items
        }
    }
    else
    {
        buying = false;
        numItemsBuying = 0;
    }
}

void Customer::decideWhatBuying(game &game, inven &inven)
{
    // decide what they are buying
    // 0 - jarred pickle, 1 - pickle on a stick, 2 - fried pickle on a stick
    // i have to check what is in stock and make a list of those things and then randomly choose from that

    // so fried pickle on a stick requires pickles, sticks, and batter
    // pickle on a stick requires pickles and sticks
    // jarred pickles require jars and pickles

    whatBuying.clear(); // clear the vector before adding to it
    for (int i = 0; i < numItemsBuying; i++)
    {
        // check stocks and if the required materials are available add that item to the stock vector
        std::vector<int> stock;
        if (inven.jars > 0 && inven.pickles > 0)
        {
            stock.push_back(0); // jarred pickle
        }
        if (inven.sticks > 0 && inven.pickles > 0)
        {
            stock.push_back(1); // pickle on a stick
        }
        if (inven.sticks > 0 && inven.batter > 0 && inven.pickles > 0)
        {
            stock.push_back(2); // fried pickle on a stick
        }

        if (!stock.empty())
        {
            whatBuying.push_back(stock[std::rand() % stock.size()]);
        }
        else
        {
            std::cout << "No items available for customer to buy." << std::endl;
            return; // if no items are available, exit the function
        }
    }
}

void Events::decideEvent()
{
    //     Robbery -> you lose 20% of your money (20% of happening)
    //   - Super Robbery -> you lose 60% of money and the day skips (2.5%)
    //   - Bonus day -> You get 10 extra people to enter your store (2.5%)
    //   - normal day -> nothing special happens (75%)
    std::string eventypes[] = {"Normal Day", "Robbery", "Bonus Day", "Super Robbery"};

    double rand = std::rand() % 100;
    if (rand < 75)
    {
        type = eventypes[0];
    }
    else if (rand < 95 && rand > 75) // 20%
    {
        type = eventypes[1];
    }
    else if (rand > 95 && rand < 97.5)
    {
        type = eventypes[2];
    }
    else
    {
        type = eventypes[3];
    }
}