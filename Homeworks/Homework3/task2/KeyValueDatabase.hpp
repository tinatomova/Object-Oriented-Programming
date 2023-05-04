/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Tina Tomova
* @idnumber 62594
* @task 1
* @compiler GCC
*/

#pragma once
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <math.h>
#include "Object.hpp"
#include <stdexcept>
class KeyValueDatabase : public Object{
private:
    std::vector<std::pair<std::string, int>> keyValue;
public:
    KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension);

    void add_entry(const std::pair<std::string, int>& entry);
    int get_value(const std::string& key) const;

    std::string to_string()const;
    void from_string(const std::string& str);
    std::string debug_print()const;
    bool operator==(const Comparable*)const;
    bool operator!=(const Comparable*)const;
    Object* clone()const;
};

