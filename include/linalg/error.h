#include <string>
#include <stdexcept>

class MatrixException : std::runtime_error {
    std::string msg;

public:
    MatrixException(std::string msg) : std::runtime_error(msg), msg(msg) {}

    const char * what() const noexcept override {
        return msg.c_str();
    }
};
