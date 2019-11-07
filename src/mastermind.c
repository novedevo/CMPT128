#include <stdio.h>

void printArray(int *array[6], int size){
    for (size_t i = 0; i<size; i++){
        printf("%d", array[i]);
    }
}

int main(){
    int array [6] = {1,2,3,4,5};
    printArray(&array,6);
}
