#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "library.h"
#include <string.h>
bool validInput(char* str, int len){
    bool flag = false;
    for(int i = 0; i < len; i++){
        if(str[i] == ' ' || str[i] == '\t'){
            flag = true;
        }
    }
    if(flag){
        printf("Input cannot have white spaces, provide a valid input");
        return false;
    }
    return true;
}
int main(){
    char* map = getMap();
    char str[100];
    fgets(str, sizeof(str), stdin);
    int len = -1;
    for(int i = 0; str[i]; i++){
        len++;
    }
    if(!validInput(str, len));
    else{
        char* encoded_msg = encode(str, len, map);
        printf("%s", encoded_msg);
        // decode(encoded_msg);
        // decode(encoded_msg);
        // decode(encoded_msg);
    }
    // printf("%d", getIndex('A'));
}
