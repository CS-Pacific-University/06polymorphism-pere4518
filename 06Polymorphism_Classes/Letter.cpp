//*****************************************************************************
// File name:  Letter.cpp
// Author:     Ali Perez-Suiter
// Date:       4/20/21
// Class:      CS250
// Assignment: Polymorphisim
// Purpose:    Implements constructors & funcitons of class Letter.
//*****************************************************************************

#include "Letter.h"

Letter::Letter () : Parcel() {

}

Letter::Letter (int trackingNum, string to, string from, int weight, int distance,
                bool rushed, bool insured) : Parcel (trackingNum, to, from, 
                weight, distance, rushed, insured) {

}


int Letter::getWeight () const {

  return Parcel::getWeight ();

}

int Letter::getDistance () const {

  return Parcel::getDistance ();

}
double Letter::getRush (double cost) const {

  double rush;

  rush = cost * RUSH_LETTER;

  return rush;

}

double Letter::getInsurance (double cost) const {

  double insurance;

  insurance = INSURANCE_LETTER;

  return insurance;

}

double Letter::getCost () const {

  double cost = COST_LETTER * getWeight();
  
  return cost;
}

int Letter::getTravelTime () const {

  int minimumTravel = 1;
  int travelTime = minimumTravel;
  int distance = getDistance ();

  travelTime = TRAVEL_PER_DAY_LETTER % distance;

  if (isRushed () && travelTime > minimumTravel) {

    travelTime -= 1;

  }


  return travelTime;

}

bool Letter::isRushed () const {

  return Parcel::isRushed ();

}

bool Letter::isInsured () const {

  return Parcel::isInsured ();

}

Parcel& Letter::addRush () {

  &Parcel::addRush ();

  return *this;

}

Parcel& Letter::addInsurance () {

  &Parcel::addInsurance ();

  return *this;

}

bool Letter::read (istream& rcIn) {

  bool bIsRead = true;

  if (!(Parcel::read (rcIn))) {

    bIsRead = false;

  }

  return bIsRead;

}

void Letter::print (ostream& rcOut) const {

  Parcel::print (rcOut);

}