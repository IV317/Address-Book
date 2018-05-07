#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {

    //setvbuf(stdout, NULL, _IONBF, 0);

    char uIn[BUFSIZ];
    char commandMap[10] = "adgfnlseo";
    Contact (*
    (*functions[9])(struct Contact *))={addContact, deleteContact, getContact, getField, getNumber, loadFile, saveFile,
                                       editContact, sortContacts};

    pNode topNode = malloc(sizeof(Contact));
    topNode->nextC = NULL;
    topNode->prevC = NULL;

    printf("Ready\n");
    fgets(uIn, BUFSIZ, stdin);

    while (uIn[0] != 'q') {
        for (int command = 0; command <= 8; command++) {
            if (uIn[0] == commandMap[command])

                topNode = (*functions[command])(topNode);
        }
        fgets(uIn, BUFSIZ, stdin);
        //printf("%c",uIn[0]);
        //printf("asdf");
    }

    printf("Complete\n");
    return (EXIT_SUCCESS);
}