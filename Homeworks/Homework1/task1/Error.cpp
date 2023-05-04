#include "Error.hpp"

Error::Error(const std::string& message)
{
	this->message = message;
}

Error::Error(const Error& e)
{
	message = e.message;
}

std::string Error::get_message() const
{
	return message;
}

void Error::setMessage(const std::string& m)
{
	message = m;
}

