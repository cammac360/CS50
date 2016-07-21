#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

char Encrypt(char letter, char change){
    char l = letter;
    char c = change;
    if(isupper(c)){
      c = c - 'A';  
    }
    else{
        c = c - 'a';
    }
    if(isupper(l)){
        if(l+c <= 'Z'){
            return l+c;
        }
        else{
            return ((l+c)%'Z')+'A' -1; 
        }
    }
    else{
        if(l + c <= 'z'){
            return l+c;
        }
        else{
            return ((l+c)%'z')+'a'-1; 
        }
    }

}

int main(int argc, string argv[]){
    string key = argv[1];
    if(argc != 2){
        printf("YOU DIDNT ENTER A KEY!!!\n");
        return 1;
    }
    for(int x = 0, y = strlen(key);x < y ; x++){
        if(isdigit(key[x])){
            printf("YOU DIDNT ENTER A FULL TEXT KEY GET RID OF INT!!!\n");
            return 1;
        }
    }
    int y = 0;
    string text = GetString();
    for(int x = 0, textLen = strlen(text); x < textLen; x++){
        char en;
        if( y >= strlen(key)){
            y=0;
        }
        if(isalpha(text[x])){
            en = Encrypt(text[x], key[y]);
            y++;
        }
        if(!isalpha(text[x])){
            en = text[x];
        }
        printf("%c", en);
    }
    printf("\n");
    return 0;
}