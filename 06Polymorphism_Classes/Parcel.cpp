//*****************************************************************************
// File name:  Parcel.cpp
// Author:     Ali Perez-Suiter
// Date:       4/20/21
// Class:      CS250
// Assignment: Polymorphisim
// Purpose:    Implements constructors & funcitons of class Parcel.
//*****************************************************************************

#include "Parcel.h"

using namespace std;

//*****************************************************************************
// Constructor: Parcel
//
// Description: Initializes data members to default values.
//
// Parameters:  None.
//
// Returned:    None.
//*****************************************************************************

Parcel::Parcel () {

  mTrackingNum = 0;

  mTo = "AAA";

  mFrom = "BBB";

  mWeight = 0;

  mDistance = 0;

  mRushed = false;

  mInsured = false;

}

//*****************************************************************************
// Constructor: Parcel
//
// Description: Initializes data members to specific values.
//
// Parameters:  trackingNum - Tracking number of parcel.
//              to          - Who to send parcel to.
//              from        - Who sent parcel.
//              weight      - Weight of parcel (assume always in ounces).
//              distance    - Miles for parcel to travel.
//              rushed      - Status of parcel's rush.
//              insured     - Status of parcel's insurance.
//
// Returned:    None.
//*****************************************************************************

Parcel::Parcel (int trackingNum, string to, string from, int weight, 
                int distance, bool rushed, bool insured) {

  mTrackingNum = trackingNum;

  mTo = to;

  mFrom = from;

  mWeight = weight;

  mDistance = distance;

  mRushed = rushed;

  mInsured = insured;

}

//*****************************************************************************
// Function:    getWeight
//
// Description: Get parcel's mWeight.
//
// Parameters:  None.
//
// Returned:    Parcels's mWeight.
//*****************************************************************************

int Parcel::getWeight () const {

  return mWeight;

}

//*****************************************************************************
// Function:    getDistance
//
// Description: Get parcel's mDistance.
//
// Parameters:  None.
//
// Returned:    Parcels's mDistance.
//*****************************************************************************

int Parcel::getDistance () const {

  return mDistance;

}

//*****************************************************************************
// Function:    isRushed
//
// Description: Tell if parcel's mRush is true or false.
//
// Parameters:  None.
//
// Returned:    Parcels's mRush.
//*****************************************************************************

bool Parcel::isRushed () const {

  return mRushed;

}

//*****************************************************************************
// Function:    isInsured
//
// Description: Tell if parcel's mInsured is true or false.
//
// Parameters:  None.
//
// Returned:    Parcels's mInsured.
//*****************************************************************************

bool Parcel::isInsured () const {

  return mInsured;

}

//*****************************************************************************
// Function:    addRush
//
// Description: Initialized mRush to true.
//
// Parameters:  None.
//
// Returned:    Parcels's mRush to true.
//*****************************************************************************

Parcel& Parcel::addRush () {

  mRushed = true;

  return *this;

}

//*****************************************************************************
// Function:    addInsurance
//
// Description: Initialized mInsured to true.
//
// Parameters:  None.
//
// Returned:    Parcels's insurance to true.
//*****************************************************************************

Parcel& Parcel::addInsurance () {

  mInsured = true;

  return *this;

}

//*****************************************************************************
// Function:    read
//
// Description: Read in to initialize parcel.
//
// Parameters:  rcIn - Where to read from.
//
// Returned:    False if not read correctly, true otherwise.
//*****************************************************************************

bool Parcel::read (istream& rcIn) {

  bool bIsRead = true;

  if (!(rcIn >> mTrackingNum >> mTo >> mFrom >> mWeight >> mDistance)) {

    bIsRead = false;

  }

  return bIsRead;
}

//*****************************************************************************
// Function:    print
//
// Description: Print out parcel in a specific format. Will print out rush 
//              and/or insured if mRushed and/or mInsured is equal to true.
//
// Parameters:  rcOut - Where to print to.
//
// Returned:    None.
//*****************************************************************************

void Parcel::print (ostream& rcOut) const {

  rcOut << "TID: " << mTrackingNum << "\t"
        << "From: " << mFrom << "\t"
        << "To: " << mTo << "\t";

  if (mInsured) {

    rcOut << "INSURED\t";

  }

  if (mRushed) {

    rcOut << "RUSH\t";

  }

}