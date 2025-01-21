#include <stdio.h>
#include <string.h>

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

void rufemalDreiAufEx()
{
    int x = 10;
    printf("Vorher: %d\n", x);

    malDreiEx(&x);
    printf("Nachher: %d\n", x);
}

void zeiger_demo_with_pointer_aithmetic()
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
}
