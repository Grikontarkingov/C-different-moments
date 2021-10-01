#include "Timer.h"

Timer::Timer() : m_beg(clock_t::now()){};

Timer::Timer(std::string name) : m_name(std::move(name)), m_beg(clock_t::now()){};

void Timer::Start (std::string name){
    m_name = std::move(name);
    m_beg = clock_t::now();
}

void Timer::Print() const{
    std::cout << m_name << ":\t" << elapsed() * 1000 << "ms" << std::endl;
}

double Timer::elapsed() const{
    return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
}
