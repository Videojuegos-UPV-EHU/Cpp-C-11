// Threading-iii.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Time/Timer.h"
#include <thread>
#include <iostream>
#include <vector>
using namespace std;

void SumVector(vector<double>& vec, int startOffset, int numElements, double* pOutput)
{
	double result = 0;
	for (int i = startOffset; i < startOffset + numElements; i++)
	{
		result += vec[i]*vec[i];
	}
	*pOutput = result;
}

int main()
{
	Timer timer;
	const int numElements = 100000000;
	vector<double> v = vector<double>(numElements);

	//Initialize the vector
	for (int i = 0; i < numElements; i++)
		v[i] = 2.3;
	cout << "Vector initialized\n";

	//Monothread execution
	double result;
	timer.Start();
	SumVector(v, 0, numElements, &result);
	double t= timer.ElapsedTime();
	cout << "Monothread execution:\nResult= " << result << " (" << t << "seconds)\n";


	//Multithread execution
	double result1= 0.0, result2= 0.0, result3= 0.0, result4= 0.0;
	int numThreads = 2;// 4;
	timer.Start();
	thread thread1(SumVector, ref(v), 0								, numElements/ numThreads	, &result1);
	thread thread2(SumVector, ref(v), numElements/ numThreads		, numElements/ numThreads	, &result2);
	//thread thread3(SumVector, ref(v), 2* (numElements / numThreads)	, numElements / numThreads	, &result3);
	//thread thread4(SumVector, ref(v), 3* (numElements / numThreads)	, numElements / numThreads	, &result4);
	thread1.join();
	thread2.join();
	//thread3.join();
	//thread4.join();
	result = result1 + result2 + result3 + result4;
	t = timer.ElapsedTime();
	cout << "Multithread execution:\nResult= " << result << " (" << t << "seconds)\n";
    return 0;
}

