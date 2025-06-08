// Neel, Ayaan, Paul
// Final ProjectPapas Pickleria
// 6-3-25
#include <iostream>
#include "utils.h"

bool checkEvent(double chance) {
    return randoPercent() <= chance;
}

int event(double& money, int& day) {
    if (checkEvent(0.1)) {
        std::cout << "\n SUPER ROBBERY! You lost 60% of your money and the day is skipped!" << std::endl;
        money *= 0.4;
        day++; //skip day
        return 0;
    } else if (checkEvent(0.5)) {
        std::cout << "\nROBBERY! You lost 20% of your money!" << std::endl;
        money *= 0.8;
    } else if (checkEvent(1.0)) {
        std::cout << "\n BONUS DAY! You got 10 extra customers today!" << std::endl;
        return 10;
    }
    return 0;
}

int main()
{
    srand(time(0));
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
    
    double satisfaction = 50.0; //starts at 50%
    int basecustomers = 10; //starting number of customers
    


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

        int bonus = event(inven.munyun, game.day);
        int totalcustomers = basecustomers + bonus;
        
        for (int i = 0; i < totalcustomers; i++) {
            Customer c = generate(satisfaction);
            std::cout << "\nCustomer " << (i + 1) << " is a " << c.type << " customer." << std::endl;
            
            int successfulsales = 0;
            for (int j = 0; j < c.items; j++) {
                if (inven.pickles > 0 && inven.sticks > 0 && inven.batter > 0 && inven.jars > 0) {
                    inven.pickles--;
                    inven.sticks--;
                    inven.batter--;
                    inven.jars--;
                    inven.munyun += 3.0; //selling price per item
                    
                    successfulsales++;
                } else {
                    std::cout << "You ran out of inventory!" << std::endl;
                    break;
                }
            }
            if (successfulsales > 0) {
                std::cout << "They bought " << successfulsales << " item(s)!" << std::endl;
            }
            
            //celeb tip
            if (c.type == "celebrity") {
                double tip = successfulsales * 3.0 * c.tip;
                inven.munyun += tip;
                std::cout << "Celebrity tipped you $" << tip << "!" << std::endl;
            }
            
            //news reporter
            if (c.type == "reporter") {
                if (c.isgood) {
                    satisfaction = std::min(100.0, satisfaction + 10.0);
                    std::cout << "Reporter wrote a GOOD review. Satisfaction is now " << satisfaction << "%." << std::endl;
                } else {
                    satisfaction = std::max(0.0, satisfaction - 20.0);
                    std::cout << "Reporter wrote a BAD review. Satisfaction is now" << satisfaction << "%." << std::endl;
                }
            }
        }
        std::cout << "\nEnd of day summary:" << std::endl;
        std::cout << "Money: $" << inven.munyun << std::endl;
        std::cout << "Inventory - Pickles: " << inven.pickles << ", Sticks: " << inven.sticks;
        std::cout << ", Batter: " << inven.batter << ", Jars: " << inven.jars << std::endl;
        std::cout << "Customer Satisfaction: " << satisfaction << "%" << std::endl;
                
        game.day++;
    }

    return 0;
}