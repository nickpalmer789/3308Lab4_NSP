#include <iostream>

using namespace std;

//Make animal an abstract class
class Animal {
public:
	//A pure virtual function to make Animal abstract
	//This function must be implemented in the derived classes
	virtual void makeSound() = 0;

	//This function is inherited in the derived classes
	string getGender() {
		return gender;
	}

	int getNumberOfLegs() {
		return numberOfLegs;
	}


protected:
	//Make numberOfLegs protected so that it is accessible in the derived classes
	int numberOfLegs;
	string gender;
};

class Dog:public Animal {
public:
	Dog(int legs, string gen) {
		numberOfLegs = legs;
		gender = gen;
	};
	Dog() {};

	//Inherited from the base class
	void makeSound() {
		cout<<"Woof Woof!"<<endl;
	}

	//Not Inherited from base class
	void wagTail() {
		cout<<"The dog wags its tail"<<endl;
	}
};

class Cat:public Animal {
public:
	Cat(int legs, string gen) {
		numberOfLegs = legs;
		gender = gen;
	}
	Cat() {};

	//Inherited from base class
	void makeSound() {
		cout<<"Meow..."<<endl;
	}

	//Not inherited from base class
	void knockStuffOffTable() {
		cout<<"The cat looks at you and knocks stuff off the table."<<endl;
	}
};




int main() {

	//Do some stuff with Dog
	cout<<"Doing stuff with the Dog class:"<<endl;
	Dog myDog(4, "male");
	myDog.makeSound();
	myDog.wagTail();
	cout<<"myDog has "<<myDog.getNumberOfLegs()<<" legs."<<endl;
	cout<<"myDog is "<<myDog.getGender()<<endl;

	//Do some stuff with Cat
	cout<<"Doing stuff with the Cat class:"<<endl;
	Cat myCat(4, "female");
	myCat.makeSound();
	myCat.knockStuffOffTable();
	cout<<"myCat has "<<myCat.getNumberOfLegs()<<" legs."<<endl;
	cout<<"myCat is "<<myCat.getGender()<<endl;

	return 0;
}
