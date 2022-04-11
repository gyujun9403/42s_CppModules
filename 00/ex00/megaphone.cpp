#include <iostream>

class Megaphone
{
private:
	int	num_of_str_;
	std::string *strs;
	Megaphone();
private:
	void prtStrs();
public:
	Megaphone(int ac, char **av);
	~Megaphone();
	void MakeAwake();
};

Megaphone::Megaphone(int ac, char **av) : num_of_str_(ac - 1)
{
	if (num_of_str_ > 0) {
		strs = new std::string[num_of_str_];
		for (int i = 0; i < num_of_str_; i++)
			(strs[i]).assign(av[i + 1]);
	}
	else
		strs = NULL;
}

void Megaphone::prtStrs()
{
	for (int i = 0; i < this->num_of_str_; i++) {
		for (std::string::size_type j = 0; j < this->strs[i].size(); j++) {
			if (this->strs[i][j] >= 'a' && this->strs[i][j] <= 'z')
				this->strs[i][j] -= 32;
		}
		std::cout << this->strs[i];
	}
	std::cout << std::endl;
}

void Megaphone::MakeAwake()
{
	if (num_of_str_ == 0)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		prtStrs();
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
