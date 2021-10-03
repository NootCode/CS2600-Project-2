#include <stdio.h>
#include "header.h"

getFoodCost(int days){

    float totalMealCost;
    float breakfastFee;
    float lunchFee;
    float dinnerFee;


    printf("Enter the total amount that you spent on breakfast during your %d days stay.\n", days);
    scanf("%f", &breakfastFee);
    printf("Enter the total amount that you spent on lunch during your %d days stay.\n", days);
    scanf("%f", &lunchFee);
    printf("Enter the total amount that you spent on dinner during your %d days stay.\n", days);
    scanf("%f", &dinnerFee);

    totalMealCost = breakfastFee + lunchFee + dinnerFee;
    //printf("Your total meal costs during your stay is: $%.2f", totalMealCost);

    return totalMealCost;

}

float getFoodAllow(int days, int depTime, int arrTime){
    float sum = 37 * (days - 2);
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