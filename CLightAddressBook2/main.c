#include "functions.h"

int main() {
    //create the Address Book
    pAddressBook pAB = malloc(sizeof(struct AddressBook));
    pAB->count =0;
    pAB->firstC = NULL;

    int index;
    char uIn[BUFSIZ];
    printf("Ready\n");
    fgets(uIn, BUFSIZ, stdin);

    while (uIn[0] != 'q') {
                switch(uIn[0]){
                    case'a':
                        index = atoi(fgets(uIn,BUFSIZ,stdin));
                        fgets(uIn, BUFSIZ,stdin);
                        addContact(pAB, index, uIn);
                        break;
                    case 'd':
                        index = atoi(fgets(uIn,BUFSIZ,stdin));
                        deleteContact(pAB, index);
                        break;
                    case 'g':
                        index = atoi(fgets(uIn,BUFSIZ,stdin));
                        getContact(pAB, index);
                        break;
                    case 'f':
                        index = atoi(fgets(uIn,BUFSIZ,stdin));
                        fgets(uIn,BUFSIZ,stdin);
                        uIn[strlen(uIn)-1]='\0';
                        getField(pAB, index, uIn);
                        break;
                    case 'n':
                        printf("%d\n", pAB->count);
                        break;
                    case 'l':
                        loadFile(pAB);
                        break;
                    case 's':
                        saveFile(pAB);
                        break;
                    case 'e':
                        editContact(pAB);
                        break;
                    case 'o':
                        sortContacts(pAB);
                        break;
                    default:
                        break;
                }
        fgets(uIn, BUFSIZ, stdin);
        }

    printf("Complete\n");
    return (EXIT_SUCCESS);
}