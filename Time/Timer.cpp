#include "stdafx.h"
#include "Timer.h"


Timer::Timer()
{
	m_startTimePoint = system_clock::now();
}

void Timer::Start()
{
	m_startTimePoint= system_clock::now();
}

double Timer::ElapsedTime(bool resetTimer)
{
	system_clock::time_point timePointNow = system_clock::now();

	auto timeDiff = timePointNow - m_startTimePoint;

	if (resetTimer) Start();

	return (duration<double, std::ratio<1>>(timeDiff)).count();
}