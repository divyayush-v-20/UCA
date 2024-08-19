#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void **elements;
    size_t size;
    size_t capacity;
}List;

void initList(List* list){
    list -> size = 0;
    list -> capacity = 4;
    list -> elements = malloc(list -> capacity * sizeof(void *));
}

void addElement(List* list, void* element){
    if(list -> size == list -> capacity){
        list -> capacity *= 2;
        list -> elements = realloc(list -> elements, list -> capacity * sizeof(void *));
    }
    list->elements[list -> size] = element;
    list -> size++;
}

void printList(List* list, void (*printFunc)(void *)){
    for(size_t i = 0; i < list -> size; i++){
        printFunc(list -> elements[i]);
    }
    printf("\n");
}

void printInt(void *element){
    printf("%d ", *(int *)element);
}

void printString(void *element){
    printf("%s ", (char *)element);
}

int main(){
    List intList;
    initList(&intList);

    int i = 5, j = 4, k = 3;

    addElement(&intList, &i);
    addElement(&intList, &j);
    addElement(&intList, &k);

    printList(&intList, printInt);

    List charList;
    initList(&charList);

    char* a = "abc";
    char* b = "def";
    char* c = "ghi";

    addElement(&charList, a);
    addElement(&charList, b);
    addElement(&charList, c);

    printList(&charList, printString);
    return 0;
}