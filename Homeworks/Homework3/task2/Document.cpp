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

#include "Document.hpp"
#include <stdexcept>

Document::Document(const std::string& name, const std::string& location, const std::string& extension): Object(name, location, extension)
{
	counter = 0;
}

void Document::write_line(const std::string& line)
{
	lines.push_back(line);
}

std::string Document::read_line()
{  
        if (counter>lines.size()-1) {           
            throw std::out_of_range("out of range");            
        }
		if (lines.size() == 0) {
			throw std::out_of_range("there is no lines");
		}
   
	counter++;
	return lines[counter-1];
}

std::string Document::read_line(const unsigned line)
{
	counter = line - 1;
	if (counter > lines.size() - 1) {
		throw std::out_of_range("out of range");
	}	
	if (lines.size() == 0) {
		throw std::out_of_range("there is no lines");
	}
	counter++;
	return lines[counter-1];
}

Object* Document::clone() const
{
	return new Document(*this);
}

void Document::from_string(const std::string& str)
{
	std::string s = "";
	int counter = 0;
	for (unsigned int i = 0; i<str.length(); i++) {
		if (str[i] != '\n') {
			s += str[i];
		}
		if (str[i] == '\n') {		
			if (counter == 0) {
				name = s;
			}
			else if (counter == 1) {
				location = s;
			}
			else if (counter == 2) {
				extension == s;
			}			
			else {
				lines.push_back(s);
			}
			counter++;
			s = "";
		}		
	}
}

std::string Document::to_string()const
{
	std::string s = name;
	s += '\n';
	s += location;
	s += '\n';
	s += extension;
	s += '\n';
	for (unsigned int i = 0; i < lines.size(); i++) {
		s += lines[i];
		s += '\n';
	}
	return s;
}

bool Document::operator==(const Comparable* rhs) const
{
	const Document* doc = dynamic_cast<const Document*>(rhs);
	if (doc == nullptr) {
		return 0;
	}
	if (doc->lines.size() != this->lines.size()) {
		return 0;
	}
	for (unsigned int i = 0; i < doc->lines.size(); i++) {
		if (this->lines[i] != doc->lines[i]) {
			return 0;
		}
	}
	return 1;
}

bool Document::operator!=(const Comparable* rhs) const
{
	return !(*this==rhs);
}

std::string Document::debug_print()const
{
	std::string s = "";
	for (unsigned int i = 0; i < lines.size(); i++) {
		std::string n = std::to_string(i + 1);
		s += "Line ";
		s += n;
		s += ": ";
		s += lines[i];
		s += '\n';
	}
	return s;
}

