//*****************************************************************************
// File name:     Source.cpp
// Author:        Ali Perez-Suiter
// Date:          4/20/2021
// Class:         CS250
// Assignment:    Polymorphism 
// Purpose:       Break up a program into well-defined functions, build a class
//                heirarchy to demonstrate use of polymorphisim, virtual
//                functions, and dynamic memory.
// Hours Worked:  9 hours, 7 minutes
//*****************************************************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Parcel.h"
#include "Letter.h"
#include "Postcard.h"
#include "Overnight.h"

using namespace std;

const int MAXIMUM = 25;
const int PRINT = 1;
const int INSURE = 2;
const int RUSH = 3;
const int DELIVER = 4;
const int QUIT = 5;
const char LETTER = 'L';
const char POSTCARD = 'P';
const char OVERNIGHT = 'O';
const string TEXT_FILE = "parcels.txt";

void openFile (ifstream& rInputFile, string fileName);
void printMenu ();
void getMenuChoice (int& rChoice);
void getParcelPosition (int& rParcel, int numParcels);
void printAllParcels (Parcel* apcParcels[MAXIMUM], int numParcels);
double getFullCost (Parcel* pcParcel);
bool isNullPointer (Parcel* pcParcel);
void getParcel (Parcel* apcParcel[MAXIMUM], int numParcels, int& rParcel);
int getDaysTraveled (Parcel* pcParcel);

//*****************************************************************************
// Function:    main
//
// Description: Implements and executes code.
//
// Parameters:  None.
//
// Returned:    Return status.
//*****************************************************************************

int main() {
  const string TITLE = "Mail Simulator!";

  Letter cTest1 (01, "ME", "YOU", 10, 10, false, false);
  //Letter cTest2();
  Parcel *apcParcels[MAXIMUM] = {nullptr};
  char ParcelType;
  double price = 0.00;
  ifstream inputFile;
  int numParcels = 0;
  int menuChoice = 0;
  int parcelPosition;

  openFile (inputFile, TEXT_FILE);

  cout << TITLE << endl << endl;

  cout << fixed << setprecision (2);

  while (!(inputFile.eof ()) && numParcels < MAXIMUM) {

    inputFile >> ParcelType;

    if (ParcelType == LETTER) {

      apcParcels[numParcels] = new Letter ();

      apcParcels[numParcels]->read (inputFile);

      numParcels++;

    }
    else if (ParcelType == POSTCARD) {

      apcParcels[numParcels] = new Postcard ();

      apcParcels[numParcels]->read (inputFile);

      numParcels++;

    }
    else if (ParcelType == OVERNIGHT) {

      apcParcels[numParcels] = new Overnight ();

      apcParcels[numParcels]->read (inputFile);

      numParcels++;

    }
  }

  do {

    printMenu ();

    getMenuChoice (menuChoice);

    if (menuChoice == PRINT) {

      printAllParcels (apcParcels, numParcels);

    }
    else if (menuChoice == INSURE) {

      getParcel (apcParcels, numParcels, parcelPosition);

      apcParcels[parcelPosition]->addInsurance ();

      price = apcParcels[parcelPosition]->getCost ();

      cout << "Added Insurance for $" 
           << apcParcels[parcelPosition]->getInsurance(price) << endl;

      apcParcels[parcelPosition]->print (cout);

      cout << endl << endl;

    }
    else if (menuChoice == RUSH) {

      getParcel (apcParcels, numParcels, parcelPosition);

      apcParcels[parcelPosition]->addRush ();

      cout << "Added Rush for $"
        << apcParcels[parcelPosition]->getRush (price) << endl;

      apcParcels[parcelPosition]->print (cout);

      cout << endl << endl;
    }
    else if (menuChoice == DELIVER) {

      getParcel (apcParcels, numParcels, parcelPosition);

      cout << "Delivered!" << endl
        << getDaysTraveled(apcParcels[parcelPosition]) << " Day, $"
        << getFullCost (apcParcels[parcelPosition]) << endl;

      apcParcels[parcelPosition]->print (cout);

      cout << endl << endl;

      apcParcels[parcelPosition] = nullptr;
    }

  } while (menuChoice != QUIT);


  //cTest1.print (cout);
  //cout << endl;
  //cTest2.print (cout);

  inputFile.close ();

  delete[] *apcParcels;

  //cout << "Reached the end!\n";
  return EXIT_SUCCESS;
}

//*****************************************************************************
// Function:    openFile
//
// Description: Open a file and check if opened correctly.
//
// Parameters:  rInputFile - File to open.
//              fileName   - Name of file to open.
//
// Returned:    Exit failure if not opened correctly, none otherwise.
//*****************************************************************************

void openFile (ifstream& rInputFile, string fileName) {

  rInputFile.open (fileName);

  if (rInputFile.fail ()) {

    cout << "File failed to open." << endl << endl;

    exit (EXIT_FAILURE);

  }

}

//*****************************************************************************
// Function:    printMenu
//
// Description: Print menu of choices for user to choose from.
//
// Parameters:  None.
//
// Returned:    None.
//*****************************************************************************

void printMenu () {

  cout << "1. Print All" << endl
       << "2. Add Insurance" << endl
       << "3. Add Rush" << endl
       << "4. Deliver" << endl
       << "5. Quit" << endl << endl;

}

//*****************************************************************************
// Function:    getMenuChoice
//
// Description: Get the user's choice from the menu, continues to ask for 
//              choice if not a valid choice.
//
// Parameters:  rChoice - Choice the user inputs.
//
// Returned:    None.
//*****************************************************************************

void getMenuChoice (int& rChoice) {

  do {

    cout << "Choice> ";

    cin >> rChoice;

    cout << endl;

  } while (rChoice != PRINT && rChoice != INSURE && rChoice != RUSH 
           && rChoice != DELIVER && rChoice != QUIT);

}

//*****************************************************************************
// Function:    getParcelPosition
//
// Description: Get a specific parcel from the user, will continue to ask if
//              user inputs number less than 0 or higher than the amount of 
//              parcels.
//
// Parameters:  rParcel    - User's input of parcel to choose.
//              numParcels - Amount of parcels in an array to choose from.
//
// Returned:    None.
//*****************************************************************************

void getParcelPosition (int& rParcel, int numParcels) {

  do {

    cout << "TID> ";

    cin >> rParcel;

  } while (rParcel > numParcels && rParcel < 0);
  // 0 for no parcels, minimum number to choose is 1

}

//*****************************************************************************
// Function:    printAllParcels
//
// Description: Print all parcels in an array that aren't null pointers.
//
// Parameters:  apcParcels - Array of parcels to print out.
//              numParcels - Amount of parcels in the array.
//
// Returned:    None.
//*****************************************************************************

void printAllParcels (Parcel* apcParcels[MAXIMUM], int numParcels) {

  for (int i = 0; i < numParcels; i++) {

    if (apcParcels[i]) {

      apcParcels[i]->print (cout);

      cout << endl;

    }

  }

  cout << endl;

}

//*****************************************************************************
// Function:    getFullCost
//
// Description: Get the total cost of a parcel. If rushed and/or insured, will
//              add to total cost.
//
// Parameters:  pcParcel - Parcel to get cost from.
//
// Returned:    Total cost of parcel.
//*****************************************************************************

double getFullCost (Parcel* pcParcel) {

  double cost = pcParcel->getCost ();

  if (pcParcel->isRushed ()) {

    cost += pcParcel->getRush (cost);

  }

  if (pcParcel->isInsured ()) {

    cost += pcParcel->getInsurance (cost);

  }

  return cost;
}

//*****************************************************************************
// Function:    isNullPointer
//
// Description: Check if a parcel is a null pointer.
//
// Parameters:  pcParcel - Parcel to check for null.
//
// Returned:    True if parcel is a null pointer, false otherwise.
//*****************************************************************************

bool isNullPointer (Parcel* pcParcel) {

  bool bIsNull = false;

  if (pcParcel == nullptr) {

    bIsNull = true;

  }

  return bIsNull;
}

//*****************************************************************************
// Function:    getParcel
//
// Description: Uses getParcelPosition and isNullPointer to check if a specific
//              parcel in an array is a null pointer, will continue to ask if
//              parcel is null.
//
// Parameters:  apcParcels - Array of pointers to parcels.
//              numParcels - Amount of parcels in the array.
//              rParcel    - User's input of parcel to choose.
//
// Returned:    None.
//*****************************************************************************

void getParcel (Parcel* apcParcel[MAXIMUM], int numParcels, int& rParcel) {

  do {

    getParcelPosition (rParcel, numParcels);

    rParcel--;

  } while (isNullPointer (apcParcel[rParcel]));

}

//*****************************************************************************
// Function:    getDaysTraveled
//
// Description: Get the days traveled of a parcel.
//
// Parameters:  pcParcel - Parcel to get days traveled from.
//
// Returned:    Days traveled of parcel.
//*****************************************************************************

int getDaysTraveled (Parcel* pcParcel) {

  int days = pcParcel->getTravelTime ();

  return days;

}