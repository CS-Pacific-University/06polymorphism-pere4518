//*****************************************************************************
// File name:  Overnight.h
// Author:     Ali Perez-Suiter
// Date:       4/20/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Declares a programmer-defined class Overnight.
//*****************************************************************************

#pragma once
#include "Parcel.h"
#include <iostream>
#include <string>

using namespace std;

class Overnight : public Parcel {

public:
  Overnight ();
  Overnight (int trackingNum, string to, string from, int weight, int distance,
             bool rushed, bool insured, int volume);

  int getWeight () const;
  int getDistance () const;

  double getRush (double cost) const;
  double getInsurance (double cost) const;
  double getCost () const;
  int getTravelTime () const;

  bool isRushed () const;
  bool isInsured () const;

  Parcel& addRush ();
  Parcel& addInsurance ();

  virtual bool read (istream& rcIn);
  virtual void print (ostream& rcOut) const;

private:
  const double COST_UNDER_100 = 12.00;
  const double COST_OVER_100 = 20.00;
  const double INSURANCE_OVERNIGHT = 0.25;
  const double RUSH_OVERNIGHT = 0.75;
  const int TRAVEL_PER_DAY_OVERNIGHT = 1000;

  int mVolume;
};

