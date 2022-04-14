#include "Reader.hpp"
#include "Writer.hpp"
#include <filesystem>

class Replacer
{
private:
	Replacer();
	std::filesystem::path	org_;
	std::filesystem::path	temp_;
	std::fstream	fstreamOrg_;
	std::fstream	fstreamTemp_;
	std::string	lineReplace(std::string line);
public:
	Replacer(std::string fName);
	bool	isReplacerUsable();
	void	replace(std::string s1, std::string s2);
};