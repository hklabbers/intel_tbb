#include <iostream>
#include "tbb/parallel_for.h"
#include "Parallel_moving_average_calculator.h"

Parallel_moving_average_calculator::Parallel_moving_average_calculator(std::vector<Forex> &forex_vec,
                                                                       int ticks) : forex_vec(forex_vec), ticks(ticks) {
}

void Parallel_moving_average_calculator::calculate() const {
    tbb::parallel_for(size_t(0), forex_vec.size(), [&] (size_t i) {
        parallel_calculate(i);
    } );
}

void Parallel_moving_average_calculator::parallel_calculate(size_t c) const {
    float sum = 0.0f;
    int count = 0;
    for (auto inner_it = c; inner_it < forex_vec.size() && inner_it >= 0; inner_it--) {
        sum = sum + forex_vec[inner_it].get_bid_price();
        count++;
        if (inner_it == c - (ticks - 1)) {
            break;
        }
    }
    forex_vec[c].set_mvng_avg_bid_price(sum / count);
}

std::vector<Forex> &Parallel_moving_average_calculator::get_forex_vec() const {
    return forex_vec;
}

void Parallel_moving_average_calculator::set_forex_vec(std::vector<Forex> &forex_vec) {
    Parallel_moving_average_calculator::forex_vec = forex_vec;
}

int Parallel_moving_average_calculator::get_ticks() const {
    return ticks;
}

void Parallel_moving_average_calculator::set_ticks(int ticks) {
    if (ticks < 5) {
        Parallel_moving_average_calculator::ticks = 5;
    } else {
        Parallel_moving_average_calculator::ticks = ticks;
    }
}