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

Parcel::Parcel () {

  mTrackingNum = 0;

  mTo = "AAA";

  mFrom = "BBB";

  mWeight = 0;

  mDistance = 0;

  mRushed = false;

  mInsured = false;

}

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

Parcel::~Parcel () {

  delete this;
}

bool Parcel::read (istream& rcIn) {

  bool bIsRead = true;

  if (!(rcIn >> mTrackingNum >> mTo >> mFrom >> mWeight >> mDistance)) {

    bIsRead = false;

  }

  return bIsRead;
}

void Parcel::print (ostream& rcOut) const {

  rcOut << mTrackingNum << ' ' 
        << mTo << ' ' 
        << mFrom << ' '
        << mWeight << ' ' 
        << mDistance << ' ';

}