// Neel, Ayaan, Paul
// Final Project - Papas Pickleria
// 6-3-25

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "utils.h"

using namespace std;

int main()
{
    std::srand(std::time(0));

    game game;
    inven inven;
    Events event;
    int customersToday = 0;

    std::cout << "Start your papas pickleria!" << std::endl;

    while (game.day < 8 && inven.munyun > 0)
    {
        std::cout << "Day " << game.day << ": " << std::endl;
        std::cout << "Your current inventory is: " << std::endl;
        std::cout << "Pickles: " << inven.pickles << std::endl;
        std::cout << "Sticks: " << inven.sticks << std::endl;
        std::cout << "Jars: " << inven.jars << std::endl;
        std::cout << "Batter: " << inven.batter << std::endl;
        cout << "Customer Satisfaction: " << game.satisfaction << "%" << std::endl;
        std::cout << "You have $" << inven.munyun << " to spend." << std::endl;
        dash(100);

        // BUYING STUFF

        restock(game, inven);

        // open the store for the day
        //         Robbery -> you lose 20% of your money (20% of happening)
        //   - Super Robbery -> you lose 60% of money and the day skips (2.5%)
        //   - Bonus day -> You get 10 extra people to enter your store (2.5%)
        //   - normal day -> nothing special happens (75%)

        event.decideEvent();
        if (event.type == "Normal Day")
        {
            std::cout << "Nice weather we're having aint it?" << std::endl;
        }
        else if (event.type == "Robbery")
        {
            inven.munyun = inven.munyun * .8;
            std::cout << "Diddy Blud robbed like 6 7 of your munyun!!(brotisserie chicken stole 20\% of money)" << std::endl;
        }
        else if (event.type == "Super Robbery")
        {
            inven.munyun = inven.munyun * .4;
            std::cout << "Diddythava licked like six seventie percent of the bag and closed up for the day!!(you lose 60\% of money and day skips)" << std::endl;
            game.day++;
        }
        else
        {
            customersToday += 10;
            std::cout << "You used to have hoop dreams till u found out there were other ways to score!!(+10 customers)" << std::endl;
        }
        std::cout << "Your store is now open for the day!" << std::endl;

        customersToday = (game.satisfaction > 50.0) ? game.baseCustomers + static_cast<int>(game.satisfaction - 50.0) * 0.5 : game.baseCustomers - static_cast<int>(50.0 - game.satisfaction) * 0.5;
        game.baseCustomers = customersToday; // update base customers for next day

        Customer customers[customersToday];

        std::cout << "You have " << customersToday << " customers today." << std::endl;
        sleep(500);
        for (int i = 0; i < customersToday; i++)
        {
            // loop through each customer to decide what type of customer they are and if buying is successful
            customers[i] = Customer();
            customers[i].decideCustomer(game);
            std::cout << "Customer " << i + 1 << " is a " << customers[i].type << "." << std::endl;
            sleep(500);

            customers[i].decideBuying(game, inven);
            if (customers[i].buying)
            {
                cout << "They are buying " << customers[i].numItemsBuying << " items." << std::endl;
                sleep(500);
                cout << "They are buying: ";
                sleep(500);
                customers[i].decideWhatBuying(game, inven);
                for (int j = 0; j < customers[i].numItemsBuying; j++)
                {
                    if (customers[i].whatBuying[j] == 0)
                    {
                        cout << "Jarred Pickle " << endl;
                        inven.jars--;
                        inven.pickles--;
                        inven.munyun += 3;
                    }
                    else if (customers[i].whatBuying[j] == 1)
                    {
                        cout << "Pickle on a Stick " << endl;
                        inven.sticks--;
                        inven.pickles--;
                        inven.munyun += 2;
                    }
                    else if (customers[i].whatBuying[j] == 2)
                    {
                        cout << "Fried Pickle on a Stick " << endl;
                        inven.sticks--;
                        inven.batter--;
                        inven.pickles--;
                        inven.munyun += 4;
                    }
                    sleep(200);
                }

                if (customers[i].type == "Celebrity")
                {
                    int tip = 0;
                    // gives players 10% of the total cost of its purchase as a tip
                    for (int j = 0; j < customers[i].numItemsBuying; j++)
                    {
                        if (customers[i].whatBuying[j] == 0)
                        {
                            tip += game.jarredPicklePrice * 0.1;
                        }
                        else if (customers[i].whatBuying[j] == 1)
                        {
                            tip += game.pickleOnStickPrice * 0.1;
                        }
                        else if (customers[i].whatBuying[j] == 2)
                        {
                            tip += game.friedPickleOnStickPrice * 0.1;
                        }
                    }
                    inven.munyun += tip;
                    cout << "They gave you a tip of $" << tip << "!" << std::endl;
                    sleep(500);
                }
            }
            else
            {
                cout << "They are not buying anything." << std::endl;
            }
        }

        game.day++;
    }

    return 0;
}
