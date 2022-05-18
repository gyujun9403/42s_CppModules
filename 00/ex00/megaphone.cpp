#include <iostream>

class Megaphone
{
private:
	int	numOfStr_;
	std::string *strs_;
	Megaphone();
	void prtStrs();
public:
	Megaphone(int ac, char **av);
	~Megaphone();
	void MakeAwake();
};

Megaphone::Megaphone(int ac, char **av) : numOfStr_(ac - 1)
{
	if (numOfStr_ > 0)
	{
		strs_ = new std::string[numOfStr_];
		for (int i = 0; i < numOfStr_; i++)
		{
			(strs_[i]).assign(av[i + 1]);
		}
	}
	else
	{
		strs_ = NULL;
	}
}

void Megaphone::prtStrs()
{
	for (int i = 0; i < this->numOfStr_; i++)
	{
		for (std::string::size_type j = 0; j < this->strs_[i].size(); j++)
		{
			if (this->strs_[i][j] >= 'a' && this->strs_[i][j] <= 'z')
			{
				this->strs_[i][j] -= 32;
			}
		}
		std::cout << this->strs_[i];
	}
	std::cout << std::endl;
}

void Megaphone::MakeAwake()
{
	if (numOfStr_ == 0)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		prtStrs();
	}
}

Megaphone::~Megaphone()
{
	delete[] strs_;
}


int main(int ac, char **av)
{
	Megaphone mgp(ac, av);
	mgp.MakeAwake();

	return 0;
}
