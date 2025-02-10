// We are prototyping a robot that refills glasses during dinner. Every glass holds 200 milliliters.
// During dinner, people either drink water or juice, and as soon as there is less than 100 ml left
// in the glass, the robot refills it back to 200 ml.
// Create a class Glass with one public int field LiquidLevel and methods public Drink(int milliliters)
// that takes the amount of liquid that a person drank and public Refill() that refills the glass to
// be 200 ml full. Both methods should not return any value. Initially set LiquidLevel to 200.
// In the Main method create an object of class Glass and read commands from the screen until the
// user terminates the program (see next). Don't forget to refill the glass when needed!
#include <iostream>
#include <string>
using namespace std;

class Glass
{
public:
    int LiquidLevel;
    Glass()
    {
        LiquidLevel = 200;
    }
    void Drink(int milliliters)
    {
        LiquidLevel -= milliliters;
    }
    void Refill()
    {
        if (LiquidLevel < 100)
        {
            LiquidLevel = 200;
        }
    }
};

int main(int argc, char *argv[])
{
    Glass glass;
    glass.Drink(stoi(argv[1]));
    cout << "Liquid Level before: " << glass.LiquidLevel << " milliliters " << endl;
    glass.Refill();
    cout << "Liquid Level after: " << glass.LiquidLevel << " milliliters " << endl;
    string input;
    while (true)
    {
        cout << "Enter the amount of liquid to drink (or type 'exit' to terminate): ";
        cin >> input;
        if (input == "exit")
        {
            break;
        }
        int amount = stoi(input);
        glass.Drink(amount);
        cout << "Liquid Level before refill: " << glass.LiquidLevel << " milliliters" << endl;
        glass.Refill();
        cout << "Liquid Level after refill: " << glass.LiquidLevel << " milliliters" << endl;
        return 0;
    }
}