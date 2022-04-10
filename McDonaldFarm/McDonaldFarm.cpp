#include <iostream>
#include <algorithm>

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

    cout << "Mission: Accepted... Start the program..." << endl;

}


void gameLoop()
{

    start();

    FenceCalculator c1;

    cout << "a = " << c1.getA() << " b = " << c1.getB() << " area = " << c1.getArea();

}




int main() {

    gameLoop();

    return 0;
}


