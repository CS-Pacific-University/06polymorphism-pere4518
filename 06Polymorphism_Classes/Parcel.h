//*****************************************************************************
// File name:  Parcel.h
// Author:     Ali Perez-Suiter
// Date:       4/20/21
// Class:      CS250
// Assignment: Polymorphism
// Purpose:    Declares a programmer-defined class Parcel.
//*****************************************************************************

#pragma once
#include "Parcel.h"
#include <iostream>
#include <string>

using namespace std;

class Parcel {

public:
  Parcel ();
  Parcel (int trackingNum, string to, string from, int weight, int distance, 
          bool rushed, bool insured);

  virtual int getWeight () const;
  virtual int getDistance () const;

  virtual double getRush (double cost) const = 0;
  virtual double getInsurance (double cost) const = 0;
  virtual double getCost () const = 0;
  virtual int getTravelTime () const = 0;

  virtual bool isRushed () const;
  virtual bool isInsured () const;

  virtual Parcel& addRush ();
  virtual Parcel& addInsurance ();

  virtual bool read (istream& rcIn);
  virtual void print (ostream& rcOut) const;

private:
  int mTrackingNum;
  string mTo;
  string mFrom;
  int mWeight;
  int mDistance;
  bool mRushed;
  bool mInsured;
};

