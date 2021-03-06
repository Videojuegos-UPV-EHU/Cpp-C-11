// Threading-ii.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <thread>
#include <string>
#include <chrono>
#include <iostream>
#include <vector>
#include <mutex>
using namespace std;


//Instead of a namespace, we could use a class with static member variables/static methods
namespace Loader
{
	mutex pendingFilesMutex;
	vector<string> pendingFiles;
	bool m_bStop;

	void Run()
	{
		cout << "Loader running\n";

		while (!m_bStop)
		{
			while (pendingFiles.size() > 0)
			{
				pendingFilesMutex.lock();
				string filename = pendingFiles.back(); //<- for simplicity, we are using LIFO
				pendingFiles.pop_back();
				pendingFilesMutex.unlock();
				cout << "File loaded: " << filename << "\n";
			}
			cout << "Loader sleeping\n";
			this_thread::sleep_for(chrono::duration<double>(0.5));
		}

		cout << "Loader stopped\n";
	}
	void AddFileToLoad(string filename)
	{
		pendingFilesMutex.lock();
		pendingFiles.push_back(filename);
		pendingFilesMutex.unlock();
	}
	void Stop()
	{
		m_bStop = true;
	}
}


int main()
{
	thread loaderThread(Loader::Run);

	this_thread::sleep_for(chrono::seconds(1));
	Loader::AddFileToLoad("file1.bin");
	this_thread::sleep_for(chrono::seconds(1));
	Loader::AddFileToLoad("file2.bin");
	this_thread::sleep_for(chrono::seconds(1));
	Loader::AddFileToLoad("file3.bin");
	this_thread::sleep_for(chrono::seconds(1));
	Loader::AddFileToLoad("file4.bin");
	this_thread::sleep_for(chrono::seconds(5));

	Loader::Stop();

	loaderThread.join();

    return 0;
}

