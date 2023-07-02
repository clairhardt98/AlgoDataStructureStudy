#pragma once
#include <ctime>

class Stopwatch
{
	
public:
	clock_t startTime;
	clock_t endTime;
public:
	Stopwatch();
	clock_t getStartTime() const;
	clock_t getEndTime() const;
	void start();
	void stop();
	double getElapsedTime();

};