#include "Replacer.hpp"
#include <errno.h>

Replacer::Replacer(const std::string fName)
{
	std::string fNameRpl;

	this->fstreamOrg_.open(fName, std::fstream::in);
	if (!this->fstreamOrg_.is_open())
	{
		std::cerr << std::strerror(errno) << std::endl;
		exit(errno);
	}
	fNameRpl = fName + ".replace";
	this->fstreamRpl_.open(fNameRpl, std::fstream::out | std::fstream::trunc);
	if (!this->fstreamRpl_.is_open())
	{
		std::cerr << std::strerror(errno) << std::endl;
		exit(errno);
	}
	this->isFileClosed = false;
}

Replacer::~Replacer()
{
	if (this->isFileClosed == false)
	{
		this->fstreamOrg_.close();
		this->fstreamRpl_.close();
	}
}

std::string	Replacer::lineReplace(const std::string line, const std::string s1, const std::string s2) const
{
	std::string ret = "";
	size_t	start = 0, end = 0;

	while (1)
	{
		end = line.find(s1, start);
		if (end == std::string::npos)
		{
			ret.append(line, start, line.length() - start);
			break;
		}
		else
		{
			ret.append(line, start, end - start);
			ret.append(s2);
			std::cout << ret << std::endl;
		}
		start = end + s1.length();
	}
	return ret;
}

void	Replacer::replace(const std::string s1, const std::string s2)
{
	std::string buffer;

	while(std::getline(this->fstreamOrg_, buffer))
	{
		buffer = lineReplace(buffer.append("\n"), s1, s2);
		this->fstreamRpl_ << buffer;
	}
}

bool Replacer::isReplacerUsable()
{
	return this->fstreamOrg_.is_open() && this->fstreamRpl_.is_open();
}

void Replacer::closeFiles()
{
	this->fstreamOrg_.close();
	this->fstreamRpl_.close();
	this->isFileClosed = true;
}

/*
open : https://www.cplusplus.com/reference/fstream/fstream/open/
fstream 읽고 쓰기 : https://corinediary.tistory.com/10
string find : https://modoocode.com/241
string append : https://modoocode.com/307
c++ file system : https://modoocode.com/306, https://jjeongil.tistory.com/1024?category=686124
*/