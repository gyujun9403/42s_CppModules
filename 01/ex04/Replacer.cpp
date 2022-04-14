#include "Replacer.hpp"
#include <errno.h>

Replacer::Replacer(std::string fName)
{
	this->org_ = fName;
	if (!std::filesystem::exists(this->org_))
	{
		std::cerr << std::strerror(errno) << std::endl;
		exit (100);	// 정확한 에러 넘 찾기
	}
	this->temp_ = "temp_" + fName;
	this->fstreamOrg_.open(fName, std::fstream::in);
	this->fstreamOrg_.open(fName, std::fstream::out | std::fstream::trunc);
}

std::string	lineReplace(std::string line, std::string s1, std::string s2)
{
	std::string ret = "";
	size_t	start = 0, end = 0;

	while (1)
	{
		end = line.find(s1[start]);
		if (end == std::string::npos)
			break;
		else
		{
			ret.append(line, start, end - start);
			ret.append(s2);
		}
		start = end + 1;
	}
	return ret;
}

/*
open : https://www.cplusplus.com/reference/fstream/fstream/open/
fstream 읽고 쓰기 : https://corinediary.tistory.com/10
string find : https://modoocode.com/241
string append : https://modoocode.com/307
c++ file system : https://modoocode.com/306, https://jjeongil.tistory.com/1024?category=686124
*/