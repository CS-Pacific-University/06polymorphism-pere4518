//*****************************************************************************
// File name:  Postcard.h
// Author:     Ali Perez-Suiter
// Date:       4/20/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Declares a programmer-defined class Postcard.
//*****************************************************************************

#pragma once
#include "Parcel.h"
#include <iostream>
#include <string>

using namespace std;

class Postcard : public Parcel {

public:
  Postcard ();
  Postcard (int trackingNum, string to, string from, int weight, int distance,
            bool rushed, bool insured, string message);

  int getWeight () const;
  int getDistance () const;

  double getCost () const;
  int getTravelTime () const;

  bool isRushed () const;
  bool isInsured () const;

  Parcel& addRush ();
  Parcel& addInsurance ();

  virtual bool read (istream& rcIn);
  virtual void print (ostream& rcOut) const;

  const double COST_POSTCARD = 0.15;
  const double INSURANCE_POSTCARD = 0.15;
  const double RUSH_POSTCARD = 0.25;

private:
  const int TRAVEL_PER_DAY_POSTCARD = 10;

  string mMessage;
};

