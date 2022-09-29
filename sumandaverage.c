#include <stdio.h>

// Megan Steinmasel
// September 2022
// Program that passes by reference


void ref(double *first, double *second, double *third){
    
    double sum;
    sum = *first + *second + *third;
    
    printf("The sum is: %.2lf\n", sum);

    double ave;
    ave = sum/3;

    printf("The average is: %.2lf\n", ave);

    return;
}



int main(){
    
    double first;
    double *p1;
    printf("1. Enter a decimal: ");
    scanf("%lf", &first);
    p1 = &first;


    double second;
    double *p2;
    printf("2. Enter a decimal: ");
    scanf("%lf", &second);
    p2 = &second;

    double third;
    double *p3;
    printf("3. Enter a decimal: ");
    scanf("%lf", &third);
    p3 = &third;

    ref(p1, p2, p3);

    return(0);
}
