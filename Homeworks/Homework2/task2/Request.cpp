#include "Request.hpp"
unsigned Request::counter = 0;
Request::Request(const string& message, const string& sender)
{
	this->message = message;
	this->sender = sender;
	counter++;
	ID = counter;
}

string Request::getMessage() const
{
	return message;
}

string Request::getSender() const
{
	return sender;
}

unsigned int Request::getCount() const
{
	return counter;
}

unsigned int Request::getID() const
{
	return ID;
}

void Request::setMessage(const string& message)
{
	this->message = message;
}


