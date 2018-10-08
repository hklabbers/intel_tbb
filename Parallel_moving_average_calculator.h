#ifndef INTEL_TBB_PARALLEL_MOVING_AVERAGE_CALCULATOR_H
#define INTEL_TBB_PARALLEL_MOVING_AVERAGE_CALCULATOR_H

#include "tbb/concurrent_vector.h"
#include "tbb/blocked_range.h"
#include "Forex.h"

class Parallel_moving_average_calculator {

public:
    Parallel_moving_average_calculator(std::vector<Forex> &forex_vec, int ticks=30);

    void calculate() const;

    std::vector<Forex> &get_forex_vec() const;

    void set_forex_vec(std::vector<Forex> &forex_vec);

    int get_ticks() const;

    void set_ticks(int ticks=30);

private:
    std::vector<Forex> &forex_vec;
    int ticks;

    void parallel_calculate(size_t  c) const;
};

#endif //INTEL_TBB_PARALLEL_MOVING_AVERAGE_CALCULATOR_H
