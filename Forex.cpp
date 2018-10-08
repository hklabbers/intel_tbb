#include "Forex.h"

Forex::Forex(std::string datetime, float bid_price, float ask_price) : datetime(datetime),
                                                                                       bid_price(bid_price),
                                                                                       ask_price(ask_price) {}

std::string Forex::get_datetime() const {
    return datetime;
}

float Forex::get_bid_price() const {
    return bid_price;
}

float Forex::get_ask_price() const {
    return ask_price;
}

float Forex::get_mvng_avg_bid_price() const {
    return mvng_avg_bid_price;
}

void Forex::set_mvng_avg_bid_price(float mvng_avg_bid_price) {
    Forex::mvng_avg_bid_price = mvng_avg_bid_price;
}

float Forex::get_mvng_avg_ask_price() const {
    return mvng_avg_ask_price;
}

void Forex::set_mvng_avg_ask_price(float mvng_avg_ask_price) {
    Forex::mvng_avg_ask_price = mvng_avg_ask_price;
}

std::ostream &operator<<(std::ostream &os, const Forex &forex1) {
    os << "datetime: " << forex1.datetime << " bid_price: " << forex1.bid_price
       << " mvng_avg_bid_price: " << forex1.mvng_avg_bid_price;
    return os;
}
