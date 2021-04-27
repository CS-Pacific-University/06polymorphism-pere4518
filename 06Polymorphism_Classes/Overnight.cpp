//*****************************************************************************
// File name:  Overnight.cpp
// Author:     Ali Perez-Suiter
// Date:       4/20/21
// Class:      CS250
// Assignment: Polymorphisim
// Purpose:    Implements constructors & funcitons of class Overnight.
//*****************************************************************************

#include "Overnight.h"

Overnight::Overnight () : Parcel () {

  mVolume = 0;

}

Overnight::Overnight (int trackingNum, string to, string from, int weight, 
                      int distance, bool rushed, bool insured, int volume) : 
                      Parcel (trackingNum, to, from, weight, distance, rushed, 
                              insured) {

  mVolume = volume;

}

int Overnight::getWeight () const {

  return Parcel::getWeight ();

}

int Overnight::getDistance () const {

  return Parcel::getDistance ();

}

double Overnight::getRush (double cost) const {

  double rush;

  rush = cost * RUSH_OVERNIGHT;

  return rush;

}

double Overnight::getInsurance (double cost) const {

  double insurance;

  insurance = cost * INSURANCE_OVERNIGHT;

  return insurance;

}

double Overnight::getCost () const {

  double cost = 0.00;

  if (mVolume > 100) {
    //100 determines price

    cost = COST_OVER_100;

  }
  else {

    cost = COST_UNDER_100;

  }

  return cost;
}

int Overnight::getTravelTime () const {

  int minimumTravel = 1;
  int travelTime = minimumTravel;
  int distance = getDistance ();

  if (distance > TRAVEL_PER_DAY_OVERNIGHT) {

    travelTime = 2; // days traveled if over 1000

  }

  if (isRushed () && travelTime > minimumTravel) {

    travelTime -= 1;

  }


  return travelTime;

}

bool Overnight::isRushed () const {

  return Parcel::isRushed ();

}

bool Overnight::isInsured () const {

  return Parcel::isInsured ();

}

Parcel& Overnight::addRush () {

  &Parcel::addRush ();

  return *this;

}

Parcel& Overnight::addInsurance () {

  &Parcel::addInsurance ();

  return *this;

}

bool Overnight::read (istream& rcIn) {

  bool bIsRead = true;

  if (!(Parcel::read (rcIn)) && rcIn >> mVolume) {

    bIsRead = false;

  }

  return bIsRead;

}

void Overnight::print (ostream& rcOut) const {

  Parcel::print (rcOut);

  rcOut << "OVERNIGHT!" << "\t";

}