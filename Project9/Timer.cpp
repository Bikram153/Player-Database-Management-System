#include "Timer.h"
Timer::Timer()
{
    m_startTimePoint = std::chrono::high_resolution_clock::now();
}
void Timer::stop()
{
    auto  endPoint = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTimePoint).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endPoint).time_since_epoch().count();
    auto duration = end - start;
    double ms = duration * 0.001;
    std::cout << duration << " Microsecond (" << ms << "ms)\n";
}
void Timer::TimerInsertion() {
    auto now = std::chrono::system_clock::now();
    auto now_time = std::chrono::system_clock::to_time_t(now);

    struct tm time_info;
    localtime_s(&time_info, &now_time);
    std::chrono::duration<double> seconds = now - std::chrono::system_clock::from_time_t(mktime(&time_info));
    std::cout << std::put_time(&time_info, "%Y-%m-%d %H:%M:%S") << " (+" << seconds.count() << " seconds) ";
    std::ofstream out;
    out.open("log.txt", std::ofstream::out | std::ofstream::app);
    out <<std::put_time(&time_info, "%Y-%m-%d %H:%M:%S") << " (+" << seconds.count() << " seconds) ";
 }
void Timer::TimerDatabase() {
    auto now = std::chrono::system_clock::now();
    auto now_time = std::chrono::system_clock::to_time_t(now);

    struct tm time_info;
    localtime_s(&time_info, &now_time);
    std::chrono::duration<double> seconds = now - std::chrono::system_clock::from_time_t(mktime(&time_info));
    std::ofstream print;
    print.open("Database.txt", std::ofstream::out | std::ofstream::app);
    print << std::put_time(&time_info, "%Y-%m-%d %H:%M:%S") << " (+" << seconds.count() << " seconds) ";
}
Timer::~Timer()
{
}