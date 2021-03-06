// Time.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Timer.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	Timer timer;
	double time1, time2;
	vector<double> vector1, vector2;
	const int numElements = 10000;

	//1st version: add elements to an empty vector using push_back()
	timer.Start();
	for (int i = 0; i < numElements; i++)
		vector1.push_back(i);
	time1 = timer.ElapsedTime();

	//2nd version: pre-allocate the vector and then write the values
	timer.Start();
	vector2 = vector<double>(numElements);
	for (int i = 0; i < numElements; i++)
		vector2[i] = i;
	time2 = timer.ElapsedTime();

	cout << "The 1st version took " << time1 << " seconds\n";
	cout << "The 2nd version took " << time2 << " seconds (" << 100*(time2/time1) << "% of the time spent by the 1st)\n";

    return 0;
}

