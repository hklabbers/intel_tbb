#include <iostream>
#include <vector>
#include "Stopwatch.h"
#include "Forex_reader.h"
#include "Serial_moving_average_calculator.h"

void serial_calculation(std::vector<Forex> &data_set, int ticks) {

    std::cout << "Started serial moving average calculator." << std::endl;
    Serial_moving_average_calculator serial_calculator(data_set, ticks);

    stopwatch::Stopwatch stopwatch;
    serial_calculator.calculate();
    auto duration = stopwatch.elapsed();
    std::cout << "Elapsed time serial calculation: " << duration << "ms." << std::endl;
}

int main() {
    int const ticks = 90;
    Forex_reader reader("/home/vagrant/hk.csv");
    stopwatch::Stopwatch stopwatch;
    auto data_set_serial = reader.read(); //Can be normal vector, no additional items are added, so no re-allocation.
    auto duration = stopwatch.elapsed();
    std::cout << "Reading forex file in " << duration << "ms." << std::endl;

    serial_calculation(data_set_serial, ticks);

    return 0;
}