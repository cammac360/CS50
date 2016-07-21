#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void){
    string name = GetString();
    printf("%c",toupper(name[0]));
    for(int x = 0; x < strlen(name); x++){
        if(name[x]==' '){
            printf("%c", toupper(name[x+1]));
        }
    }
    printf("\n");
}