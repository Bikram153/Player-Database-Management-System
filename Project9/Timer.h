#pragma once
#include<chrono>
#include<iostream>
#include<fstream>
#include <iomanip>
class Timer
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_startTimePoint;
public:
    Timer();
    void TimerInsertion();
    void stop();
    void TimerDatabase();
    ~Timer();
};


