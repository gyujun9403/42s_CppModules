#include <Reader.hpp>

Reader::Reader(std::string fName)
{
	this->read_.open(fName, std::fstream::out);
}

bool Reader::isReaderUsable()
{
	return (this->read_.is_open());
}

std::string Reader::getNextLine()
{
	std::string line;
	std::getline(this->read_, line);
	return line;
}

Reader::~Reader()
{
	if (this->isReaderUsable)
		this->read_.close();
}