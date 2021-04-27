//*****************************************************************************
// File name:  Letter.h
// Author:     Ali Perez-Suiter
// Date:       4/20/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Declares a programmer-defined class Letter.
//*****************************************************************************

#pragma once
#include "Parcel.h"
#include <iostream>
#include <string>

using namespace std;

class Letter : public Parcel {

public:
  Letter ();
  Letter (int trackingNum, string to, string from, int weight, int distance, 
          bool rushed, bool insured);

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
  const double COST_LETTER = 0.45;
  const double INSURANCE_LETTER = 0.45;
  const double RUSH_LETTER = 0.10;
  const int TRAVEL_PER_DAY_LETTER = 100;

};

