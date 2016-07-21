#include <stdio.h>
#include <cs50.h>

int main(void){
    printf("minutes: ");
    int min = GetInt();
    int gal = min * 1.5;
    int ounce = gal/128; 
    printf("bottles: %i", min * 12);
}