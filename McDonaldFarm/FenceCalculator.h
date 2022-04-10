#include <iostream>


using namespace std;

class FenceCalculator {

private:
	int a, b;

	int getFence();
	unsigned long long int getArea(int fence, int a);
	int findA(int fence);

public:

	FenceCalculator();
	~FenceCalculator();
	unsigned long long int getArea();
	int getA();
	int getB();


	

};