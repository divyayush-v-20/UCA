#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef BASE_64_LIBRARY
#define BASE_64_LIBRARY

char* getMap();

char* decimalToBinary(int n, int p);

int get_ceil(int a, int b);

int binaryToDecimal(char* bin, int p);

int power(int a, int b);

int padding_len(int x);

char* encode(char* str, int len, char* map);

char* decode(char* str);

#endif