/*
The base class Pet has protected data members petName, and petAge. The derived class Dog extends the Pet class and includes a private data member for dogBreed. Complete main() to:

create a generic pet and print information using PrintInfo().
create a Dog pet, use PrintInfo() to print information, and add a statement to print the dog's breed using the GetBreed() function.
Ex. If the input is:


*/

#include <iostream>
#include <string>
#include "Dog.h"

using namespace std;

int main()
{

    string petName, dogName, dogBreed;
    int petAge, dogAge;

    Pet myPet;
    Dog myDog;

    getline(cin, petName);
    cin >> petAge;
    cin.ignore();
    getline(cin, dogName);
    cin >> dogAge;
    cin.ignore();
    getline(cin, dogBreed);

    // TODO: Create generic pet (using petName, petAge) and then call PrintInfo
    Pet pet;
    pet.SetName(petName);
    pet.SetAge(petAge);
    pet.PrintInfo();
    // TODO: Create dog pet (using dogName, dogAge, dogBreed) and then call PrintInfo
    Dog dog_pet;
    dog_pet.SetName(dogName);
    dog_pet.SetAge(dogAge);
    dog_pet.SetBreed(dogBreed);
    dog_pet.PrintInfo();
    // TODO: Use GetBreed(), to output the breed of the dog
    cout << "   Breed: " << dog_pet.GetBreed() << endl;
}
