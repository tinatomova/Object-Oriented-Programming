#pragma once
// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

template <typename T>

class Optional {
    T value;
    bool empty;
public:
    Optional();
    Optional(const T& value);
    void setValue(const T& v);

    bool is_none() const;
    T get_value() const;
};

template<typename T>
inline Optional<T>::Optional()
{
    value;
    empty = 1;
}

template<typename T>
inline Optional<T>::Optional(const T& value)
{
    this->value = value;
    empty = 0;
}

template<typename T>
inline void Optional<T>::setValue(const T& v)
{
    value = v;
    empty = 0;
}

template<typename T>
inline bool Optional<T>::is_none() const
{
    if (empty == 1) return 1;
    else return 0;
}

template<typename T>
inline T Optional<T>::get_value() const
{
    if (empty == 1)return T();
    return value;
}

