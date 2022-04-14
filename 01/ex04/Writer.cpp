#include "Writer.hpp"

Writer::Writer(std::string fName)
{
	this->write_.open(fName, std::fstream::in | std::fstream::trunc);
}

bool Writer::isWriterUsable()
{
	return (this->write_.is_open);
}

int	Writer::writeString(std::string str)
{
	this->write_ << str;
}

Writer::~Writer()
{
	if (this->write_.is_open)
		this->write_.close();
}