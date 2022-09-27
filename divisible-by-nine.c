#include <stdio.h>
#include <math.h>


// Megan Steinmasel
// September 2022
// Program splits integer into its digits, and sees if that number is divisible by 9


void funct(int userNum){
    int startingNum = userNum;
    int i = 0;
    int numArr[50];

    // takes "userNum" and peals off each digit of the integer
    while(userNum != 0){
        // gets the last digit of userNum and puts it in the numArr array
        numArr[i] = userNum % 10;
        i++;        
        userNum = userNum / 10;
    }

    // prints "numArr" backwards and adds up the digits
    int added = 0;
    for(int j = i -1; j > -1; j--){
        printf("%d", numArr[j]);
        added += numArr[j];
        if(numArr[j-1]){
            printf(" + ");
        }
        else{
            printf(" = ");
        }
    }
    printf("%d", added);
    printf("\n");
    
    // checks if "added" is divisible by 9
    if (added % 9 == 0){
        printf("Since %d is divisible by 9, %d is divisible by 9.\n", added, startingNum);
    }
    else{
        printf("Since %d is not divisible by 9, %d is not divisible by 9.\n", added, startingNum);
    }
}

int main(void){
    // loops on input until user inputs 0
    int num;
    while(num != 0){
        printf("Enter number to check (0 to end): ");
        scanf("%d", &num);
        if (num == 0){
            break;
        }
        else{
            funct(num);
        }
    }
    return(0);
}
