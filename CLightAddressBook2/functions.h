//
// Created by chris on 5/1/18.
//

#ifndef CLIGHTADDRESSBOOK2_FUNCTIONS_H
#define CLIGHTADDRESSBOOK2_FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct contact {
    char firstName[255], lastName[255], email[255], phone[255];
    struct contact * prevC;
    struct contact * nextC;
};

struct AddressBook{
    struct contact * firstC;
    int count;
};

typedef struct AddressBook * pAddressBook;

void addContact(pAddressBook, int, char[]);

void deleteContact(pAddressBook, int);

void getContact(pAddressBook, int);

void getField(pAddressBook, int, char[]);

void loadFile(pAddressBook);

void saveFile(pAddressBook);

void editContact(pAddressBook);

void sortContacts(pAddressBook);

struct contact* makeContact(char []);

#endif //CLIGHTADDRESSBOOK2_FUNCTIONS_H
