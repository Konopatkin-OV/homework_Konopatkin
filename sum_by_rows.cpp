#include <chrono>
#include <iostream>

class Timer
{
    using clock_t = std::chrono::high_resolution_clock;
    using microseconds = std::chrono::microseconds;
public:
    Timer()
        : start_(clock_t::now())
    {
    }

    ~Timer()
    {
        const auto finish = clock_t::now();
        const auto us = 
            std::chrono::duration_cast<microseconds>
                (finish - start_).count();
        std::cout << us << " us" << std::endl;
    }

private:
    const clock_t::time_point start_;
};

using namespace std;

int main(void) {
    int N = 1000;
    //cin >> N;
    int* Matrix = new int[1000000];

    Timer a;

    int Sum = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            Sum += Matrix[i * 1000 + j];
        }
    }

    cout << Sum << endl;

    delete[] Matrix;

    return 0;
}

// -O2