
/*
Plant information (vector)
Given a base Plant class and a derived Flower class,
complete main() to create a vector called myGarden.
The vector should be able to store objects that belong
to the Plant class or the Flower class. Create a function
called PrintVector(), that uses the PrintInfo() functions
defined in the respective classes and prints each element
in myGarden. The program should read plants or flowers
from input (ending with -1), adding each Plant or Flower
to the myGarden vector, and output each element in myGarden
using the PrintInfo() function.
*/

// ~~~~~~~~~~~~~~~~~~ Solution 1 ~~~~~~~~~~~~~~~~~~
// #include "Plant.h"
// #include "Flower.h"
// #include <vector>
// #include <string>
// #include <iostream>

// using namespace std;

// // PrintVector method that prints a vector of plant (or flower) objects
// void PrintVector(vector<Plant> v)
// {

//     for (size_t i = 0; i < v.size(); ++i)
//     {
//         v.at(i).PrintInfo();
//     }
// }

// int main(int argc, char *argv[])
// {

//     string input;

//     // a vector called myGarden that can hold object of type plant
//     vector<Plant> myGarden;

//     cin >> input;

//     // variables - plantName, plantCost, colorOfFlowers, isAnnual
//     string plantName, colorOfFlowers, isAnnual;

//     int plantCost;

//     while (input != "-1")
//     {

//         if (input.compare("flower") == 0)
//         {
//             // TODO: Check if input is a plant or flower
//             //       Store as a plant object or flower object
//             //       Add to the ArrayList myGarden

//             Flower myFlower;
//             cin >> plantName >> plantCost >> colorOfFlowers >> isAnnual;

//             if (isAnnual.compare("true") == 0)
//             {
//                 myFlower.SetPlantType(true);
//             }
//             else
//             {
//                 myFlower.SetPlantType(false);
//             }
//             myFlower.SetPlantCost(plantCost);
//             myFlower.SetPlantName(plantName);
//             myFlower.SetColorOfFlowers(colorOfFlowers);
//             myGarden.push_back(myFlower);
//         }

//         else if (input.compare("plant") == 0)
//         {
//             Plant myPlant;
//             cin >> plantName >> plantCost;
//             myPlant.SetPlantCost(plantCost);
//             myPlant.SetPlantName(plantName);
//             myGarden.push_back(myPlant);
//         }
//     }

//     // Call the method PrintInfo to print myGarden
//     PrintVector(myGarden);

//     for (size_t i = 0; i < myGarden.size(); ++i)
//     {
//         delete myGarden.at(i);
//     }

//     return 0;
// }

// ~~~~~~~~~~~~~~~~~~ Solution 2 ~~~~~~~~~~~~~~~~~~
#include "Plant.h"
#include "Flower.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// PrintVector function that prints an vector of plant (or flower) object pointers
void PrintVector(vector<Plant *> myGarden)
{
    for (size_t i = 0; i < myGarden.size(); ++i)
    {
        myGarden[i]->PrintInfo();
        cout << endl;
    }
}

// main function
int main(int argc, char *argv[])
{

    // Declare a vector called myGarden that can hold object of type plant pointer
    vector<Plant *> myGarden;

    // Declare variables - plantName, plantCost, flowerName, flowerCost,
    string plantName, flowerName, buff;
    int plantCost, flowerCost;
    // Declare variables - colorOfFlowers, isAnnual
    bool isAnnual;
    string colorOfFlowers;

    Flower *flower;
    Plant *plant;

    string input;
    cin >> input;

    while (input != "-1")
    {
        // Check if input is a plant or flower

        // Store as a plant object or flower object
        if (input == "plant")
        {
            plant = new Plant;
            cin >> plantName;
            cin >> plantCost;
            plant->SetPlantName(plantName);
            plant->SetPlantCost(plantCost);
            myGarden.push_back(plant);
        }
        else if (input == "flower")
        {
            flower = new Flower;
            cin >> flowerName;
            cin >> flowerCost;
            cin >> buff;
            if (buff == "true")
                isAnnual = true;
            else
                isAnnual = false;
            cin >> colorOfFlowers;
            flower->SetPlantName(flowerName);
            flower->SetPlantCost(flowerCost);
            flower->SetPlantType(isAnnual);
            flower->SetColorOfFlowers(colorOfFlowers);
            myGarden.push_back(flower);
        }
        cin >> input;
    }

    // all the method PrintVector to print myGarden
    PrintVector(myGarden);

    for (size_t i = 0; i < myGarden.size(); ++i)
    {
        delete myGarden.at(i);
    }

    return 0;
}