#include "header.h"
#include <stdio.h>

float getMileCost(int days)
{
    float miles;
    printf("How many miles did you drive per day? ");
    scanf("%f", &miles);
    return days*miles*0.27;
}

float getParkingCost(int days)
{
    float fees;
    printf("How much was the parking fee per day? ");
    scanf("%f", &fees);
    return days*fees;
}

float getTaxiCost(int days)
{
    float fees;
    printf("How much was the tax fee per day? ");
    scanf("%f", &fees);
    return days*fees;
}

float getConferenceCost(int days)
{
    float fees;
    printf("How much was the conference fee per day? ");
    scanf("%f", &fees);
    return days*fees;
}

float getHotelCost(int days)
{
    float fees;
    printf("How much was the hotel per day? ");
    scanf("%f", &fees);
    return days*fees;
}
