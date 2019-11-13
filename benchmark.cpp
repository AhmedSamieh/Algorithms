#ifndef _BENCHMARK_H_
#define _BENCHMARK_H_

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

/*
  Usage:
  {
     // some code 
    {
        benchmark performance;
        // the code to measure performance
    }
    // some code
  }
*/
class benchmark
{
private:
    time_point<high_resolution_clock> startTimePoint;
public:
    benchmark()
    {
        startTimePoint = high_resolution_clock::now();
    }
    ~benchmark()
    {
        auto stopTimePoint = high_resolution_clock::now();
        auto duration = time_point_cast<microseconds>(stopTimePoint).time_since_epock() -
                        time_point_cast<microseconds>(startTimePoint).time_since_epock();
        cout << "duration : " << duration << " us" << endl;
    }
};

#endif // _BENCHMARK_H_