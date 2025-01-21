#include <stdio.h>
#include <string.h>

#include "Functions.h"

void zeiger_demo()
{
    int n = 123;   // n ist eine int-Variable

    int* ptr;      // ptr ist eine Zeiger-Variable, die auf einen int-Wert zeigt.

    ptr = &n;

    int m = *ptr;

    printf("n = m = %d\n", m);
}

// Whyyyyyyyyyyyyyyyyyyyyyyyyyyyy

static void malDrei(int para)
{
    para = para * 3;
}

void rufemalDreiAuf()
{
    int x = 10;
    printf("Vorher: %d\n", x);

    malDrei(x);
    printf("Nachher: %d\n", x);

    malDrei(x);
    printf("Nochmal Nachher: %d\n", x);
}

// Nochmal Whyyyyyyyyyyyyyyyyyyyyyyyyyyyy

static void malDreiEx(int* ptr)
{
    // para = para * 3;

    int tmp;

    tmp = *ptr;   // Adresse auf der rechten Seite: lesen

    tmp = tmp * 3;

    *ptr = tmp;  // Adresse auf der linken Seite: schreiben
}

static void malDreiExEx(int* ptr)
{
    // advanced
    *ptr = *ptr * 3;
    // oder
    *ptr = 3 * (*ptr);
    // oder
    *ptr = 3**ptr;   // very, very bad --- smells extremely
}

void rufemalDreiAufEx()
{
    int x = 10;
    printf("Vorher: %d\n", x);

    malDreiEx(&x);
    printf("Nachher: %d\n", x);
}

// Implementierung
void zeiger_demo_with_pointer_arithmetic()
{
    int n = 123;   // n ist eine int-Variable

    int* ptr = NULL;      // ptr ist eine Zeiger-Variable, die auf einen int-Wert (n) zeigt.

    // int* ptr = &n;
    // oder
    ptr = &n;

    printf("*ptr: %d\n", *ptr);

    printf("sizeof (int): %zu\n", sizeof(int));

    ++ptr;   // vorher: 0x1024 // nachher: 0x1028 !!!

    int m = *ptr;
    printf("m (???): %d\n", m);

    --ptr;
    m = *ptr;
    printf("m (???): %d\n", m);

    // ==================================

    char ch = 'A';

    char* cp = &ch;

    ++cp;

    // ==================================

    short s = 123;

    short* sp = &s;

    ++sp;
}

void swap(int* ptr1, int* ptr2)
{
    // adavanced
    int tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}

void exercise_tausche()
{
    printf("Funktion swap\n");
    printf("=============\n");

    int n = 123;
    int m = 456;

    printf("n = % d, m = % d\n", n, m);

    swap(&n, &m);

    printf("n = % d, m = % d\n", n, m);
}
