#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* findLastA(char* inputStr);
void sortArray(int array[], int arraySize);

int main() {

//    printf("Type string:\n");
   char uIn[100];
//    fgets(uIn, 100, stdin);
    char *Aptr = findLastA(uIn);
//    if(Aptr)
//    printf("%s", Aptr);

    //\/home/CLionProjects/Exam2/textfile.txt
    char fileName[] = "/home/chris/CLionProjects/Exam2/textfile";

    FILE *fp;
    fp = fopen(fileName, "r");
    fgets(uIn,100,fp);

    Aptr = findLastA(uIn);
    if(Aptr)
        printf("%s\n", Aptr);

    int array[10];
    for( size_t i = 0; i<10; i++){
        printf("Input next num: ");
        fgets(uIn,100,stdin);
        array[i] = atoi(uIn);
    }
    printf("unsorted:\n");
    for( size_t i = 0; i<10; i++){
        printf("%d\n", array[i]);
    }
    printf("sorted:\n");
    sortArray(array, 10);
    for( size_t i = 0; i<10; i++){
        printf("%d\n", array[i]);
    }

    return 0;
}

char* findLastA(char* inputStr){
    char* tempP= inputStr;
    do{
        tempP = strchr(tempP,'a');
        if(tempP){
            inputStr = tempP;
            tempP++;
        }
    }while(tempP);
    return(inputStr);
}

void sortArray(int array[], int arraySize) {
    int temp;
    for (size_t j = 0; j < arraySize; j++) {
        for (size_t i = 0; i < arraySize; i++) {
            if (array[i] > array[i + 1]) {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}