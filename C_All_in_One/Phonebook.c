#include <stdio.h>     // printf
#include <stdlib.h>    // malloc, free
#include <string.h>    // strlen, etc.
#include <ctype.h>     // isdigit, etc.

// Kontakte Verwaltung

// Ein Eintrag in der Kontakte Verwaltung

#define     ContactsLength      20

struct contact
{
    char*  m_name;   // Name
    size_t m_phone;  // Tel. Nummer
    int    m_full;   // 1 == belegt, 0 == leer
};

typedef struct contact Contact;

// Kontakte Verwaltung
// global für diese Datei
Contact myContacts[ContactsLength];    // Array of Structs

static void printContacts()
{
    for (int i = 0; i < ContactsLength; ++i) {

        if (myContacts[i].m_full == 1) {

            printf("%s: %zu\n", myContacts[i].m_name, myContacts[i].m_phone);
        }
    }
}

static void enterContact()
{
    // Namen einlesen
    char buffer[200] = { '\0' };

    printf("Bitte Namen eingeben: ");
    scanf_s("%s", buffer, 200);

    size_t nameLen = strlen(buffer);
    char* tmp = calloc(nameLen + 1, sizeof(char));
    strcpy_s(tmp, (nameLen + 1) * sizeof(char), buffer);

    // ====================================================
    // Tel.Nummer einlesen
    // 1. Variante: Ohne Überfrüfung falscher Eingaben von der Konsole
    //printf("Bitte Nummer eingeben: ");
    //size_t number = 0;
    //scanf_s("%zu", &number);
    // end
    // ===================================================

    // ====================================================
    // Tel.Nummer einlesen
    // 2. Variante: MIT Überfrüfung falscher Eingaben von der Konsole
    printf("Bitte Nummer eingeben: ");

    int succeeded = 0;  // no success

    do
    {
        scanf_s("%s", buffer, 200);  // Eingabe von der Konsole

        // Eingabe in buffer ist erfolgt - sind das alles Ziffern zwischen 0 und 9
        size_t lengthInput = strlen(buffer);
        int i = 0;
        while (i != lengthInput) {

            if (!isdigit(buffer[i])) {
                printf("Wrong Number - please enter number again: ");
                break;
            }

            ++i;
        }

        if (i == lengthInput) {
            succeeded = 1;
        }

    } while (succeeded == 0);

    // convert char input to size_t
    size_t number = 0;
    sscanf_s(buffer, "%zu", &number);   // Eingabe aus einer Zeichenkette (hier: buffer)

    // end
    // ===================================================

    // create a contact structure
    Contact c = { .m_name = tmp, .m_phone = number, .m_full = 1 };

    // search empty slot in global contacts array

    int slotFound = 0;  // kein Slot gefunden

    for (int i = 0; i < ContactsLength; ++i) {

        if (myContacts[i].m_full == 0) {  // empty

            myContacts[i] = c;   // Wertzuweisung von Strukturen (geht !!!)
            slotFound = 1;
            break;
        }
    }

    if (slotFound == 0) {

        printf("No more memory for this Contact\n");
    }
    else {
        printf("Contact entered successfully\n");
    }     
}

static void searchContact()
{
    // Namen einlesen
    char buffer[200] = { '\0' };

    printf("Bitte Namen eingeben: ");
    scanf_s("%s", buffer, 200);

    // search this name in contacts array

    int found = 0; // not found

    for (int i = 0; i < ContactsLength; ++i) {

        if (myContacts[i].m_full == 0) {
            continue;
        }

        if (strcmp (myContacts[i].m_name, buffer) == 0 ) {  // found

            printf("Eintrag '%s' gefunden: Nr. = %zu\n", buffer, myContacts[i].m_phone);
            found = 1;
            break;
        }
    }

    if (found == 0) {

        printf("Name '%s' nicht gefunden !\n", buffer);
    }
}



void test_contacts()
{
    enterContact();

    searchContact();

    enterContact();
    enterContact();

    printContacts();
}

