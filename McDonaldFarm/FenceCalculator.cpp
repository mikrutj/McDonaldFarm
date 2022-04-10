#include <iostream>
#include <string>
#include <limits>

#include "FenceCalculator.h"


using namespace std;

bool isNumber(string s) {
    //Check if is number
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}

int FenceCalculator::getFence() {
    
    string fence;

    cout << "How many meters of fence you have: ";
    getline(cin, fence);
    
    //Value check
    while (true) {
        if (isNumber(fence) && fence.length() <= 10 && stoll(fence) <= INT_MAX && stoll(fence) >= 3) {
            break;
        }
        else {
            //Report problem
            if ((!isNumber(fence.substr(1)) && fence[0] == '-') || (!isNumber(fence) && fence[0] != '-')) {
                cout << "Wrong value. Please try an integer number..." << endl;
            }
            else if (isNumber(fence.substr(1)) && fence[0] == '-') {
                cout << "Of course... and pig can fly... Try to be more realistic..." << endl;
            }
            else if (fence.length() > 10 || stoll(fence) > INT_MAX) {
                cout << "It is a lot of fence. Maybe something smaller?..." << endl;
            } 
            else if (stoll(fence) < 3) {
                cout << "We can't build anything out of it. Try to buy more..." << endl;
            }
            else {
                cout << "Wrong value. Please try again..." << endl;
            }

            cout << "How many meters of fence you have: ";
            getline(cin, fence);
        }
        
    }

    return stoll(fence);
}

unsigned long long int FenceCalculator::getArea (int f, int a) {
    //Calculate area
    //----------------------------------
    //2a + b = f
    //so b = f - 2*a
    //area A = a * b  =>  A = a * (f - 2*a)
    //----------------------------------

    return (unsigned long long int)a * (f - (2 * a));//((f * a) - (2 * pow(a, 2)));
}

unsigned long long int FenceCalculator::getArea() {
    return (unsigned long long int) a * b;
}

int FenceCalculator::findA (int f) {
    //Calculations 
    //----------------------------------
    // area - A,  
    // fence - f
    // 
    // f = 2*a + b   =>  b = f - 2*a
    // 
    // A = a * b 
    // A(a) = a * ( f - 2*a) = f*a - 2*pow(a,2)
    // 
    // in this case the function will have max value when its derivative is equal to zero
    // 
    // A'(a) = f - 4*a   
    // 
    // A'(a) = 0  <=>  a = f/4
    //----------------------------------

    double a = (f * 0.25);
    double area1, area2;

    //Find a bigger area if a is not integer
    if (a - (int)a != 0) {

        area1 = FenceCalculator::getArea(f, ceil(a));
        area2 = FenceCalculator::getArea(f, floor(a));

        if (area1 < area2) {
            return floor(a);
        }
        else {
            return ceil(a);
        }
    }

    return a;
}

int FenceCalculator::getA() {
    return a;
}

int FenceCalculator::getB() {
    return b;
}

FenceCalculator::FenceCalculator() {
    
    int fence = FenceCalculator::getFence();
    a = FenceCalculator::findA(fence);
    b = fence - 2 * a;

}


FenceCalculator::~FenceCalculator() {

}





