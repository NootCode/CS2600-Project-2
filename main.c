#include <stdio.h>
#include "header.h"

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

int main()
{  
    int tester = 1;

    int total_days;
    int departure_time;
    int arrival_time;
    float cost_roundTrip;
    float cost_carRentals;
    float cost_milesDriven = 0;
    float fee_parking;
    float fee_taxi;
    float fee_reg;
    float hotelExpenses;
    float meal;

    float totalExpenses;
    float totalAllow;
    float reimburse;
    float totalSaved;

    printf("Enter number of days: ");
    scanf("%d", &total_days);

    int wrong = 1;
    while(wrong == 1){
        printf("Enter departure time in military format (0000-2359): "); 
        scanf("%d", &departure_time);

        printf("Enter arrival time in military format (0000-2359): ");
        scanf("%d", &arrival_time);

        if(departure_time > 2359 || departure_time < 0000 || arrival_time > 2359 || arrival_time < 0000)
            printf("\nENTER TIME IN THE CORRECT FORMAT\n\n");
        else
            wrong = 0;
        //ENSURES TIME IS IN THE CORRECT FORMAT. IF NOT LOOPS AGAIN
    }

    printf("Enter price of airfare: ");
    scanf("%f", &cost_roundTrip);

    printf("Enter price of car rentals (if any): ");
    scanf("%f", &cost_carRentals);

    if(cost_carRentals == 0){ //if no car rentals check the miles driven and get that value;
        cost_milesDriven = getMileCost(total_days);
    }

    //GET PRICE OF ALL FEES
    fee_parking = getParkingCost(1);
    fee_taxi = getTaxiCost(total_days);
    fee_reg = getConferenceCost(total_days);
    hotelExpenses = getHotelCost(total_days);
    //meal = getFoodCost(total_days, departure_time, arrival_time);
    meal = 0;

    if(tester == 1){
        printf("\n");
        printf("Num days: %d\n", total_days);
        printf("Departure time: %d\n", departure_time);
        printf("Arrival time: %d\n", arrival_time);
        printf("Airfare price: %.2f\n", cost_roundTrip);
        printf("Car rental price: %.2f\n", cost_carRentals);
        printf("private car price: %.2f\n", cost_milesDriven);
        printf("Parking Fees: %.2f\n", fee_parking);
        printf("Taxi Fees: %.2f\n", fee_taxi);
        printf("Conference Fees: %.2f\n", fee_reg);
        printf("Hotel Fees: %.2f\n\n\n", hotelExpenses);

    }
    
    //TOTAL ALLOWANCE FOR x DAYS
    totalAllow = getTotalAllow(total_days) + getFoodAllow(total_days, departure_time, arrival_time);

    totalExpenses = fee_parking + fee_reg + fee_taxi + hotelExpenses + meal + cost_carRentals + 
        cost_milesDriven + cost_roundTrip;

    //CALCULATE TOTAL SAVED IF ALLOWED > EXPENSE
    if(totalAllow > totalExpenses){
        totalSaved = totalAllow - totalExpenses;
    }

    //CALCULATE REIMBURSE OTHERWISE
    if(totalAllow < totalExpenses)
        reimburse = totalAllow;
    else
        reimburse = totalExpenses;

    //PRINT VALUES
    printf("The total expenses for the %d day trip was: %.2f\n", total_days, totalExpenses);
    printf("The total allowance for a %d day trip is: %.2f\n", total_days, totalAllow);
    printf("The reimbursement for the %d day trip is: %.2f\n\n\n", total_days, reimburse);
    printf("The total saved for the %d day trip was: %.2f\n", total_days, totalSaved);
    return 0;
}
