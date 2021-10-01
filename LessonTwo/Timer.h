#ifndef _TIMER_H
#define _TIMER_H
#include <chrono>
#include <iostream>

class Timer{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;

    std::string m_name;
    std::chrono::time_point<clock_t> m_beg;
    double elapsed() const;

public:
    Timer();
    Timer(std::string name);

    void Start (std::string name);

    void Print() const;
};

#endif //_TIMER_H
