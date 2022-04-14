#pragma once

#include <fstream>

class Writer
{
private:
	Writer();
	std::ofstream	write_;
public:
	bool	isWriterUsable();
	Writer(std::string fName);
	int	writeString(std::string str);
	~Writer();
};