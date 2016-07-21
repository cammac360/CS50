#include <stdio.h>
#include <cs50.h>

int main(void){
    int height;
    do{
        printf("height: ");
        height = GetInt();
        if(height == 0){
        return height;
    }
    }
    
    while(height < 1 || height > 23);
    for (int y = 0; y < height; y++){
        for(int z = height-y-1; z > 0 ; z--){
            printf(" ");
        }
        for(int x = y + 2; x > 0; x--){
            printf("#");
        }
        printf("\n");
    }
}