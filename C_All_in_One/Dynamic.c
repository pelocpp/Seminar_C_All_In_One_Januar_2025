#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>    // malloc
#include <crtdbg.h>

#include <stdio.h>     // printf

// Dynamische Speicherverwaltung

static void test_dynamic_01()
{
    // Eine int-Variable dynamisch auf der Halde anlegen:

    int countBytes = sizeof(int);

    // Typkonvertierung: von void* nach int*
    int* ptr = (int*) malloc(countBytes);

    *ptr = 123;

    free(ptr);

    printf("Done.\n");
}

static void test_dynamic_02()
{
    // Eine int-Variable dynamisch auf der Halde anlegen:

    int countBytes = sizeof(int);

    int* ptr = malloc(countBytes);

    if (ptr != NULL) {

        *ptr = 123;

        free(ptr);
    }
    else {

        printf("malloc failed !\n");
    }
}

// =========================================

static void useDataOnTheHeap(int* data)
{
    printf("useDataOnTheHeap: %d\n", *data);

    free(data);
}

static void test_dynamic_03()
{
    // Eine int-Variable dynamisch auf der Halde anlegen:

    int countBytes = sizeof(int);
    int* ptr = malloc(countBytes);   // <== Zeiger: malloc

    *ptr = 123;

    useDataOnTheHeap(ptr);

    free(ptr);
}

static void test_dynamic_04()
{
//    int n = 50;
//    int feld[n];

    // Feld dynamischer Länge von int-Variablen anlegen
    int n = 20;

    int countBytes = n * sizeof(int);

    int* ptr = malloc(countBytes);   // Ab / hinter der Adresse in ptr ist
                                     // Platz für 'n' int-Werte

    // vorbelegen - pure -  mit Zeigerarithmetik
    for (int i = 0; i < n; ++i) {
        *(ptr + i) = 2 * i;
    }

    // vorbelegen - in einer angenehmeren Syntax
    for (int i = 0; i < n; ++i) {
        ptr[i] = 2 * i;
    }

    // ausgeben
    for (int i = 0; i < n; ++i) {
        
        printf("%02d: %d\n", i, *(ptr+i));
    }

    // ausgeben
    for (int i = 0; i < n; ++i) {

        printf("%02d: %d\n", i, ptr[i]);
    }
}

static void test_dynamic_05_gimmicks()
{
    int n = 20;
    int countBytes = n * sizeof(int);
    int* ptr = malloc(countBytes);

    // vorbelegen
    for (int i = 0; i < n; ++i) {
        ptr[i] = 2 * i;
    }

    int index = 5;
    int value = ptr[index];

    value = index[ptr];   // ???
    value = *(index + ptr);
    value = *(ptr + index);

    value = 8[ptr];       // ???

    printf("%d: %d\n", index, value);
}

static void test_dynamic_06_gimmicks()
{
    int n = 20;
    int countBytes = n * sizeof(int);
    int* ptr = malloc(countBytes);

    // getNumberOfBytes (ptr)
    int wievieleBytes = ptr[-4];  // ??? // *(ptr -1)
    // Unter Visual C++ // malloc liegt bei 4 Stellen VOR DER ADRESSE (-4)
    // die Länge des allokierten Bereichs
    printf("wievieleBytes: %d\n", wievieleBytes);
}

static void test_dynamic_07_gimmicks()
{
    int n = 123;
    int value = 0;

    int* ptr = &n;
    value = *ptr;
    printf("n: %d\n", value);

    int** ptr2 = &ptr;
    value = **ptr2;
    printf("n: %d\n", value);

    int*** ptr3 = &ptr2;
    value = ***ptr3;
    printf("n: %d\n", value);

    int**** ptr4 = &ptr3;
    value = ****ptr4;
    printf("n: %d\n", value);
}


void test_dynamic()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    test_dynamic_07_gimmicks();
}
