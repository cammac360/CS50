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
    if(key > 26){
    key = key%26;
    }
    string text = GetString();
    string final = text;
    for(int x = 0, len = strlen(text); x < len; x++){
        char en;
        int tmp = (int)text[x];
        if(isalpha(text[x])){
            if(isupper(text[x])){
                
                if(tmp+key <= 90){
                    en = (char)(tmp+key);
                }
                else{
                    en = (char) (tmp+key) - 26 ; 
                }
            
            }
            else{
                if(tmp+key <= 122){
                 en = (char) (tmp+key);
                }
                else{
                    en = (char) (tmp+key) - 26; 
                }
            }   
        }
        else{
            en = (char) tmp;
        }
        final[x] = en;
        
    }
    printf("%s\n", final);
    return 0;
}