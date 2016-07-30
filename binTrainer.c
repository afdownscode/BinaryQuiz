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

int main(){
        time_t now;     // a special type for the seed
        now = time(NULL);   // returns the num of seconds since UNIX birth
        srand((unsigned)now); // seed for the rand() function
        // you could also use srand(now(NULL)); in one pass
        rand();     // get it rocking
        int count = 0;
        int max_terms = 6;
        int nums[max_terms];
        while(count < max_terms){
            nums[count] = rand() % 15 + 1;
            //printf("%d\n", rand() % 15 + 1);
            count++;
        }
        for(int i = 0; i < max_terms; i++){
            printf("%d\n", nums[i]);
        }
        return(0);
}
