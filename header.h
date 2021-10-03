#ifndef HEADER_H
#define HEADER_H

// functions for miles, parking, taxi, conference, and hotel
float getMileCost(int days);
float getParkingCost(int days);
float getTaxiCost(int days);
float getConferenceCost(int days);
float getHotelCost(int days);

// functions for food
float getFoodCost(int days, int depTime, int arrTime);
float getFoodAllow(int days, int depTime, int arrTime);
float getTotalAllow(int days);

#endif