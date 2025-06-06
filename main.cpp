//Ayaan Gill, Paul Rowe, Neelyp
//Final Project
//6-3-25
#include <iostream>
#include "main.h"

using namespace std;


int main()
{
    
    cout << "Start your papas pickleria!";
    
    
    while (game.day < 8 && inventory.munyun > 0) {
        cout << "Day " << game.day << ": " << endl;
        cout << "Pickles cost 50 cents to buy. How many would you like to buy for today? ";
        cin >> inventory.pickles;
        inventory.munyun -= inventory.pickles * game.picklePrice;
    }
    
    
    return 0;
}