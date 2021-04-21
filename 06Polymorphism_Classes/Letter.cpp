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

Letter::~Letter () {

  delete this;

}

int Letter::getWeight () const {

  return Parcel::getWeight ();

}

double Letter::getCost () const {

  double cost = COST_LETTER * getWeight();

  //bool bRush = isRushed;
  //bool bInsure = isInsured;

  if (isRushed()) {

    double rushRate = cost * RUSH_LETTER;

    cost += rushRate;

  }

  if (isInsured()) {

    cost += INSURANCE_LETTER;

  }
  
  return cost;
}

int Letter::getTravelTime () const {

  int travelTime = 0;

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

  bool bIsRead = false;

  return bIsRead;

}

void Letter::print (ostream& rcOut) const {

  Parcel::print (rcOut);

}