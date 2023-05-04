#pragma once
#include <string>
class Error {
    std::string message;
public:
    Error(const std::string& message = "");
    Error(const Error& e);
    std::string get_message() const;

    void setMessage(const std::string& m);
};
