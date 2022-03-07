#include <iostream>
#include <string>

class megaphone
{
private:
	int	_numOfStr;
	std::string *_strs;
private:	
	void PrtTrimedStr();
public:
	megaphone(int ac);
	megaphone(int ac, char **av);
	~megaphone();
	void MakeAwake();
};

megaphone::megaphone(int ac, char **av) : _numOfStr(ac - 1)
{
	if (_numOfStr > 0)
	{
		_strs = new std::string[_numOfStr];
		for (int i = 0; i < _numOfStr; i++)
		{
			(_strs[i]).assign(av[i + 1]);
		}
	}
	else
	{
		_strs = NULL;
	}
}

void megaphone::PrtTrimedStr()
{
	std::string str;

	for (int i = 0; i < this->_numOfStr; i++)
	{
		str.assign(_strs[i], 
			_strs[i].find_first_not_of("\a\b\f\n\r\t\v "),
			_strs[i].find_last_not_of("\a\b\f\n\r\t\v "));
		std::cout << _strs[i] << "'s last : " <<_strs[i].find_last_not_of("\a\b\f\n\r\t\v ") << std::endl;;
		std::transform(str.begin(), str.end(), str.begin(), ::toupper);
		//std::cout << str << " ";
	}
	std::cout << std::endl;
}

void megaphone::MakeAwake()
{
	if (_numOfStr == 0)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		PrtTrimedStr();
	}
	
}

megaphone::~megaphone()
{
	delete[] _strs;
}


int main(int ac, char **av)
{
	megaphone mgp(ac, av);
	mgp.MakeAwake();

	return 0;
}

/*
REF
trim : http://duongame.blogspot.com/2015/04/c-string-trim.html
toupper : https://godog.tistory.com/entry/C-string-%EC%86%8C%EB%AC%B8%EC%9E%90-%EB%8C%80%EB%AC%B8%EC%9E%90-%EB%B3%80%ED%99%98-tolwer-toupper
assign : https://computer-science-student.tistory.com/44
*/