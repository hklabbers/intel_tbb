#ifndef INTEL_TBB_FOREX_READER_H
#define INTEL_TBB_FOREX_READER_H

#include <string>
#include "tbb/concurrent_vector.h"
#include "Forex.h"

class Forex_reader {
public:
    explicit Forex_reader(std::string filename);
    std::vector<Forex> read();

private:
    std::string filename;
    bool error = false;
    std::string error_message = "";
};


#endif //INTEL_TBB_FOREX_READER_H
