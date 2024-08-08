//library.c
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "library.h"
#include <string.h>

char* getMap(){
    
    char* map = (char *)malloc(64* sizeof(char));
    map = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    return map;
}

char* decimalToBinary(int n, int p){
    char* binary = (char *)malloc((p+1)* sizeof(char));
    // binary[8] = '\0';
    for(int i = p - 1; i >= 0; i--){
        binary[i] = (n & 1) ? '1' : '0';
        n >>= 1; //right shift by 1(divide by 2)
    }
    binary[p] = '\0';
    return binary;
}

int get_ceil(int a, int b){
    if(!(a % b)) return a;
    return (a / b) + 1;
}

int binaryToDecimal(char* bin, int p){
    int posi = 0;
    int ans = 0;
    for(int i = p - 1; i >= 0; i--){
        ans += (power(2, posi) * (bin[i] - '0'));
        posi++;
    }
    return ans;
}

int power(int a, int b){
    if(b == 0) return 1;
    int ans = 1;
    for(int i = 0; i < b; i++){
        ans *= a;
    }
    return ans;
}

int padding_len(int len){
    int mult = get_ceil(8*len, 6);
    int expected_len = 6*mult;
    int actual_len = 8*len;
    return (expected_len - actual_len)/2;
}

char* encode(char* str, int len, char* map){
    char matrix[len][9];
    for(int i = 0; i < len; i++){
        char* binary = decimalToBinary(str[i] - 0, 8);
        for(int j = 0; j < 9; j++){
            matrix[i][j] = binary[j];
            // printf("%c", matrix[i][j]);
        }
        // printf("\n");
    }
    int padding_val = padding_len(len);
    if((8 * len) % 6 == 0) padding_val = 0;
    // printf("%d", binaryToDecimal("100110"));

    int bin_size = get_ceil(8 * len, 6);

    char array[bin_size][6];
    for(int i = 0; i < bin_size; i++){
        for(int j = 0; j < 6; j++){
            array[i][j] = '0';  
        }
    }

    int cur_ind = 0;
    int cnt = 0;
    for(int i = 0; i < len; i++){
        for(int j = 0; j < 8; j++){
            if(cnt == 6){
                cnt = 0;
                cur_ind++;
            }
            array[cur_ind][cnt++] = matrix[i][j];
        }
    }

    int enc_len = get_ceil(8 * len, 6) + padding_val;
    char* encoded_message = (char *)malloc(enc_len * sizeof(char));
    int ind = 0;
    // printf("%d\n", enc_len);
    for(int i = 0; i <= cur_ind; i++){
        char conv[6] ;
        for(int j = 0; j < 6; j++){
            conv[j] = array[i][j];
        }
        // printf("%c", map[binaryToDecimal(conv)]);
        encoded_message[ind++] = map[binaryToDecimal(conv, 6)];
    }
    while(padding_val--){
        // printf("=");
        encoded_message[ind++] = '=';
    }
    // abcd -> YWJjZA==
    encoded_message[ind] = '\0';
    return encoded_message;
}

char* decode(char* str){
    int len = 0;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == '=') break;
        len++;
    }
    char binaries[len][7];
    for(int i = 0; i < len; i++){
        int index;
        char c = str[i];
        if(c >= 'A' && c <= 'Z'){
            index = c - 'A';
        }
        else if(c >= 'a' && c <= 'z'){
            index = c - 'a' + 26;
        }
        else if(c >= '0' && c <= '9'){
            index = c - '0' + 52;
        }
        else if(c == '+') index = 62;
        else if(c == '/') index = 63;
        char* bin = (char*)malloc(7*sizeof(char));
        bin = decimalToBinary(index, 6);
        for(int j = 0; j < 6; j++){
            binaries[i][j] = bin[j];
        }
        // bin[7] = '\0'; //seg fault
        // free(bin); //seg fault
    }
    // for(int i = 0; i < len; i++){
    //     for(int j = 0; j < 6; j++){
    //         printf("%c", binaries[i][j]);
    //     }
    //     printf("\n");
    // }
}