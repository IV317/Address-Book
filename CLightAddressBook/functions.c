//
// Created by chris on 4/24/18.
//
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

Contact *addContact(pNode topNode) {

    char uIn[BUFSIZ];
    int index = atoi(fgets(uIn, BUFSIZ, stdin));

    if (index == 0 && topNode->nextC == NULL) {
        topNode = makeNode(topNode);
    } else if (index == 0) {
        pNode tempNodeA = malloc(sizeof(Contact));
        tempNodeA = makeNode(tempNodeA);

        tempNodeA->nextC = topNode;
        topNode->prevC = tempNodeA;
        topNode = topNode->prevC;
        topNode->prevC = NULL;
    } else {
        int q = 0;
        pNode tempNodeA = malloc(sizeof(Contact));
        pNode tempNodeB = topNode;
        while (q <= index) {
            tempNodeB = tempNodeB->nextC;
            q++;
        }
        tempNodeA->nextC = tempNodeB;
        tempNodeB->prevC = tempNodeA;
        tempNodeB = tempNodeB->prevC;
        tempNodeB = tempNodeB->prevC;
        tempNodeB->nextC = tempNodeA;
        free(tempNodeB);
    }
    return (topNode);
}

void deleteContact(pNode topNode) {
    printf("delete contact selected\n");
    char uIn[BUFSIZ];
    return;
}

void getContact(pNode topNode) {
    printf("get contact selected\n");
    char uIn[BUFSIZ];
    return;
}

void getField(pNode topNode) {
    printf("get field selected\n");
    char uIn[BUFSIZ];
    return;
}

void getNumber(pNode topNode) {
    printf("get number selected\n");
    return;
}

void loadFile(pNode topNode) {
    printf("load file selected\n");
    char uIn[BUFSIZ];
    fgets(uIn, BUFSIZ, stdin);
    printf(uIn);
    return;
}

void saveFile(pNode topNode) {
    printf("save file selected\n");
    char uIn[BUFSIZ];
    fgets(uIn, BUFSIZ, stdin);
    printf(uIn);
    return;
}

void editContact(pNode topNode) {
    printf("edit contact selected\n");
    char uIn[BUFSIZ];
    return;
}

void sortContacts(pNode topNode) {
    printf("sort contacts selected\n");
    return;
}

Contact * makeNode(Contact* tempNode){
    char uIn[BUFSIZ];
    int i, f, e, p = 0;
    //printf("%d", index);
    fgets(uIn, BUFSIZ, stdin);

    while (uIn[i] != ',') {
        tempNode->lastName[i] = uIn[i];
        i++;
    }
    tempNode->lastName[i] = '\0';
    i++;
    while (uIn[i] != ',') {
        tempNode->firstName[f] = uIn[i];
        i++;
        f++;
    }
    tempNode->firstName[f] = '\0';
    i++;
    while (uIn[i] != ',') {
        tempNode->email[e] = uIn[i];
        i++;
        e++;
    }
    tempNode->email[e] = '\0';
    i++;
    while (uIn[i] != ',') {
        tempNode->phone[p] = uIn[i];
        i++;
        p++;
    }
    tempNode->phone[p] = '\0';
    return(tempNode);
}
