#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    int pennies=0;
    int nickels=0;
    int dimes=0;
    int quarters=0;
    printf("How much change?: ");
    pennies = GetInt();
    for(int i = 1; i < 5; i++){
        if(pennies > (25*i)){
            quarters = i;
            pennies = pennies -(quarters*25);
        }
    }
    for(int i = 1; i > 4; i++){
        if(pennies > (10*i)){
            dimes = i;
            pennies = pennies - (dimes*10);
        }
    }
    if(pennies > 5){
        nickels =1;
        pennies = pennies - (nickels*5);
        
    }
    printf("%i\n",quarters + dimes + nickels + pennies);
}