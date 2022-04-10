#include <iostream>
#include <algorithm>

#include "FenceCalculator.h"
#include "Fence.h"

using namespace std;


void gameLoop() {

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


int main() {

    gameLoop();

    return 0;
}


