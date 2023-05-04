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

#include "KeyValueDatabase.hpp"

KeyValueDatabase::KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension): Object(name, location, extension){}

void KeyValueDatabase::add_entry(const std::pair<std::string, int>& entry)
{
	for (unsigned int i=0; i < keyValue.size(); i++) {
		if (keyValue[i].first == entry.first) {
			throw std::invalid_argument("invalid argument");
		}
	}
	keyValue.push_back(entry);
}

int KeyValueDatabase::get_value(const std::string& key) const
{
	for (unsigned i = 0; i < keyValue.size(); i++) {
		if (keyValue.at(i).first==key) {
			return keyValue[i].second;
		}
	}
	throw std::invalid_argument("invalid argument");
}

std::string KeyValueDatabase::to_string()const
{
	std::string s = name;
	s += '\n';
	s += location;
	s += '\n';
	s += extension;
	s += '\n';
	for (unsigned int i = 0; i < keyValue.size(); i++) {
		std::string n = std::to_string(keyValue[i].second);
		s += keyValue[i].first;
		s += ":";
		s += n;		
		s += '\n';
	}
	return s;
}

void KeyValueDatabase::from_string(const std::string& str)
{
	std::pair<std::string, int> P;
	std::string s = "";
	int num = 0;
	for (unsigned int i = 0; i < str.length(); i++) {
		if (str[i] != ':' && str[i] != '\n') {
			s += str[i];
		}
		if (str[i] == ':') {
			P.first = s;
			s = "";
		}
		if (str[i] == '\n') {
			if (num == 0) {
				name = s;
			}
			if (num == 1) {
				location = s;
			}
			if (num == 2) {
				extension = s;
			}
			if (num > 2) {
				for (unsigned int i = 0; i < s.length(); i++) {
					num += s[i] - '0';
					num *= 10;
				}
				P.second = num / 10;
				keyValue.push_back(P);
			}
			s = "";
			num++;
			
		}
	}
	
}

std::string KeyValueDatabase::debug_print()const
{
	std::string s = "";
	for (unsigned int i = 0; i < keyValue.size(); i++) {
		s += "{";
		s += keyValue[i].first;
		s += ":";
		s += std::to_string(keyValue[i].second);
		s += "}";
		s += '\n';
	}
	return s;
}

bool KeyValueDatabase::operator==(const Comparable* rhs) const
{
	const KeyValueDatabase* keyv = dynamic_cast<const KeyValueDatabase*>(rhs);
	
	if (keyv) {
		if (keyValue.size() != keyv->keyValue.size()) {
			return 0;
		}
		for (unsigned int i = 0; i < keyValue.size(); i++) {
			if (keyValue[i].first != keyv->keyValue[i].first) {
				return 0;
			}
			if (keyValue[i].second != keyv->keyValue[i].second) {
				return 0;
			}
		}
		return 1;
	}
	return 0;	
}

bool KeyValueDatabase::operator!=(const Comparable* rhs) const
{
	return !(*this==rhs);
}

Object* KeyValueDatabase::clone() const
{
	return new KeyValueDatabase(*this);
}


