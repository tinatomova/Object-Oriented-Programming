#pragma once
#include <iostream>
using namespace std;

class Request
{
protected:
	string message;
	string sender;
	unsigned int ID;

public:
	static unsigned counter;
	Request(const string& message, const string& sender);

	string getMessage()const;
	string getSender()const;
	unsigned int getCount()const;
	unsigned int getID()const;

	void setMessage(const string& message);
};


