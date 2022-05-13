#include "Serializer.hpp"
#include <iostream>

int main()
{
	Serializer serializer;
	Data data = {"gyeon", 29, 42.42};
	Data *reSerializedData;

	reSerializedData = serializer.deserialize(serializer.serialize(&data));

	std::cout << "--------------------[Compare]-------------------" << std::endl;
	std::cout << "ptr :" << &data << "\t| " << "ptr :" << reSerializedData << std::endl;
	std::cout << "name :" << data.name << "\t\t| " << "name :" << reSerializedData->name << std::endl;
	std::cout << "value1 :" << data.value1 << "\t\t| " << "value1 :" << reSerializedData->value1 << std::endl;
	std::cout << "value2 :" << data.value2 << "\t\t| " << "value2 :" << reSerializedData->value2 << std::endl;

	return 0;
}