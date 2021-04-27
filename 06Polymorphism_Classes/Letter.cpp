//*****************************************************************************
// File name:  Letter.cpp
// Author:     Ali Perez-Suiter
// Date:       4/20/21
// Class:      CS250
// Assignment: Polymorphisim
// Purpose:    Implements constructors & funcitons of class Letter.
//*****************************************************************************

#include "Letter.h"

//*****************************************************************************
// Constructor: Letter
//
// Description: Initializes data members to default values. Use's Parcel's
//              constructor first.
//
// Parameters:  None.
//
// Returned:    None.
//*****************************************************************************

Letter::Letter () : Parcel() {

}

//*****************************************************************************
// Constructor: Letter
//
// Description: Initializes data members to specific values. Uses Parcel's 
//              constructor.
//
// Parameters:  trackingNum - Tracking number of letter.
//              to          - Who to send letter to.
//              from        - Who sent letter.
//              weight      - Weight of letter (assume always in ounces).
//              distance    - Miles for letter to travel.
//              rushed      - Status of letter's rush.
//              insured     - Status of letter's insurance.
//
// Returned:    None.
//*****************************************************************************

Letter::Letter (int trackingNum, string to, string from, int weight, int distance,
                bool rushed, bool insured) : Parcel (trackingNum, to, from, 
                weight, distance, rushed, insured) {

}

//*****************************************************************************
// Function:    getWeight
//
// Description: Calls Parcel's getWeight to return weight of the letter parcel.
//
// Parameters:  None.
//
// Returned:    Weight of letter parcel.
//*****************************************************************************

int Letter::getWeight () const {

  return Parcel::getWeight ();

}

//*****************************************************************************
// Function:    getDistance
//
// Description: Calls Parcel's getDistance to return distance of the letter 
//              parcel.
//
// Parameters:  None.
//
// Returned:    Distance of letter parcel.
//*****************************************************************************

int Letter::getDistance () const {

  return Parcel::getDistance ();

}

//*****************************************************************************
// Function:    getRush
//
// Description: Calculates the cost of a letter's rush.
//
// Parameters:  cost - Current cost of letter.
//
// Returned:    Rush rate of letter to add to cost.
//*****************************************************************************

double Letter::getRush (double cost) const {

  double rush;

  rush = cost * RUSH_LETTER;

  return rush;

}

//*****************************************************************************
// Function:    getInsurance
//
// Description: Calculates the cost of a letter's insurance.
//
// Parameters:  cost - Current cost of letter.
//
// Returned:    Insurance rate of letter to add to cost.
//*****************************************************************************

double Letter::getInsurance (double cost) const {

  double insurance;

  insurance = INSURANCE_LETTER;

  return insurance;

}

//*****************************************************************************
// Function:    getCost
//
// Description: Calculates the cost of a letter.
//
// Parameters:  None.
//
// Returned:    Cost of letter.
//*****************************************************************************

double Letter::getCost () const {

  double cost = COST_LETTER * getWeight();
  
  return cost;
}

//*****************************************************************************
// Function:    getTravelTime
//
// Description: Calculates the days of travel for a letter. If rushed and days
//              are more than one, minus one day of travel.
//
// Parameters:  None.
//
// Returned:    Travel time of letter.
//*****************************************************************************

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

//*****************************************************************************
// Function:    isRushed
//
// Description: Calls Parcel's isRushed to return if letter has rush or not.
//
// Parameters:  None.
//
// Returned:    True if rushed, false otherwise.
//*****************************************************************************

bool Letter::isRushed () const {

  return Parcel::isRushed ();

}

//*****************************************************************************
// Function:    isInsured
//
// Description: Calls Parcel's isInsured to return if letter has insurance or 
//              not.
//
// Parameters:  None.
//
// Returned:    True if insured, false otherwise.
//*****************************************************************************

bool Letter::isInsured () const {

  return Parcel::isInsured ();

}

//*****************************************************************************
// Function:    addRush
//
// Description: Calls Parcel's addRush to have letter's rush equal true.
//
// Parameters:  None.
//
// Returned:    Letter's rush to true.
//*****************************************************************************

Parcel& Letter::addRush () {

  &Parcel::addRush ();

  return *this;

}

//*****************************************************************************
// Function:    addInsurance
//
// Description: Calls Parcel's addInsurance to have letter's insurance equal 
//              true.
//
// Parameters:  None.
//
// Returned:    Letter's insurance to true.
//*****************************************************************************

Parcel& Letter::addInsurance () {

  &Parcel::addInsurance ();

  return *this;

}

//*****************************************************************************
// Function:    read
//
// Description: Read in to initialize letter. Uses Parcel's read.
//
// Parameters:  rcIn - Where to read from.
//
// Returned:    False if not read correctly, true otherwise.
//*****************************************************************************

bool Letter::read (istream& rcIn) {

  bool bIsRead = true;

  if (!(Parcel::read (rcIn))) {

    bIsRead = false;

  }

  return bIsRead;

}

//*****************************************************************************
// Function:    print
//
// Description: Print out letter in a specific format. Uses Parcel's print.
//
// Parameters:  rcOut - Where to print to.
//
// Returned:    None.
//*****************************************************************************

void Letter::print (ostream& rcOut) const {

  Parcel::print (rcOut);

}