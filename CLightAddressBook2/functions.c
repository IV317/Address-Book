//
// Created by chris on 5/1/18.
//
#include "functions.h"

void addContact(pAddressBook pAB, int index, char uIn[]){

    struct contact * pCur = pAB->firstC;
    struct contact *pIns = makeContact(uIn);

        if (index == 0 && pAB->count == 0 && pIns) { //first entry
            pAB->firstC = pIns;
            pAB->count++;
        } else if (index < pAB->count && index != 0 && pIns) { //insert intermediate
            int i = 0;
            while (i < index) {
                pCur = pCur->nextC;
                i++;
            }
            pIns->nextC = pCur;
            pCur->prevC->nextC = pIns;
            pIns->prevC = pCur->prevC;
            pCur->prevC = pIns;
            pAB->count++;
        } else if (index == pAB->count && pIns) { //insert last
            int i = 1;
            while (i < index) {
                pCur = pCur->nextC;
                i++;
            }
            pCur->nextC = pIns;
            pIns->prevC = pCur;
            pAB->count++;
        } else if (index == 0 && pIns) { //insert first
            pIns->nextC = pCur;
            pCur->prevC = pIns;
            pAB->firstC = pIns;
            pAB->count++;
        } else {
            printf("Not a valid input! Current count is: %d \n", pAB->count);
        }
    }

void deleteContact(pAddressBook pAB, int index){
    int i = 0;
    struct contact * pCur = pAB->firstC;

    if (index == 0 && pAB->count == 1) { //delete last, 0 count
        free(pCur);
        pAB->count--;
    }
    else if (index == pAB->count-1){ //delete last
        while (i < index) {
            pCur = pCur->nextC;
            i++;
        }
        free(pCur);
        pAB->count--;
    }
    else if (index <= pAB->count-1 && index !=0){ //delete intermediate
        while (i < index) {
            pCur = pCur->nextC;
            i++;
        }
        struct contact * pTemp = pCur->prevC;
        pCur->prevC->nextC = pCur->nextC;
        pCur->nextC->prevC = pTemp;
        free(pCur);
        pAB->count--;
    }
    else if (index ==0 && pAB->count!=0 ){ //delete first
        pAB->firstC = pAB->firstC->nextC;
        free(pCur);
        pAB->count--;
    }
    else{
        printf("Not a valid input! Current count is: %d \n", pAB->count);
    }
}

void getContact(pAddressBook pAB, int index){
    int i = 0;
    struct contact * pCur = pAB->firstC;

    if(index <= pAB->count-1) {
        while (i < index) {
            pCur = pCur->nextC;
            i++;
        }
        printf("%s, %s, %s, %s\n", pCur->firstName, pCur->lastName, pCur->email, pCur->phone);
    }
    else{
        printf("Not a valid input! Current count is: %d \n", pAB->count);
    }
}

void getField(pAddressBook pAB, int index, char uIn[]){
    struct contact * pCur = pAB->firstC;
    int i = 0;

    if(index <= pAB->count-1 && strstr("firstNamelastNameemailphoneNumber", uIn)) {
        while (i < index) {
            pCur = pCur->nextC;
            i++;
        }
        if(!strcmp(uIn, "firstName")) {
            printf("%s\n", pCur->firstName);
        }
        else if(!strcmp(uIn, "lastName")){
            printf("%s\n", pCur->lastName);
        }
        else if(!strcmp(uIn, "email")){
            printf("%s\n", pCur->email);
        }
        else{
            printf("%s\n", pCur->phone);
        }
    }
    else{
        printf("Not a valid input! Current count is: %d \n", pAB->count);
    }
}

void loadFile(pAddressBook pAB) {
    char uIn[BUFSIZ], stringLoad[BUFSIZ];
    fgets(uIn, BUFSIZ, stdin);
    uIn[strlen(uIn) - 1] = '\0';
    int i = pAB->count;

    //\/home/chris/CLionProjects/CLightAddressBook2/test.csv
    FILE *fp = fopen(uIn, "r");
    while (!feof(fp)) {

        stringLoad[0] = '\0'; //nullify first char in case fgets !get
        fgets(stringLoad, BUFSIZ, fp);
        if(stringLoad[0] != '\0') {
            addContact(pAB, i, stringLoad);
        }
        i++;
    }
    fclose(fp);
}

    void saveFile(pAddressBook pAB) {
        char uIn[BUFSIZ], stringLoad[BUFSIZ];
        struct contact * pCur = pAB->firstC;
        fgets(uIn, BUFSIZ, stdin);
        uIn[strlen(uIn) - 1] = '\0';
        FILE *fp = fopen(uIn, "w");

        for(int i=0; i<pAB->count;i++){
            strcpy(stringLoad,pCur->lastName);
            strcat(stringLoad,", ");
            strcat(stringLoad,pCur->firstName);
            strcat(stringLoad,", ");
            strcat(stringLoad,pCur->email);
            strcat(stringLoad,",");
            strcat(stringLoad,pCur->phone);
            strcat(stringLoad,"\n");
            fprintf(fp,stringLoad);
            pCur = pCur->nextC;
        }
        fclose(fp);
    }

    void editContact(pAddressBook pAB) {
        printf("edit contact sel\n");
    }

    void sortContacts(pAddressBook pAB) {
        printf("sort contact sel \n");
    }

    struct contact* makeContact(char uIn[]) {

        struct contact * ptempContact = malloc(sizeof(struct contact));

       char *lName = strtok(uIn, ",");
        while (isspace(*lName)) {
            lName++;
        }
        char *fName = strtok(NULL, ",");
        while (isspace(*fName)) {
            fName++;
        }
        char *email = strtok(NULL, ",");
        while (isspace(*email)) {
            email++;
        }
        char *phone = strtok(NULL, "\n");
        while (isspace(*phone)) {
            phone++;
        }

        strcpy(ptempContact->lastName, lName);
        strcpy(ptempContact->firstName, fName);
        strcpy(ptempContact->email, email);
        strcpy(ptempContact->phone, phone);

        return(ptempContact);
    }
