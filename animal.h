#pragma once
#include <iostream>

class animal
{
protected:
	int id = 0;
	std::string name = "animal";
	std::string eat_cond;
	
public:
	animal(std::string name,std::string eat_cond,int id = 0) : name(name),eat_cond(eat_cond), id(id) {}
	animal() {}

	void eat() const
	{
		std::cout << name << " is eating" << eat_cond << std::endl;
	}
	void sleep() const
	{
		std::cout << name << " is sleeping" << std::endl;
	}
	virtual void sound() const
	{
		std::cout << "..." << std::endl;
	}
	void id_set(int i)
	{
		id = i;
	}
	int id_get() const
	{
		return id;
	}
	std::string get_name() const
	{
		return name;
	}
	virtual ~animal() {};
};

class Bird : public animal
{
public:
	Bird() :animal("bird", "grains", 1) {}
	Bird(std::string n,std::string food,int id):animal(n,food,id) {}

	void play() const
	{
		std::cout << name << " is playing" << std::endl;
	}
};

class parrot :public Bird
{
protected:
	std::string sound_ = "";
public:
	parrot():Bird("parrot", "grains",11),sound_("On board!!") {}
	parrot(std::string n,std::string food,int id,std::string s):Bird(n,food,id),sound_(s) {}

	void sound() const override 
	{	
		std::cout << sound_ << std::endl;
	}
	void laugh() const
	{
		std::cout << "Ha-ha-ha" << std::endl;
	}
};
class Mammal : public animal
{
public:
	Mammal() : animal("mammal", "meat", 2) {}
	Mammal(std::string n, std::string cond, int id) :animal(n, cond, id) {}

	void play() const 
	{
		std::cout << name << " is playing" << std::endl;
	}
	
};

class Cat :public Mammal
{
protected:
	std::string sound_ = "";
public:
	Cat():Mammal("Cat", "milk", 21),sound_("Meow") {}
	Cat(std::string n, std::string eat, std::string s, int id) :Mammal(n, eat_cond, id),sound_(s) {}

	void call() const
	{
		std::cout << "Come here " << name<<std::endl;
	}
	void sound() const override
	{
		std::cout << sound_ << std::endl;
	}
};
class Dog :public Mammal
{
protected:
	std::string sound_ = "";
public:
	Dog() :Mammal("Dog", "dog food", 22), sound_("Gaf-Gaf") {}
	Dog(std::string n, std::string eat, std::string s, int id) :Mammal(n, eat_cond, id), sound_(s) {}

	void bring_ball() const
	{
		std::cout<<name << " brought the ball " << std::endl;
	}
	void sound() const override
	{
		std::cout << sound_ << std::endl;
	}
};
class Fox :public Mammal
{
protected:
	std::string sound_ = "";
public:
	Fox() :Mammal("Fox", "chicken", 23), sound_("Tyaf") {}
	Fox(std::string n, std::string eat, std::string s, int id) :Mammal(n, eat_cond, id), sound_(s) {}

	void pet() const
	{
		std::cout << "You're petting the " << name << std::endl;
	}
	void sound() const override
	{
		std::cout << sound_ << std::endl;
	}
};

class Fish : public animal
{
public:
	Fish() :animal("Fish", "food", id) {}
	Fish(std::string n,int id,std::string cond,std::string s):animal(n,cond,id) {}

	void swim() const
	{
		std::cout << name << " is swimming" << std::endl;
	}
};