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
class Comparable {
public:
	virtual bool operator==(const Comparable*)const = 0;
	virtual bool operator!=(const Comparable*)const = 0;
	virtual ~Comparable() = default;
};
