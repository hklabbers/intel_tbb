#ifndef INTEL_TBB_SERIALMOVINGAVERAGECALCULATOR_H
#define INTEL_TBB_SERIALMOVINGAVERAGECALCULATOR_H

#include <tbb/concurrent_vector.h>
#include "Forex.h"

class Serial_moving_average_calculator {
public:
    Serial_moving_average_calculator(std::vector<Forex> &forex_vec, int ticks = 30);

    void calculate() const;

    std::vector<Forex> &get_forex_vec() const;

    void set_forex_vec(std::vector<Forex> &forex_vec);

    int get_ticks() const;

    void set_ticks(int ticks=30);

private:
    std::vector<Forex> &forex_vec;
    int ticks;
};

#endif //INTEL_TBB_SERIALMOVINGAVERAGECALCULATOR_H
