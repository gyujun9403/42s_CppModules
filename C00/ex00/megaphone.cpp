#include <iostream>

class Megaphone
{
private:
	int	num_of_str_;
	std::string *strs;
private:	
	void prtTrimedStr();
public:
	Megaphone(int ac);
	Megaphone(int ac, char **av);
	~Megaphone();
	void MakeAwake();
};

Megaphone::Megaphone(int ac, char **av) : num_of_str_(ac - 1)
{
	if (num_of_str_ > 0) {
		strs = new std::string[num_of_str_];
		for (int i = 0; i < num_of_str_; i++) {
			(strs[i]).assign(av[i + 1]);
		}
	}
	else {
		strs = NULL;
	}
}

void Megaphone::prtTrimedStr()
{
	std::string				str;
	std::string::size_type	trim_begin;
	std::string::size_type	trim_end;

	for (int i = 0; i < this->num_of_str_; i++) {
		trim_begin = strs[i].find_first_not_of("\a\b\f\n\r\t\v ");
		trim_end = strs[i].find_last_not_of("\a\b\f\n\r\t\v ");
		if (trim_begin > strs[i].size())
			continue;
		str.assign(strs[i], trim_begin, trim_end - trim_begin + 1);
		std::transform(str.begin(), str.end(), str.begin(), ::toupper);
		std::cout << str << ' ';
	}
	std::cout << std::endl;
}

void Megaphone::MakeAwake()
{
	if (num_of_str_ == 0)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		prtTrimedStr();
	}
	
}

Megaphone::~Megaphone()
{
	delete[] strs;
}


int main(int ac, char **av)
{
	Megaphone mgp(ac, av);
	mgp.MakeAwake();

	return 0;
}
