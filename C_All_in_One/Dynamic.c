#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>    // malloc
#include <crtdbg.h>

#include <stdio.h>     // printf


// Dynamische Speicherverwaltung

void test_dynamic_01()
{
    // Eine int-Variable dynamisch auf der Halde anlegen:

    int countBytes = sizeof(int);

    // Typkonvertierung: von void* nach int*
    int* ptr = (int*) malloc(countBytes);

    *ptr = 123;

    free(ptr);

    printf("Done.\n");
}

void test_dynamic_02()
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

void useDataOnTheHeap(int* data)
{
    printf("useDataOnTheHeap: %d\n", *data);

    free(data);
}

void test_dynamic_03()
{
    // Eine int-Variable dynamisch auf der Halde anlegen:

    int countBytes = sizeof(int);
    int* ptr = malloc(countBytes);   // <== Zeiger: malloc

    *ptr = 123;

    useDataOnTheHeap(ptr);

    free(ptr);
}

void test_dynamic()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    test_dynamic_01();
}