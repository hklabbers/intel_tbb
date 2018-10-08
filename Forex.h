#ifndef INTEL_TBB_FOREX_H
#define INTEL_TBB_FOREX_H

#include <string>
#include <ostream>

class Forex {
public:
    Forex();

    Forex(std::string datetime, float bid_price, float ask_price);

    std::string get_datetime() const;

    float get_bid_price() const;

    float get_ask_price() const;

        float get_mvng_avg_bid_price() const;

    void set_mvng_avg_bid_price(float mvng_avg_bid_price);

    float get_mvng_avg_ask_price() const;

    void set_mvng_avg_ask_price(float mvng_avg_ask_price);

    friend std::ostream &operator<<(std::ostream &os, const Forex &forex1);

private:
    std::string datetime;
    float bid_price;
    float ask_price;
    float mvng_avg_bid_price;
    float mvng_avg_ask_price;
};


#endif //INTEL_TBB_FOREX_H
