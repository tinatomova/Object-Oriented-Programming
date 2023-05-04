/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Tina Tomova
* @idnumber 62594
* @task 1
* @compiler VC
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Object.hpp"
class Document : public Object{
private:
    std::vector<std::string> lines;
    unsigned int counter;
public:
    Document(const std::string& name, const std::string& location, const std::string& extension);

    void write_line(const std::string& line);

    std::string read_line();
    std::string read_line(const unsigned line);
    void from_string(const std::string& str);
    std::string to_string()const;
    bool operator==(const Comparable*)const;
    bool operator!=(const Comparable*)const;
    std::string debug_print()const;
    Object* clone()const;
};
