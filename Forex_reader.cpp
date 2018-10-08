#include <fstream>
#include <iostream>
#include <cstring>
#include "Forex_reader.h"
#include "standalone_functions.h"

Forex_reader::Forex_reader(std::string filename) : filename(std::move(filename)) { }

std::vector<Forex> Forex_reader::read() {
    std::vector<Forex> forex_vec;
    forex_vec.reserve(1700000);
    std::string line;
    std::ifstream file(filename);

    if (file) {
        std::cout << "File with name:" << filename << " was opened." << std::endl;
    } else {
        std::cout << "File with name: " << filename << " was not opened. Error code: " << strerror(errno) << "." << std::endl;
    }

    while(std::getline(file, line)) {
        auto tokens = hk::tokenize(line, ',');
        auto datetime = tokens[0];
        auto bid_price = std::stof(tokens[1]);
        auto ask_price = std::stof(tokens[2]);

        Forex item(datetime, bid_price, ask_price);
        forex_vec.emplace_back(item);
    }

    file.close();
    std::cout << "Loaded " << std::to_string(forex_vec.size()) << " ticks." << std::endl;

    return forex_vec;
}