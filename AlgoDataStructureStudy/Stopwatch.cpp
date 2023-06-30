#include "Stopwatch.h"

Stopwatch::Stopwatch()
{
    startTime = clock();
    endTime = 0;
    
}

clock_t Stopwatch::getStartTime() const
{
    return startTime;
}

clock_t Stopwatch::getEndTime() const
{
    return endTime;
}

void Stopwatch::start()
{
    startTime = clock();
    
}

void Stopwatch::stop()
{
    endTime = clock();
}

double Stopwatch::getElapsedTime()
{
    return (double)(endTime- startTime);
}
