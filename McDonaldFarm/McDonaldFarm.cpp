#include <iostream>
#include <algorithm>
#include <conio.h>
#include <string>

#include "FenceCalculator.h"


using namespace std;


void start() {

    string run;

    //Ask to start
    cout << "Please write \"RUN\" to start: ";
    getline(cin, run);

    //Transform input to upper
    transform(run.begin(), run.end(), run.begin(), ::toupper);

    //Check input
    while (!cin.good() || (run != "RUN")) {
        //Report problem
        cout << "Please try again..." << endl;

        //Get input again
        cout << "Please write \"RUN\" to start: ";
        getline(cin, run);

        //Transform input to upper
        transform(run.begin(), run.end(), run.begin(), ::toupper);
    }
    cout << "Mission: Accepted... Start the program..." << endl << endl;

}

void gameLoop() {

    start();
    //Set initial value
    string choice = "Y";
    bool isWrongValue = false;

    
    while (true) {

        if (choice == "y" || choice == "Y") {
            FenceCalculator calc;
            //Print value
            cout << "you can build a fence with dimensions a = " << calc.getA()
                << "m and b = " << calc.getB() << "m." << endl; 
            cout << "The area will be " << calc.getArea() << "m^2." << endl;;

            //Set values for play again
            choice = "";
            isWrongValue = false;
        }
        else if (choice == "n" || choice == "N") {
            break;
        }
        else {
            //Play again
            string message = isWrongValue ? 
                "Wrong value! Try again!\nDo you want to calculate another fence [Y/N]: " : 
                "Do you want to calculate another fence [Y/N]: ";
            cout << endl << message;

            getline(cin, choice);
            isWrongValue = true;
        }
    }
}



int main() {

    gameLoop();

    return 0;
}


