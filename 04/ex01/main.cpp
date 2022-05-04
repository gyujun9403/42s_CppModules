#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define ARR_SIZE 4

int main()
{
	std::cout << "-----[Exer 1]-----" << std::endl;
	Animal* arrAnimal[ARR_SIZE];
	Cat* castedCat;
	Cat copiedCat;
	

	for (int i = 0; i < ARR_SIZE; i++)
	{
		std::cout << i << std::endl;
		if (i % 2 == 0)
			arrAnimal[i] = new Dog();
		else
			arrAnimal[i] = new Cat();
	}
	castedCat = static_cast<Cat *>(arrAnimal[1]);

	castedCat->getBrain().getIdea(0).assign("meow!");
	castedCat->getBrain().getIdea(1).assign("meow!!");
	castedCat->getBrain().getIdea(2).assign("meow!!!");
	copiedCat = *castedCat;

	std::cout << copiedCat.getBrain().getIdea(0) << std::endl;
	std::cout << copiedCat.getBrain().getIdea(1) << std::endl;
	std::cout << copiedCat.getBrain().getIdea(2) << std::endl;

	for (int i = 0; i < ARR_SIZE; i++)
	{
		delete arrAnimal[i];
	}
	std::cout << "------------------" << std::endl;
	return 0;
}