#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    int pennies=0;
    int nickles=0;
    int dimes=0;
    int quarters=0;
    
    float Nchange;
    do{
        printf("How much change?: ");
        Nchange = GetFloat();
    }
    while(Nchange < 0);
    int change = round(100*Nchange);
  
    do{
        if((change - 25) >= 0){
            quarters++;
            change = change - 25;
        }
    }
    while((change - 25) >= 0);
    
    do{
        if( (change - 10) >= 0){
            dimes++;
            change = change - 10;
        }
    }
    while((change - 10) >= 0);
    
    do{
        if( (change - 5) >= 0){
            nickles++;
            change = change - 05;
        }
    }
    while((change - 5) >= 0);
    
    do{
        if((change - 1) >= 0){
            pennies++;
            change = change - 1;
        }
    }
    while((change - 1) >= 0);
    
    printf("%i\n",quarters + dimes + nickles + pennies);
}