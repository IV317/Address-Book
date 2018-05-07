//
// Created by chris on 4/24/18.
//

#ifndef CLIGHTADDRESSBOOK_FUNTIONS_H
#define CLIGHTADDRESSBOOK_FUNTIONS_H

typedef struct {
    char firstName[255], lastName[255], email[255], phone[255];
    struct Contact * prevC;
    struct Contact *nextC;
}Contact;

typedef Contact * pNode;

Contact * addContact(pNode);

void deleteContact(pNode);

void getContact(pNode);

void getField(pNode);

void getNumber(pNode);

void loadFile(pNode);

void saveFile(pNode);

void editContact(pNode);

void sortContacts(pNode);

Contact * makeNode(Contact*);

#endif //CLIGHTADDRESSBOOK_FUNTIONS_H
