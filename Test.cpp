// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int myNumber3[3];
	myNumber3[0] = 2;
	myNumber3[1] = 3;
	myNumber3[2] = 6;
	for (int i = 0; i < 3; i++) {
		cout << i << " = " << myNumber3[i] << endl;
	}
	cout << "Vector" << endl;
	vector<int> myNumber2;
	myNumber2.push_back(2);
	myNumber2.push_back(3);
	myNumber2.push_back(6);
	for (int i = 0; i < myNumber2.size(); i++) {
		cout << i << " = " << myNumber2[i] << endl;
	}
    return 0;
}

