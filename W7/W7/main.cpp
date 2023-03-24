/////////////////////////////////////////////////////////
// Workshop 7: Derived Classes & Functions in a Hierarchy
// 
// Date:	10/29/2022
// Author:	Jitesh Arora
// File:	main.cpp
// 
// Last Updated 11/25/2022 by Jitesh Arora
// Version: 0.3 - Update based on initial feedback 
// 
// Description: Test program
////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS

#include "Fish.h"
#include "Dog.h"

using namespace sdds;
using namespace std;

Pet myPet("Cici");
Dog myDog("Scooby");
Fish myFish("Nemo");

// Display info for all pets
void displayPetsAll()
{
	cout << myPet << endl;
	cout << myDog << endl;
	cout << myFish << endl;
}

// Move to next day for all pets
void nextDayAll()
{
	myPet++;
	myDog++;
	myFish++;
}

int main()
{
	Pet* petList[3];
	petList[0] = &myPet;
	petList[1] = &myDog;
	petList[2] = &myFish;

	// Initial Set of Pets
	cout << "-------------------------------" << endl;
	cout << "------ New Borns: 3 Pets ------" << endl;
	displayPetsAll();

	// Under Nurture
	cout << "-------------------------------" << endl;
	cout << "-------- Under Nurture --------" << endl;
	for (int i = 0; i < 9; i++)
		nextDayAll();
	displayPetsAll();

	// Revive
	cout << "-------------------------------" << endl;
	cout << "----------- ReSpawn -----------" << endl;
	myPet.reSpawn();
	myDog.reSpawn();
	myFish.reSpawn();
	displayPetsAll();

	// Over Nurture: Test through Base class 
	cout << "-------------------------------" << endl;;
	cout << "---------- Over Nurture -------" << endl;
	for (int i = 0; i < 9; i++)
	{
		petList[i % 3]->feed();
		petList[i % 3]->groom();
		petList[i % 3]->hug();
	}
	// 0, 1 2 0 1 2 0 1 2 
	nextDayAll();
	displayPetsAll();

	cout << "-------------------------------" << endl;;
	cout << "------- Over Nurture: Dog -----" << endl;
	for (int i = 0; i < 5; i++)
	{
		myDog.walk();
		myDog.feed();
		myDog.groom();
	}
	cout << myDog << endl;
	myDog++;
	cout << myDog << endl;

	// ReSpawn our dog and take care of it for a while
	myDog.reSpawn();
	for (int i = 0; i < 10; i++)
	{
		myDog.feed(); myDog.walk();
		myDog.groom(); myDog.hug();
		myDog.feed(); myDog.walk();
		myDog++;
	}
	cout << "Testing--------------------------";
	cout << myDog;
	// Cloning 
	cout << "-------------------------------" << endl;;
	cout << "--------- Cloning: Dog --------" << endl;
	Dog* tempDog = new Dog("Mowgli");
	*tempDog = myDog;
	cout << *tempDog;
	tempDog->payBalance(cout);

	// Clone again, acitivity, clear balance
	Dog copiedDog("Clone");
	copiedDog = *tempDog;
	copiedDog.walk();
	copiedDog.feed();
	copiedDog.groom();
	copiedDog++;

	cout << endl << copiedDog;

	delete tempDog;

	cout << endl;
	cout << "-------------------------------" << endl;;
	cout << "----------- Complete ----------" << endl;
	return 0;
}


