#include <stdio.h>
#include "header.h"

getFoodCost(int totalDays, int departureTime, int arrivalTime)
{
    //variables
    float totalMealCOst;
    float breakfastFee;
    float lunchFee;
    float dinnerFee;

    /*Allowable meal prices 
    breakfast = 9.00
    lunch= 12.00
    dinner= 16.00*/
    float breakfast = 9.00;
    float lunch = 12.00;
    float dinner = 16.00;

    for(int days =1; days <= totalDays; days++)
    {
        //printf("This is day %d\n", days);
        
        //For the first day 
        //breakfast is allowed if the departure is before 7am (0700).
        //lunch is allowed if the time of departure is 12pm (1200)
        //dinner is allowed if the departure is 6pm (1800)
        while(days < 2 && departureTime > 0000 && departureTime <= 0700){
            printf("Enter the cost of breakfast on day %d : \n", days);
            scanf("%f", &breakfastFee);
            printf("Enter the cost of lunch on day %d : \n", days);
            scanf("%f", &lunchFee);
            printf("Enter the cost of dinner on day %d : \n", days);
            scanf("%f", &dinnerFee);   
            totalMealCOst = totalMealCOst + breakfastFee + lunchFee + dinnerFee;
            days++;       
        }
        while(days <2 && departureTime > 0701 && departureTime <= 1200){

            printf("Enter the cost of lunch on day %d : \n", days);
            scanf("%f", &lunchFee);
            printf("Enter the cost of dinner on day %d : \n", days);
            scanf("%f", &dinnerFee); 
            totalMealCOst = totalMealCOst + lunchFee + dinnerFee;
            days++;
        }

        while(days <2 && departureTime > 1201 && departureTime <= 1800){

            printf("Enter the cost of dinner on day %d : \n", days);
            scanf("%f", &dinnerFee); 
             totalMealCOst = totalMealCOst + dinnerFee;
            days++;
        }
        while(days > 1 && days < totalDays){
            printf("Enter the cost of breakfast on day %d : \n", days);
            scanf("%f", &breakfastFee);
            printf("Enter the cost of lunch on day %d : \n", days);
            scanf("%f", &lunchFee);
            printf("Enter the cost of dinner on day %d : \n", days);
            scanf("%f", &dinnerFee);  
            totalMealCOst = totalMealCOst + breakfastFee + lunchFee + dinnerFee;
            days++;
        }

        /*On the last day of the trip, breakfast is allowed if the time of arrival is after 8 a.m. 
        Lunch is allowed if the time of arrival is after 1 p.m. 
        Dinner is allowed on the last day if the time of arrival is after 7 p.m. */
        while(days == totalDays && arrivalTime > 800 && arrivalTime <= 1300){
            printf("Enter the cost of breakfast on day %d : \n", days);
            scanf("%f", &breakfastFee);
            totalMealCOst = totalMealCOst + breakfastFee;
            days++;
        }
        while(days == totalDays && arrivalTime > 1301 && arrivalTime <= 1900){
            printf("Enter the cost of breakfast on day %d : \n", days);
            scanf("%f", &breakfastFee);
            printf("Enter the cost of lunch on day %d : \n", days);
            scanf("%f", &lunchFee);
            totalMealCOst = totalMealCOst + breakfastFee + lunchFee;
            days++;
        }

        while(days == totalDays && arrivalTime > 1901){
            printf("Enter the cost of breakfast on day %d : \n", days);
            scanf("%f", &breakfastFee);
            printf("Enter the cost of lunch on day %d : \n", days);
            scanf("%f", &lunchFee);
            printf("Enter the cost of dinner on day %d : \n", days);
            scanf("%f", &dinnerFee); 
            totalMealCOst = totalMealCOst + breakfastFee + lunchFee + dinnerFee;
            days++; 
        }
        
    }

    //printf("Your total expenses come up to $%.2f\n", totalExpenses);

    return totalMealCOst;
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