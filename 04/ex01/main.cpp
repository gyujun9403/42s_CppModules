#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define ARR_SIZE 100

int main()
{
	std::cout << "-----[Exer 1]-----" << std::endl;
	Animal* arrAnimal[ARR_SIZE];
	Cat copiedCat;
	

	for (int i = 0; i < ARR_SIZE; i++)
	{
		if (i % 2 == 0)
			arrAnimal[i] = new Dog();
		else
			arrAnimal[i] = new Cat();
	}
	{
		std::cout << "-------[Exer 1]-------" << std::endl;
		Cat* castedCat;
		castedCat = dynamic_cast<Cat *>(arrAnimal[1]);
		if (castedCat == NULL)
			return 1;
		std::cout << copiedCat.getBrain().getIdea(0) << std::endl;
		std::cout << copiedCat.getBrain().getIdea(1) << std::endl;
		std::cout << copiedCat.getBrain().getIdea(2) << std::endl;

		castedCat->getBrain().getIdea(0).assign("meow!");
		castedCat->getBrain().getIdea(1).assign("meow!!");
		castedCat->getBrain().getIdea(2).assign("meow!!!");
		// 🌟 deep copy cat's brain!
		copiedCat.getBrain() = castedCat->getBrain();

		std::cout << copiedCat.getBrain().getIdea(0) << std::endl;
		std::cout << copiedCat.getBrain().getIdea(1) << std::endl;
		std::cout << copiedCat.getBrain().getIdea(2) << std::endl;
	}
	{
		std::cout << "-------[Exer 2]-------" << std::endl;
		Cat* castedCat1;
		Cat* castedCat2;
		castedCat1 = dynamic_cast<Cat *>(arrAnimal[1]);
		castedCat2 = dynamic_cast<Cat *>(arrAnimal[3]);
		if (castedCat1 == NULL || castedCat2 == NULL)
			return 1;
		castedCat2 = castedCat1;
		std::cout << castedCat2->getBrain().getIdea(0) << std::endl;
		std::cout << castedCat2->getBrain().getIdea(1) << std::endl;
		std::cout << castedCat2->getBrain().getIdea(2) << std::endl;	
	}
	// 🌟 brain do deep copy. so, copiedCat takes no effect about delete arrAnimal[i];
	for (int i = 0; i < ARR_SIZE; i++)
	{
		delete arrAnimal[i];
	}
	std::cout << "------------------" << std::endl;
	return 0;
}
