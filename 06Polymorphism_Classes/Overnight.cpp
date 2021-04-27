//*****************************************************************************
// File name:  Overnight.cpp
// Author:     Ali Perez-Suiter
// Date:       4/20/21
// Class:      CS250
// Assignment: Polymorphisim
// Purpose:    Implements constructors & funcitons of class Overnight.
//*****************************************************************************

#include "Overnight.h"

//*****************************************************************************
// Constructor: Overnight
//
// Description: Initializes data members to default values. Use's Parcel's
//              constructor first.
//
// Parameters:  None.
//
// Returned:    None.
//*****************************************************************************

Overnight::Overnight () : Parcel () {

  mVolume = 0;

}

//*****************************************************************************
// Constructor: Overnight
//
// Description: Initializes data members to specific values. Uses Parcel's
//              constructor first.
//
// Parameters:  trackingNum - Tracking number of overnight.
//              to          - Who to send overnight to.
//              from        - Who sent overnigth.
//              weight      - Weight of overnight (assume always in ounces).
//              distance    - Miles for overnight to travel.
//              rushed      - Status of overnight's rush.
//              insured     - Status of overnight's insurance.
//              volume      - Volume of overnight.
//
// Returned:    None.
//*****************************************************************************

Overnight::Overnight (int trackingNum, string to, string from, int weight, 
                      int distance, bool rushed, bool insured, int volume) : 
                      Parcel (trackingNum, to, from, weight, distance, rushed, 
                              insured) {

  mVolume = volume;

}

//*****************************************************************************
// Function:    getWeight
//
// Description: Calls Parcel's getWeight to return weight of the overnight 
//              parcel.
//
// Parameters:  None.
//
// Returned:    Weight of overnight parcel.
//*****************************************************************************

int Overnight::getWeight () const {

  return Parcel::getWeight ();

}

//*****************************************************************************
// Function:    getDistance
//
// Description: Calls Parcel's getDistance to return distance of the overnight 
//              parcel.
//
// Parameters:  None.
//
// Returned:    Distance of overnight parcel.
//*****************************************************************************

int Overnight::getDistance () const {

  return Parcel::getDistance ();

}

//*****************************************************************************
// Function:    getRush
//
// Description: Calculates the cost of a overnight's rush.
//
// Parameters:  cost - Current cost of overnight.
//
// Returned:    Rush rate of overnight to add to cost.
//*****************************************************************************

double Overnight::getRush (double cost) const {

  double rush;

  rush = cost * RUSH_OVERNIGHT;

  return rush;

}

//*****************************************************************************
// Function:    getInsurance
//
// Description: Calculates the cost of a overnight's insurance.
//
// Parameters:  cost - Current cost of overnight.
//
// Returned:    Insurance rate of overnight to add to cost.
//*****************************************************************************

double Overnight::getInsurance (double cost) const {

  double insurance;

  insurance = cost * INSURANCE_OVERNIGHT;

  return insurance;

}

//*****************************************************************************
// Function:    getCost
//
// Description: Calculates the cost of an overnight.
//
// Parameters:  None.
//
// Returned:    Cost of overnight.
//*****************************************************************************

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

//*****************************************************************************
// Function:    getTravelTime
//
// Description: Calculates the days of travel for an overnight. If rushed and 
//              days are more than one, minus one day of travel.
//
// Parameters:  None.
//
// Returned:    Travel time of overnight.
//*****************************************************************************

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

//*****************************************************************************
// Function:    isRushed
//
// Description: Calls Parcel's isRushed to return if overnight has rush or not.
//
// Parameters:  None.
//
// Returned:    True if rushed, false otherwise.
//*****************************************************************************

bool Overnight::isRushed () const {

  return Parcel::isRushed ();

}

//*****************************************************************************
// Function:    isInsured
//
// Description: Calls Parcel's isInsured to return if overnight has insurance 
//              or not.
//
// Parameters:  None.
//
// Returned:    True if insured, false otherwise.
//*****************************************************************************

bool Overnight::isInsured () const {

  return Parcel::isInsured ();

}

//*****************************************************************************
// Function:    addRush
//
// Description: Calls Parcel's addRush to have overnight's rush equal true.
//
// Parameters:  None.
//
// Returned:    Overnight's rush to true.
//*****************************************************************************

Parcel& Overnight::addRush () {

  &Parcel::addRush ();

  return *this;

}


//*****************************************************************************
// Function:    addInsurance
//
// Description: Calls Parcel's addInsurance to have overnight's insurance equal 
//              true.
//
// Parameters:  None.
//
// Returned:    Overnight's insurance to true.
//*****************************************************************************

Parcel& Overnight::addInsurance () {

  &Parcel::addInsurance ();

  return *this;

}

//*****************************************************************************
// Function:    read
//
// Description: Read in to initialize overnight. Uses Parcel's read first.
//
// Parameters:  rcIn - Where to read from.
//
// Returned:    False if not read correctly, true otherwise.
//*****************************************************************************

bool Overnight::read (istream& rcIn) {

  bool bIsRead = true;

  if (!(Parcel::read (rcIn))) {

    bIsRead = false;

  }

  if (!(rcIn >> mVolume)) {

    bIsRead = false;

  }

  return bIsRead;

}

//*****************************************************************************
// Function:    print
//
// Description: Print out overnight in a specific format. Uses Parcel's print 
//              first.
//
// Parameters:  rcOut - Where to print to.
//
// Returned:    None.
//*****************************************************************************

void Overnight::print (ostream& rcOut) const {

  Parcel::print (rcOut);

  rcOut << "OVERNIGHT!" << "\t";

}