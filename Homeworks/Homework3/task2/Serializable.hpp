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
class Serializable {
public:
	virtual std::string to_string()const = 0;
	virtual void from_string(const std::string&) = 0;
	virtual ~Serializable() = default;
};
