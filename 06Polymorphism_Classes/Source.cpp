//*****************************************************************************
// File name:     Source.cpp
// Author:        Ali Perez-Suiter
// Date:          4/20/2021
// Class:         CS250
// Assignment:    Polymorphism 
// Purpose:       Break up a program into well-defined functions, build a class
//                heirarchy to demonstrate use of polymorphisim, virtual
//                functions, and dynamic memory.
// Hours Worked:  4 hours, 57 minutes
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
void printAllParcels (Parcel* pcParcels[MAXIMUM], int numParcels);

int main() {
  const string TITLE = "Mail Simulator!";

  Letter cTest1 (01, "ME", "YOU", 10, 10, false, false);
  Letter cTest2();
  Parcel *apcParcels[MAXIMUM] = {nullptr};
  char ParcelType;
  double price;
  ifstream inputFile;
  int numParcels = 0;
  int menuChoice = 0;
  int parcelChoice = 0;
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

      getParcelPosition (parcelPosition, numParcels);

      parcelPosition--;

      apcParcels[parcelPosition]->addInsurance ();

      price = apcParcels[parcelPosition]->getCost ();

      cout << "Added Insurance for $" 
           << apcParcels[parcelPosition]->getInsurance(price) << endl;

      apcParcels[parcelPosition]->print (cout);

      cout << endl << endl;

    }
    else if (menuChoice == RUSH) {

      cTest1.addRush ();

    }
    else if (menuChoice == DELIVER) {

      cout << cTest1.getCost ();

    }

  } while (menuChoice != QUIT);


  //cTest1.print (cout);
  //cout << endl;
  //cTest2.print (cout);

  inputFile.close ();

  cout << "Reached the end!\n";
  return EXIT_SUCCESS;
}

void openFile (ifstream& rInputFile, string fileName) {

  rInputFile.open (fileName);

  if (rInputFile.fail ()) {

    cout << "File failed to open." << endl << endl;

    exit (EXIT_FAILURE);

  }

}

void printMenu () {

  cout << "1. Print All" << endl
       << "2. Add Insurance" << endl
       << "3. Add Rush" << endl
       << "4. Deliver" << endl
       << "5. Quit" << endl << endl;

}

void getMenuChoice (int& rChoice) {

  do {

    cout << "Choice> ";

    cin >> rChoice;

    cout << endl;

  } while (rChoice != PRINT && rChoice != INSURE && rChoice != RUSH 
           && rChoice != DELIVER && rChoice != QUIT);

}

void getParcelPosition (int& rParcel, int numParcels) {

  do {

    cout << "TID> ";

    cin >> rParcel;

  } while (rParcel > numParcels && rParcel < 0);
  // 0 for no parcels, minimum number to choose is 1

}

void printAllParcels (Parcel* pcParcels[MAXIMUM], int numParcels) {

  for (int i = 0; i < numParcels; i++) {

    pcParcels[i]->print (cout);

    cout << endl;

  }

  cout << endl;

}