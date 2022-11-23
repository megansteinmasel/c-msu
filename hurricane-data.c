#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Author: Megan Steinmasel
// October 2022
// Program reads in hurricane data and writes a sorted list out to a file

void selectionSort(char*strs[], int size, FILE *fileout){
    // sorts strs array
    int i, j;
    char temp[100];
    for(i = 0; i < size-1; i++){
        for(j= i+1; j < size; j++){
            if(strcmp(strs[i], strs[j]) > 0){
                // swapping process
                strcpy(temp, strs[i]);
                strcpy(strs[i], strs[j]);
                strcpy(strs[j], temp);
            }
        }
    }
    
    // writes output to fileout.txt
    char sentence[] = "\nHurricanes in Florida with category and date\n";
    fprintf(fileout, "%s", sentence);

    char *name, *num, *date;

    for(int i = 0; i < 37; i++){
        // gets the hurricane name & writes to file
        name = strtok(strs[i], ",");
        fprintf(fileout, " %-8s", name);
        
        // gets hurricane category
        num = strtok(NULL, ",");

        // extracts the category number & writes to file
        while(*num){
            if(isdigit(*num)){
                long l = strtol(num, &num, 10);
                fprintf(fileout, "%4ld", l);
            }
            else{
                num++;
            }
        }
        
        // gets the hurricane date & writes to file 
        date = strtok(NULL, "\0");
        fprintf(fileout, "    %8s", date);
    }
}

void read(){

    // opens hurricane data input file
    FILE *fptr = fopen("/public/lab4/hurricanes.csv", "r");
    
    // opens an output file
    FILE *fout = fopen("fileout.txt", "w");

    // checks if input file opened correctly 
    if(!fptr){
        printf("Error opening file.");
        exit(-1);
    }
    
    // gets each line of input file and puts it into the char array 
    char *line[100];
    for(int i = 0; i < 37; i++){
        // allocate memory
        line[i] = malloc(sizeof(char) * 100);
        fgets(line[i], 100, fptr);
    }
    
    // calls selectionSort with char array, size, and output file
    selectionSort(line, 37, fout);

    // closes input file
    fclose(fptr);

    return;
}


int main(void){
    read();
    return(0);
}
