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

#include "Object.hpp"

Object::Object(const std::string& name, const std::string& location, const std::string& extension): name(name), location(location), extension(extension){}

std::string Object::get_name() const
{
	return name;
}

std::string Object::get_location() const
{
	return location;
}

std::string Object::get_extension() const
{
	return extension;
}

std::string Object::get_fullpath() const
{
	std::string path = "";
	path += location;
	path += '/';
	path += name;
	path += '.';
	path += extension;
	return path;
}


