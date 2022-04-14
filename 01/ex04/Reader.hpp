#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Reader
{
private:
	Reader();
	std::ifstream	read_;
public:
	bool	isReaderUsable();
	Reader(std::string fName);
	std::string getNextLine();
	~Reader();
};