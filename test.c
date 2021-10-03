#include <stdio.h>
#include "header.h"

float getFoodCost(int days, int depTime, int arrTime){

    float totalMealCost;
    float breakfastFee;
    float lunchFee;
    float dinnerFee;

    printf("How much was the total amount for breakfast per day? ");
    scanf("%f", &breakfastFee);

    printf("How much was the total amount for lunch per day? ");
    scanf("%f", &lunchFee);

    printf("How much was the total amount for dinner per day? ");
    scanf("%f", &dinnerFee);

    if(days > 2)
        totalMealCost = breakfastFee * (days-2) + lunchFee*(days-2)+ dinnerFee*(days-2);
    if(depTime < 700)
        totalMealCost += breakfastFee;
    if(depTime < 1200)
        totalMealCost += lunchFee;
    if(depTime < 1800)
        totalMealCost += dinnerFee;

    if(arrTime > 800)
        totalMealCost += breakfastFee;
    if(arrTime > 1300)
        totalMealCost += lunchFee;
    if(arrTime > 1900)
        totalMealCost += dinnerFee;

    //printf("Your total meal costs during your stay is: $%.2f", totalMealCost);

    return totalMealCost;

}

float getFoodAllow(int days, int depTime, int arrTime){
    float sum;
    if(days > 2)
        sum = 37 * (days - 2);
    if(depTime < 700)
        sum += 9;
    if(depTime < 1200)
        sum += 12;
    if(depTime < 1800)
        sum += 16;

    if(arrTime > 800)
        sum += 9;
    if(arrTime > 1300)
        sum += 12;
    if(arrTime > 1900)
        sum += 16;

    return sum;
}

float getTotalAllow(int days){
    float sum = 0;
    sum += days * 6;
    sum += days * 10;
    sum += days * 90;

    return sum;
}