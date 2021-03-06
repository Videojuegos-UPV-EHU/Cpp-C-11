// Threading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <thread>
#include <chrono>
#include <iostream>
using namespace std;

void threadFunc()
{
	for (int i= 0; i<10; i++)
	{
		cout << "thread #" << this_thread::get_id() << " here\n";
		this_thread::sleep_for(chrono::duration<double>(1.0));
	}
}


int main()
{
	thread thread1(threadFunc);
	thread thread2(threadFunc);
	
	this_thread::sleep_for(chrono::duration<double>(10.0));

	thread1.join(); //<- the main thread is blocked until thread1 ends
	thread2.join(); //<- the main thread is blocked until thread2 ends
	
    return 0;
}

