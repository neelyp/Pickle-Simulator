//Ayaan Gill, Paul Rowe, Neelyp
//Final Project
//6-3-25
#include <iostream>
using namespace std;


int main()
{
    struct {
        double munyun = 100.00;
        int sticks = 0;
        int pickles = 0;
        int jars = 0;
        int batter = 0;
    } inventory;
    
    struct {
        int day = 1;
        double picklePrice = 0.5;
        double jarPrice = 1.0;
        double batterPrice = 0.27;
    } game;

    cout << "Start your papas pickleria!";
    
    
    while (game.day < 8 && inventory.munyun > 0) {
        cout << "Day " << game.day << ": " << endl;
        cout << "Pickles cost 50 cents to buy. How many would you like to buy for today? ";
        cin >> inventory.pickles;
        inventory.munyun -= inventory.pickles * game.picklePrice;
    }
    
    
    return 0;
}