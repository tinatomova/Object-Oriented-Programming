#pragma once
// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

#include "Error.hpp"
#include "Optional.hpp"

template<typename T>

class Result {
private:
    Optional<T> value;
    Optional<Error> error;
    bool isError;
public:
    Result();
    Result(const T& result);
    Result(const std::string& error_message);

    Optional<T> get_result() const;
    Optional<Error> get_error() const;

    bool operator==(const T& rhs);
    bool operator==(const Error& rhs);
};

template<typename T>
inline Result<T>::Result()
{
    value;
    error;
    isError = 0;
}

template<typename T>
inline Result<T>::Result(const T& result)
{
    value.setValue(result);
    isError = 0;
}

template<typename T>
inline Result<T>::Result(const std::string& error_message)
{
    error.get_value().setMessage(error_message);
    isError = 1;
}

template<typename T>
inline Optional<T> Result<T>::get_result() const
{
    return value;
}

template<typename T>
inline Optional<Error> Result<T>::get_error() const
{
    return error;
}

template<typename T>
inline bool Result<T>::operator==(const T& rhs)
{
    if(isError == 0)return true;
    return false;
}

template<typename T>
inline bool Result<T>::operator==(const Error& rhs)
{
    if (isError == 1)return true;
    return false;
}

