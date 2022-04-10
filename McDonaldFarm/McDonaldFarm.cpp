#include <iostream>
#include <algorithm>
#include <conio.h>

#include "FenceCalculator.h"


using namespace std;

void start() {

    string run;

    //Ask to start
    cout << "Please write \"RUN\" to start: ";
    cin >> run;

    //Transform input to upper
    transform(run.begin(), run.end(), run.begin(), ::toupper);

    //Check input
    while (!cin.good() || (run != "RUN"))
    {
        //Report problem
        cout << "Please try again..." << endl;

        //Clear stream
        cin.clear();
        cin.ignore();

        //Get input again
        cout << "Please write \"RUN\" to start: ";
        cin >> run;

        //Transform input to upper
        transform(run.begin(), run.end(), run.begin(), ::toupper);
    }

    cout << "Mission: Accepted... Start the program..." << endl << endl;

}


void gameLoop() {

    start();
    
    string choice = "Y";
    bool isWrongValue = false;

    while (true) {

        if (choice == "y" || choice == "Y") {
            FenceCalculator c1;

            cout << "a = " << c1.getA() << " b = " << c1.getB() << " area = " << c1.getArea();

            choice = "";
            isWrongValue = false;
        }
        else if (choice == "n" || choice == "N")
        {
            break;
        }
        else
        {
            string message = isWrongValue ? 
                "Wrong value! Try again!\nDo you want to calculate another fence [Y/N]: " : 
                "Do you want to calculate another fence [Y/N]: ";
            cout << endl << message;

            cin >> choice;
            isWrongValue = true;
        }

    }

}




int main() {

    gameLoop();

    return 0;
}


