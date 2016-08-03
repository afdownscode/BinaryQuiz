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


void displayBinary(int n, int bit_arr[], int num_target);
void createDistinctRands(int size, int arr[], int range, int zeroflag);
double calcScore(double t, int answer);


int main(){
        const int bin_digits = 4;   // the number on binary digits
        int bin_array[bin_digits];  // to hold the binary digits
        const int num_choices = 9;  // the number of random ints
        int choices[num_choices];   // to hold the random numbers
        const int range = 15;       // the range of numbers for binary conv
        const int nozeros = 0;
        const int withzeros = 1;
        
        createDistinctRands(num_choices, choices, range, nozeros);
        printf("The Binary Quiz\n");
        printf("Pick 3 numbers to find given sum...\n");
        for(int i = 0; i < num_choices; i++){
            printf("Choice %d\t",i);
            displayBinary(bin_digits, bin_array, choices[i]);
            printf("\n");
        }
        int num_select = 3; // the number of items to sum
        int adders[num_select];  // to hold the indexes to add for sum
        createDistinctRands(num_select, adders, num_choices, withzeros);
        //printf("The indexes:\n");
        //for(int i = 0; i < num_select; i++){
        //    printf("adders %d\t\t%d\n",i, adders[i]);
        //} 
        int sum = choices[adders[0]] + 
                  choices[adders[1]] + 
                  choices[adders[2]]; 
        printf("The sum to find = %d\n", sum);
        int num_picks = 3;
        int picks[num_picks];
        int pick_sum = 0;
        int correct;

        double elapsed_time;
        time_t start;
        time(&start); 
        for(int i = 0; i < num_picks; i++){
            printf("Select Choice %d: ", i + 1);
            scanf("%d", picks + i);
            pick_sum += choices[picks[i]];
        }
        time_t end;
        time(&end);
        if(sum == pick_sum){
                printf("Winner! Winner! Chicken Dinner!!\n");
                correct = 1;
        }
        else{
                printf("You need some more practice...\n");
                correct = 0;
        }
        
        elapsed_time = difftime(end, start);
        printf("It took %04.1f seconds\n", elapsed_time);
        printf("Your score is %04.1f\n", calcScore(elapsed_time, correct));
        getchar();
 
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

        
void displayBinary(int n, int bit_arr[], int num_target){
        // num_digits is the bits of binary to display
        // num_target is number to be converted
        // need to zero out the bin array
        for(int i = 0; i < n; i++){
                bit_arr[i] = 0;
        }
        int i = n - 1;
        while(num_target > 0){
            bit_arr[i] = num_target%2;
            num_target /= 2;
            i--;
        }
        for(i = 0; i < n; i++){
            printf("%d", bit_arr[i]);
        }
}

double calcScore(double t, int answer){
        double score;
        if(!answer)
                return 0;

        if(t < 5){
            score = (60 - t) * 1.5;
        }
        else if(t < 15){
            score = (60 - t) * 1.25;
        }
        else if(t < 30){
            score = (60 - t) * 1.0;
        }
        else if(t < 60){
            score = (60 - t) * .75;
        }
        else
                score = 0.0;

        return score;
}
