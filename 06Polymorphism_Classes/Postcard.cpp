//*****************************************************************************
// File name:  Postcard.cpp
// Author:     Ali Perez-Suiter
// Date:       4/20/21
// Class:      CS250
// Assignment: Polymorphisim
// Purpose:    Implements constructors & funcitons of class Postcard.
//*****************************************************************************

#include "Postcard.h"

Postcard::Postcard () : Parcel() {

  mMessage = "No Message";

}

Postcard::Postcard (int trackingNum, string to, string from, int weight, int 
                    distance, bool rushed, bool insured, string message) : 
                    Parcel (trackingNum, to, from, weight, distance, rushed, 
                            insured) {

  mMessage = message;

}

int Postcard::getWeight () const {

  return Parcel::getWeight ();

}

int Postcard::getDistance () const {

  return Parcel::getDistance ();

}

double Postcard::getCost () const {

  double cost = COST_POSTCARD;

  if (isRushed ()) {

    cost += RUSH_POSTCARD;

  }

  if (isInsured ()) {

    cost += INSURANCE_POSTCARD;

  }

  return cost;
}

int Postcard::getTravelTime () const {

  int minimumTravel = 1;
  int travelTime = minimumTravel;
  int distance = getDistance ();

  travelTime = TRAVEL_PER_DAY_POSTCARD % distance;

  if (isRushed () && travelTime > minimumTravel) {

    travelTime -= 1;

  }


  return travelTime;
}

bool Postcard::isRushed () const {

  return Parcel::isRushed ();

}

bool Postcard::isInsured () const {

  return Parcel::isInsured ();

}

Parcel& Postcard::addRush () {

  &Parcel::addRush ();

  return *this;

}

Parcel& Postcard::addInsurance () {

  &Parcel::addInsurance ();

  return *this;

}

bool Postcard::read (istream& rcIn) {

  bool bIsRead = true;

  if (!(Parcel::read (rcIn)) && rcIn >> mMessage) {

    bIsRead = false;

  }

  return bIsRead;

}

void Postcard::print (ostream& rcOut) const {

  Parcel::print (rcOut);

  rcOut << mMessage << "\t";

}