#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define ARR_SIZE 4

int main()
{
	{
		std::cout << "-----[Exer 1]-----" << std::endl;
		Animal* castedCat;
		Cat* cat;

		castedCat = new Cat();	// auto casting.
		cat = new Cat();

		// Animal* animal;
		// 🌟C++ error: object of abstract class type is not allowed: pure virtual function has no overrider
		// animal = new Animal();
		// animal = new Animal(*castedCat);

		std::cout << "------------------" << std::endl;
	}
	{
		std::cout << "-----[Exer 2]-----" << std::endl;
		Animal* arrAnimal[ARR_SIZE];
		Cat* castedCat;
		Cat copiedCat;
		
		for (int i = 0; i < ARR_SIZE; i++)
		{
			if (i % 2 == 0)
				arrAnimal[i] = new Dog();
			else
				arrAnimal[i] = new Cat();
		}
		castedCat = dynamic_cast<Cat *>(arrAnimal[1]);
		if (castedCat == NULL)
			return 1;

		std::cout << copiedCat.getBrain().getIdea(0) << std::endl;
		std::cout << copiedCat.getBrain().getIdea(1) << std::endl;
		std::cout << copiedCat.getBrain().getIdea(2) << std::endl;

		castedCat->getBrain().getIdea(0).assign("meow!");
		castedCat->getBrain().getIdea(1).assign("meow!!");
		castedCat->getBrain().getIdea(2).assign("meow!!!");
		copiedCat.getBrain() = castedCat->getBrain();

		std::cout << copiedCat.getBrain().getIdea(0) << std::endl;
		std::cout << copiedCat.getBrain().getIdea(1) << std::endl;
		std::cout << copiedCat.getBrain().getIdea(2) << std::endl;

		for (int i = 0; i < ARR_SIZE; i++)
		{
			delete arrAnimal[i];
		}
		std::cout << "------------------" << std::endl;
	}
	return 0;
}