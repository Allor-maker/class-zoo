#pragma once
#include <vector>
#include <iostream>
#include "animal.h"

class Zoo
{
private:
	int id = 0;
	static int count;
	std::vector<animal*> animals;
	static int count_mammals;
public:
	Zoo()
	{}
	void add(animal* a)
	{	
		Mammal* m{ dynamic_cast<Mammal*>(a) };
		if (m != nullptr)
			++count_mammals;
		++count;
		animals.push_back(a);
		a->id_set(id);
		++id;
	}
	void er(int id) 
	{
		for (int i = 0; i < count; ++i)
		{
			if (animals[i]->id_get() == id)
			{
				Mammal* m{ dynamic_cast<Mammal*>(animals[i]) };
				if (m != nullptr)
					--count_mammals;
				animals.erase(animals.begin() + i);
			}
		}
		--count;
	}
	void listen() const
	{
		for (int i = 0; i < count; i++)
		{
			animals[i]->sound();
		}
	}
	static void get_count() 
	{
		std::cout << count << std::endl;
	}
	static void get_mammal()
	{
		std::cout << count_mammals << std::endl;
	}
	void list()
	{
		std::cout << "Animals:" << std::endl;
		for (int i = 0; i < count; i++)
		{
			std::cout <<i+1<<"."<< animals[i]->get_name() << std::endl;
		}
	}
	
};