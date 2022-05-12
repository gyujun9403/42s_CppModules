#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <iostream>
#include <fstream>
// c++ 11
//#include <filesystem>

class Replacer
{
private:
	Replacer();
	bool			isFileClosed;
	std::ifstream	fstreamOrg_;
	std::ofstream	fstreamRpl_;
	std::string	lineReplace(const std::string line, const std::string s1, const std::string s2) const;
public:
	Replacer(const std::string fName);
	~Replacer();
	bool	isReplacerUsable();
	void	closeFiles();
	void	replace(const std::string s1, const std::string s2);
};

#endif