#pragma once
#include <vector>
#include <iostream>
#include "animal.h"

class Zoo
{
private:
	static int count;
	std::vector<animal*> animals;
	
public:
	Zoo()
	{}
	void add(animal* a)
	{	
		++count;
		animals.push_back(a);
		a->id_set(count - 1);
	}
	void er(int id) 
	{
		--count;
		animals.erase(animals.begin()+id);
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
	void list()
	{
		std::cout << "Animals:" << std::endl;
		for (int i = 0; i < count; i++)
		{
			std::cout <<i+1<<"."<< animals[i]->get_name() << std::endl;
		}
	}
	
};