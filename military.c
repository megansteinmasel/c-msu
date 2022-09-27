#include <stdio.h>


// Author: Megan Steinmasel
// August 2022
// Program calculates military discount and sales tax


int userCost(void){
    // gets cost from user and returns it
    int cost;
    printf("Cost of Purchase \t\t $");
    scanf("%d", &cost);
    return cost;
}

int main(void){
    // gets cost from userCost 
    int cost;
    cost = userCost();

    // military discount - yes or no?
    char answer;
    printf("In military (y or n) \t\t ");
    scanf(" %c", &answer);
    
    // yes - military discount
    if(answer == 'y'|| answer == 'Y' ){

        if(cost >= 200){

            // finds the 20% military discount
            double militaryDiscount;
            militaryDiscount = cost * .20;
            printf("Military discount (20%%) \t $%.2lf \n", militaryDiscount);

            // finds the discounted total
            double discountedTotal;
            discountedTotal = cost - militaryDiscount;
            printf("Discounted total \t\t $%.2lf \n", discountedTotal);

            // finds sales tax
            double salesTax;
            salesTax = discountedTotal * .06;
            printf("Sales tax (6%%) \t\t\t $%.2lf \n", salesTax);

            // finds the total
            double total;
            total = discountedTotal + salesTax;
            printf("Total \t\t\t\t $%.2lf \n", total);
        }
        else{
            
            // finds the 15% military discount
            double militaryDiscount1;
            militaryDiscount1 = cost * .15;
            printf("Military discount (15%%) \t $%.2lf \n", militaryDiscount1);

            // finds the discounted total
            double discountedTotal1;
            discountedTotal1 = cost - militaryDiscount1;
            printf("Discounted total \t\t $%.2lf \n", discountedTotal1);
        
            // finds sales tax
            double salesTax1;
            salesTax1 = discountedTotal1 * .06;
            printf("Sales tax (6%%) \t\t\t $%.2lf \n", salesTax1);

            // finds the total
            double total1;
            total1 = discountedTotal1 + salesTax1;
            printf("Total \t\t\t\t $%.2lf \n", total1);
        }
    }
    // no - military discount
    else if(answer == 'n' || answer == 'N'){

        // finds sales tax
        double salesTax2;
        salesTax2 = cost * .06;
        printf("Sales tax (6%%) \t\t\t $%.2lf \n", salesTax2);

        // finds the total
        double total2;
        total2 = cost + salesTax2;
        printf("Total \t\t\t\t $%.2lf \n", total2);
    }
    // error for bad input
    else{
        printf("Error: bad input \n");
    }

    return(0);

    }
