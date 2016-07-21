#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]){
    string k = argv[1];
    int key;
    if(argc != 2){
        printf("YOU DIDNT ENTER A KEY!!!\n");
        return 1;
    }
    key = atoi(k);
    if(key > 26 ){
        key = key%26;
    }
    string text = GetString();
    for(int x = 0, len = strlen(text); x < len; x++){
        char en;
        if(isalpha(text[x])){
            if(isupper(text[x])){
                if(text[x]+key <= 'Z'){
                    en = text[x]+key;
                }
                else{
                    en = ((text[x]+key)%'Z')+'A'; 
                }
            
            }
            else{
                if(text[x]+key <= 'z'){
                 en = text[x]+key;
                }
                else{
                    en = ((text[x]+key)%'z')+'a'-1; 
                }
            }   
        }
        else{
            en = text[x];
        }
        printf("%c", en);
    }
}