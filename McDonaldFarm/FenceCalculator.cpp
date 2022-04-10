#include <iostream>
#include "FenceCalculator.h"


using namespace std;

int FenceCalculator::getFence() {
    
    double fence;

    cout << "How many meters of fence you have: ";
    cin >> fence;

    //Value check
    while (!cin.good() || (fence < 3) || (fence - (int)fence != 0))
    {
        //Report problem
        if (!cin.good())
        {
            cout << "Wrong value. Please try again..." << endl;
        }
        else if (fence - (int)fence != 0)
        {
            if (fence > INT_MAX)
            {
                cout << "It is a lot of fence. Maybe something smaller?..." << endl;
            }
            else
                cout << "Wrong value. Please try an integer number..." << endl;
        }
        else if (fence < 3)
        {
            cout << "We can't build anything out of it. Try to buy more..." << endl;
        }
        else
            cout << "Wrong value. Please try again..." << endl;

        //Clear stream
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        //Get input again
        cout << "How many meters of fence you have: ";
        cin >> fence;
    }
    return (int)fence;
}

unsigned long long int FenceCalculator::getArea (int f, int a)
{
    //Calculate area
    //----------------------------------
    //2a + b = f
    //so b = f - 2*a
    //area A = a * b  =>  A = a * (f - 2*a)
    //----------------------------------

    return (unsigned long long int)a * (f - (2 * a));//((f * a) - (2 * pow(a, 2)));
}

unsigned long long int FenceCalculator::getArea()
{
    return (unsigned long long int) a * b;
}

int FenceCalculator::findA (int f)
{
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
    // A'(a) = f - 4*a       derivative
    // 
    // A'(a) = 0  <=>  a = f/4
    //----------------------------------

    double a = (f * 0.25);
    double area1, area2;

    //Find a bigger area if a != integer
    if (a - (int)a != 0)
    {
        area1 = FenceCalculator::getArea(f, ceil(a));
        area2 = FenceCalculator::getArea(f, floor(a));

        if (area1 < area2)
        {
            return floor(a);
        }
        else
        {
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





