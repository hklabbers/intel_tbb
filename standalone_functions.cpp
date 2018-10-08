#include <vector>
#include <string>
#include <sstream>

namespace hk {
    std::vector<std::string> tokenize(std::string &string_to_tokenize, char delimiter) {
        std::vector<std::string> result;
        std::istringstream token_stream(string_to_tokenize);
        std::string token;

        while(std::getline(token_stream, token, delimiter)) {
            result.push_back(token);
        }

        return result;
    }
}
