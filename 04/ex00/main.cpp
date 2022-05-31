#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
	{
		std::cout << "-----[Exer 1]-----" << std::endl;
		const Animal* meta = new Animal();
		// 🌟
		const Animal* i = new Cat();
		const Animal* j = new Dog();

		std::cout << "meta :" << meta->getType() << " " << std::endl;
		std::cout << "i :" << i->getType() << " " << std::endl;
		std::cout << "j :" << j->getType() << " " << std::endl;
		meta->makeSound();
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		delete meta;
		delete i;
		delete j;
		std::cout << "------------------" << std::endl;
	}
	{
		std::cout << "-----[Exer 2]-----" << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		// 🌟
		const WrongAnimal* i = new WrongCat();
		std::cout << "meta :" << meta->getType() << " " << std::endl;
		std::cout << "i :" << i->getType() << " " << std::endl;
		meta->makeSound();
		i->makeSound();
		delete meta;
		delete i;
		std::cout << "------------------" << std::endl;
	}
	return 0;
}