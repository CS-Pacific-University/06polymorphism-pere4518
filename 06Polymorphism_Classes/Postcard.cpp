//*****************************************************************************
// File name:  Postcard.cpp
// Author:     Ali Perez-Suiter
// Date:       4/20/21
// Class:      CS250
// Assignment: Polymorphisim
// Purpose:    Implements constructors & funcitons of class Postcard.
//*****************************************************************************

#include "Postcard.h"

//*****************************************************************************
// Constructor: Postcard
//
// Description: Initializes data members to default values. Use's Parcel's
//              constructor first.
//
// Parameters:  None.
//
// Returned:    None.
//*****************************************************************************

Postcard::Postcard () : Parcel() {

  mMessage = "   ";

}

//*****************************************************************************
// Constructor: Postcard
//
// Description: Initializes data members to specific values. Uses Parcel's 
//              constructor first.
//
// Parameters:  trackingNum - Tracking number of postcard.
//              to          - Who to send postcard to.
//              from        - Who sent postcard.
//              weight      - Weight of postcard (assume always in ounces).
//              distance    - Miles for postcard to travel.
//              rushed      - Status of postcard's rush.
//              insured     - Status of postcard's insurance.
//              message     - Message on postcard
//
// Returned:    None.
//*****************************************************************************

Postcard::Postcard (int trackingNum, string to, string from, int weight, int 
                    distance, bool rushed, bool insured, string message) : 
                    Parcel (trackingNum, to, from, weight, distance, rushed, 
                            insured) {

  mMessage = message;

}

//*****************************************************************************
// Function:    getWeight
//
// Description: Calls Parcel's getWeight to return weight of the postcard
//              parcel.
//
// Parameters:  None.
//
// Returned:    Weight of postcard parcel.
//*****************************************************************************

int Postcard::getWeight () const {

  return Parcel::getWeight ();

}

//*****************************************************************************
// Function:    getDistance
//
// Description: Calls Parcel's getDistance to return distance of the postcard 
//              parcel.
//
// Parameters:  None.
//
// Returned:    Distance of postcard parcel.
//*****************************************************************************

int Postcard::getDistance () const {

  return Parcel::getDistance ();

}

//*****************************************************************************
// Function:    getRush
//
// Description: Calculates the cost of a postcard's rush.
//
// Parameters:  cost - Current cost of postcard.
//
// Returned:    Rush rate of postcard to add to cost.
//*****************************************************************************

double Postcard::getRush (double cost) const {

  double rush;

  rush = RUSH_POSTCARD;

  return rush;

}

//*****************************************************************************
// Function:    getInsurance
//
// Description: Calculates the cost of a postcards's insurance.
//
// Parameters:  cost - Current cost of postcard.
//
// Returned:    Insurance rate of postcard to add to cost.
//*****************************************************************************

double Postcard::getInsurance (double cost) const {

  double insurance;

  insurance = INSURANCE_POSTCARD;

  return insurance;

}

//*****************************************************************************
// Function:    getCost
//
// Description: Calculates the cost of a postcard.
//
// Parameters:  None.
//
// Returned:    Cost of postcard.
//*****************************************************************************

double Postcard::getCost () const {

  double cost = COST_POSTCARD;

  return cost;
}

//*****************************************************************************
// Function:    getTravelTime
//
// Description: Calculates the days of travel for a postcard. If rushed and 
//              days are more than one, minus one day of travel.
//
// Parameters:  None.
//
// Returned:    Travel time of postcard.
//*****************************************************************************

int Postcard::getTravelTime () const {

  int minimumTravel = 1;
  int travelTime = minimumTravel;
  int distance = getDistance ();

  travelTime = TRAVEL_PER_DAY_POSTCARD % distance;

  if (isRushed () && travelTime > minimumTravel) {

    travelTime -= 1;

  }


  return travelTime;
}

//*****************************************************************************
// Function:    isRushed
//
// Description: Calls Parcel's isRushed to return if postcard has rush or not.
//
// Parameters:  None.
//
// Returned:    True if rushed, false otherwise.
//*****************************************************************************

bool Postcard::isRushed () const {

  return Parcel::isRushed ();

}

//*****************************************************************************
// Function:    isInsured
//
// Description: Calls Parcel's isInsured to return if postcard has insurance or 
//              not.
//
// Parameters:  None.
//
// Returned:    True if insured, false otherwise.
//*****************************************************************************

bool Postcard::isInsured () const {

  return Parcel::isInsured ();

}

//*****************************************************************************
// Function:    addRush
//
// Description: Calls Parcel's addRush to have postcard's rush equal true.
//
// Parameters:  None.
//
// Returned:    Postcard's rush to true.
//*****************************************************************************

Parcel& Postcard::addRush () {

  &Parcel::addRush ();

  return *this;

}


//*****************************************************************************
// Function:    addInsurance
//
// Description: Calls Parcel's addInsurance to have postcard's insurance equal 
//              true.
//
// Parameters:  None.
//
// Returned:    Postcard's insurance to true.
//*****************************************************************************

Parcel& Postcard::addInsurance () {

  &Parcel::addInsurance ();

  return *this;

}

//*****************************************************************************
// Function:    read
//
// Description: Read in to initialize postcard. Uses Parcel's read first.
//
// Parameters:  rcIn - Where to read from.
//
// Returned:    False if not read correctly, true otherwise.
//*****************************************************************************

bool Postcard::read (istream& rcIn) {

  bool bIsRead = true;

  if (!(Parcel::read (rcIn))) {

    bIsRead = false;

  }

  if (!(rcIn >> mMessage)) {

    bIsRead = false;

  }

  return bIsRead;

}

//*****************************************************************************
// Function:    print
//
// Description: Print out postcard in a specific format. Uses Parcel's print
//              first.
//
// Parameters:  rcOut - Where to print to.
//
// Returned:    None.
//*****************************************************************************

void Postcard::print (ostream& rcOut) const {

  Parcel::print (rcOut);

  rcOut << mMessage << "\t";

}