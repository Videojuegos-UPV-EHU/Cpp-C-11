#pragma once
#include <chrono>
using namespace std::chrono;

class Timer
{
	system_clock::time_point m_startTimePoint;
public:
	Timer();

	void Start();
	double ElapsedTime(bool resetTimer = false);
};