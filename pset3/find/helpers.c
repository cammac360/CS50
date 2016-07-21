/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if(n < 0){
        return false;
    }
    for(int i = 0; i < n; i++){
        if(values[i] == value){
            return true;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int swaps = 0;
    do{
        swaps = 0;
        for(int i = 0; i < n - 1; i ++){
            if(values[i] > values[i+1]){
                int small = values[i];
                int big = values[i+1];
                values[i] = big;
                values[i+1] = small;
                swaps ++;
            }
        }
    }
    while(swaps != 0);
}