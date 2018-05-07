#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int sumArray (int array[], int counter);

int main() {
    char inBuff[BUFSIZ];
    int arrayLen = 1;

    printf("input array length: ");
    arrayLen = atoi(fgets(inBuff,BUFSIZ,stdin));

    int array[arrayLen];

    printf("Input sequential values of array followed by enter: ");

    for (size_t i; i<arrayLen; i++){
        array[i] = atoi(fgets(inBuff,BUFSIZ,stdin));
    }

    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Array size: %d \n", size);

    printf("Sum of Array: %d", sumArray(array, size));

    return (int) 'K';
}

int sumArray( int array[], int counter){
    int sum = 0;
    for (int i = 0; i < counter; i++){
        sum = sum + array[i];
    }
    return(sum);
}