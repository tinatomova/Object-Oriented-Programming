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
#include <string>
#include "Comparable.hpp"
#include "Debug.hpp"
#include "Serializable.hpp"
class Object : public Comparable, public Debug, public Serializable{
protected:
    std::string name;
    std::string location;
    std::string extension;
public:
    Object(const std::string& name, const std::string& location, const std::string& extension);

    std::string get_name() const;
    std::string get_location() const;
    std::string get_extension() const;
    std::string get_fullpath() const;

    virtual Object* clone()const = 0;

    virtual ~Object() = default;
};
