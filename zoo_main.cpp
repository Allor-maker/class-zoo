#include <iostream>
#include "animal.h"
#include "zoo.h"

int Zoo::count = 0;
int Zoo::count_mammals = 0;
int main()
{
	
	Cat Barsic;
	Barsic.play();
	Barsic.call();

	Dog Pedro;
	Pedro.bring_ball();
	Pedro.sleep();

	Fox Lissa;
	Lissa.pet();
	Lissa.sound();
	
	Fish Bob;
	Bob.swim();

	parrot Ted;
	Ted.laugh();

	Zoo first;
	
	first.add(&Barsic);
	first.add(&Pedro);
	first.add(&Lissa);
	first.add(&Bob);
	first.add(&Ted);

	first.listen();
	Zoo::get_count();

	first.er(Barsic.id_get());

	Zoo::get_count();
	Zoo::get_mammal();
	first.list();
	

}