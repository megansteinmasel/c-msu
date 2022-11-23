#include <stdio.h>

// Author: Megan Steinmasel
// September 2022
// Program reads in a text file from the class server and computes exam grades

int charOperations(FILE* fptr, char answers[], int numofq){
 // reads in the first line of the file

    int n;
    char c;

    // gets the number of questions - numofq
    for(int i = 0; i < 1; i++){
        fscanf(fptr, "%d", &n);
        numofq = n;

        // gets the correct answers - answers[]
        for(int j = 0; j < numofq; j++){
            fscanf(fptr, " %c", &c);
            answers[j] = c;
        }
    }

// output
    printf("Question\t");
    for(int m = 1; m < numofq+1; m++){
        printf(" %d", m);
    }printf("\n");

    printf("Answer\t\t");
    for(int x = 0; x < numofq; x++){
        printf(" %c", answers[x]);
    }printf("\n");

    printf("ID\t Grade(%%)\n");


// grades each student and finds the missed questions
    int idNum;
    char ch;
    int missed[10] = {};

    while(fscanf(fptr, "%d ", &idNum) == 1){

        // prints ID numbers
        printf("%d\t", idNum);
        int numwrong = 0;

        // iterates through the answers of each student
        for(int t = 0; t < numofq; t++){
            fscanf(fptr,"%c", &ch);

            // checks if answers are correct
            if(ch != answers[t]){
                numwrong += 1;
                missed[t] += 1;
            }
        }

        // finds the grade of each student
        double div = (numofq - numwrong);
        double ans = (div / numofq);
        double grade = (ans * 100);
        printf("%.2lf\n", grade);
    }


// output
    printf("Question\t");
    for(int m = 1; m < numofq + 1; m++){
        printf(" %d", m);
    }printf("\n");

    printf("Missed by\t");
    for(int s = 0; s < numofq; s++){
        printf(" %d", missed[s]);
    }printf("\n");

    return(0);
}


int read(){
    // reading in file
    FILE* fptr = fopen("/public/lab3/exam.txt", "r");

    // checks if file is null
    if(fptr == NULL){
        printf("Can't find file\n");
        return(0);
    }

    // calls charOperations with parameters
    int q = 0;
    char answers[10];
    charOperations(fptr, answers, q);

    // closes the file
    fclose(fptr);
    return(0);
}

int main(){
    read();
    return(0);
}
