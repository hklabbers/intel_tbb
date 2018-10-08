#include <iostream>
#include "tbb/tbb/task_scheduler_init.h"
#include "tbb/parallel_for.h"
#include "Stopwatch.h"
#include "Forex_reader.h"
#include "Serial_moving_average_calculator.h"
#include "Parallel_moving_average_calculator.h"

void serial_calculation(std::vector<Forex> &data_set, int ticks) {

    std::cout << "Started serial moving average calculator." << std::endl;
    Serial_moving_average_calculator serial_calculator(data_set, ticks);

    stopwatch::Stopwatch stopwatch;
    serial_calculator.calculate();
    auto duration = stopwatch.elapsed();
    std::cout << "Elapsed time serial calculation: " << duration << "ms." << std::endl;
}

void parallel_calculation(std::vector<Forex> &data_set, int ticks) {
    std::cout << "Started parallel moving average calculator." << std::endl;
    Parallel_moving_average_calculator parallel_moving_average_calculator(data_set, ticks);

    tbb::task_scheduler_init init;
    std::cout << "Number of default threads for the task scheduler: " << (tbb::task_scheduler_init::default_num_threads() - 1) << std::endl;

    stopwatch::Stopwatch stopwatch;
    parallel_moving_average_calculator.calculate();
    auto duration = stopwatch.elapsed();

    std::cout << "Elapsed time parallel calculation: " << duration << "ms." << std::endl;
}

int main() {
    int const ticks = 90;
    Forex_reader reader("/home/vagrant/hk.csv");
    stopwatch::Stopwatch stopwatch;
    std::vector<Forex> data_set_serial = reader.read(); //Can be normal vector, no additional items are added, so no re-allocation.
    auto duration = stopwatch.elapsed();
    std::cout << "Reading file in " << duration << "ms." << std::endl;

    std::vector<Forex> data_set_parallel(data_set_serial);

    serial_calculation(data_set_serial, ticks);
    parallel_calculation(data_set_parallel, ticks);

    // Compare serial and parallel results, they should be the identical!
    int parallel_vec_it = 0;
    unsigned long wrong_cntr = 1;
    for (int serial_vec_it = 0; serial_vec_it < data_set_serial.size(); serial_vec_it++) {
        if (std::to_string(data_set_serial[serial_vec_it].get_mvng_avg_bid_price()) != std::to_string(data_set_parallel[serial_vec_it].get_mvng_avg_bid_price())) {
            std::cout << wrong_cntr++ << ". Not the same: " << std::to_string(data_set_serial[serial_vec_it].get_mvng_avg_bid_price()) << ", "
                  << std::to_string(data_set_parallel[serial_vec_it].get_mvng_avg_bid_price()) << std::endl;
        }
        parallel_vec_it++;
    }
    return 0;
}



