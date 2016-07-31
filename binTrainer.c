/*
 * a program to quiz on binary numbers
 * generate 9 numbers between 1 - 15
 * select 3 of those and sum
 * display all 9 with target of sum
 * select the correct 3 to match sum
 */

#include <stdio.h>
#include <stdlib.h>  //for random generation
#include <time.h>    //time value for seed

void createDistinctRands(int size, int arr[], int range, int zeroflag);


int main(){
        int num_choices = 9; // the number of random ints
        int choices[num_choices];
        createDistinctRands(num_choices, choices, 15, 0);
        printf("The randoms:\n");
        for(int i = 0; i < num_choices; i++){
            printf("Choices %d\t%d\n",i, choices[i]);
        }
        int num_select = 3; // the number of items to sum
        int adders[num_select];  // to hold the indexes to add for sum
        createDistinctRands(num_select, adders, num_choices, 1);
        printf("The indexes:\n");
        for(int i = 0; i < num_select; i++){
            printf("adders %d\t\t%d\n",i, adders[i]);
        } 
        int sum = choices[adders[0]] + 
                  choices[adders[1]] + 
                  choices[adders[2]]; 
        printf("The sum of the indexes = %d\n", sum);
        return(0);
}

void createDistinctRands(int size, int arr[], int range, int zeroflag){
        // this function populates an array with random integers
        // range is random range... zeroflag is if 0 will be included

        time_t now;     // a special type for the seed
        now = time(NULL);   // returns the num of seconds since UNIX birth
        srand((unsigned)now); // seed for the rand() function
        // you could also use srand(now(NULL)); in one pass
        rand();     // get it rocking
        int count = 0;
        while(count < size){
            int candidate;
            if(zeroflag){
                candidate = rand() % range;
            }
            else{
                candidate = rand() % range + 1;
            }
            arr[count] = candidate;
            int proceed = 1;
            for(int i = 0; i < count; i++){
                if(arr[i] == candidate){
                    proceed = 0;
                }    
            }
            if(!proceed)
                    continue;
            count++;
        }
}

        
