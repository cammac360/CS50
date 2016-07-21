/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"



node* root;

unsigned int dictionarySize = 0;
/**
 * Returns true if word is in dictionary else false.
 */

bool check(const char* word)
{
    //char word = &checkword;
    node* current = root;
    int nextLetter = 0;
    for(int i = 0;word[i] != '\0'; i++){
        //check to see if this is a letter or not then find reduce ascii value
        if(isalpha(word[i])){
            if(isupper(word[i])){
                nextLetter = word[i] - 'A';
                //printf(nextLetter);
            }
            else{
                nextLetter = word[i] - 'a';
                //printf(nextLetter);
            }
        }
        //if it isnt a letter it has to be a apostrophe
        else{
            nextLetter = 26;
            //printf("!");
        }
        //check if next letter exists if it doesnt return false if it does continue down word
        if(current->child[nextLetter] == NULL){
            return false;
            //printf("#");
        }
        else
        {
            current = current->child[nextLetter];
        }
    }
    if(current->is_word == true){
        return true;
    }
    //printf("$");
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE* dic = fopen(dictionary, "r");
    if(dic == NULL){
        return false;
    }
    root = malloc(sizeof(node));
    node* current = root;
    
    dictionarySize = 0;
    
    for(int let = tolower(fgetc(dic)); let != EOF; let = tolower(fgetc(dic))){
        //endoflinecheck reset current to root for next word
        if(let == '\n'){
            dictionarySize++;
            current->is_word = true;
            current = root;
            
        }
        else
        {
            //check for ' and set to so it will be placed at end of letter array
            if(let == '\''){
                let = 123;
            }
           //check if node has been created. If not create one and add.
            struct node* nextNode = current->child[let-97];
            if (nextNode == NULL)
            {
                // Allocate space if it is not yet there
                current->child[let-97] = malloc(sizeof(node));
                current = current->child[let-97];
            }
            else
            {
                current = nextNode;
            }
            
        }
    }
    fclose(dic);
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dictionarySize;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    free(root);
    return true;
}
