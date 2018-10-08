#include <iostream>
#include "Serial_moving_average_calculator.h"

Serial_moving_average_calculator::Serial_moving_average_calculator(std::vector<Forex> &forex_vec, int ticks)
        : forex_vec(forex_vec), ticks(ticks) {}

void Serial_moving_average_calculator::calculate() const {

    for (size_t outer_cnt = 0; outer_cnt < forex_vec.size(); outer_cnt++) {
        float sum = 0.0;
        int count = 0;
        for (size_t inner_cnt = outer_cnt; inner_cnt < forex_vec.size() && inner_cnt >= 0; inner_cnt--) {
            sum = sum + (forex_vec[inner_cnt].get_bid_price());
            count++;
            if (inner_cnt == outer_cnt - (ticks - 1)) {
                break;
            }
        }
        forex_vec[outer_cnt].set_mvng_avg_bid_price(sum / count);
    }
}

std::vector<Forex> &Serial_moving_average_calculator::get_forex_vec() const {
    return forex_vec;
}

void Serial_moving_average_calculator::set_forex_vec(std::vector<Forex> &forex_vec) {
    Serial_moving_average_calculator::forex_vec = forex_vec;
}

int Serial_moving_average_calculator::get_ticks() const {
    return ticks;
}

void Serial_moving_average_calculator::set_ticks(int ticks) {
    if (ticks < 5) {
        Serial_moving_average_calculator::ticks = 5;
    } else {
        Serial_moving_average_calculator::ticks = ticks;
    }
}
