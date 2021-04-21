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
  ~Parcel ();

  //virtual double getCost () const = 0;
  //virtual int getTravelTime () const = 0;

  //virtual Parcel& addRushed () = 0;
  //virtual Parcel& addInsurance () = 0;

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

