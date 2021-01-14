#ifndef TIMER_HPP
#define TIMER_HPP

#include <iostream>
#include <chrono>

template <typename T>
float get_duration(std::chrono::steady_clock::time_point start, std::chrono::steady_clock::time_point stop){
    auto duration = std::chrono::duration_cast<T>(stop - start);
    return duration.count();
}

#endif