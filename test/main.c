#include <stdio.h>

int main() {
    int x = 5;
    char text[] = "hello, my name is, john";
    char first[25], middle[25], last[25];

    if (x > 4) {
        int i,j,k = 0;
        while (text[i] != ',') {
            first[i] = text[i];
            i++;
        }
        first[i]='\0';
        i++;
        while (text[i] != ',') {
            middle[j] = text[i];
            i++;
            j++;
        }
        middle[j]='\0';
        i++;
        while (text[i] != '\0') {
            last[k] = text[i];
            i++;
            k++;
        }
        last[k]='\0';
        printf("first: %s \nmiddle: %s \nlast: %s", first, middle, last);
    }


    return 0;
}