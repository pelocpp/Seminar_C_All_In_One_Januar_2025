#include <stdio.h>
#include <string.h>

// Unterprogramm

void inkrement_zweimal()
{
    int i = 10;
    int m;

    // Nebeneffekte
    // m = i++;  // Post-Inkrement: Erst Wertzuweisung, dann Inkrement
    // m = ++i;  // Pre-Inkrement: Erst Inkrement, dann Wertzuweisung

    m = i;      // Best Practice
    i++;

    printf("m: %d\n", m);
}

void felder()
{
    // 10 int-Werte in einem Feld vereinbaren
    int zahlen[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Zugriff auf das ERSTE Element:  Index 0 für das ERSTE Element
    int first = zahlen[0];

    // Zugriff auf das LETZTE Element:  Index 9 für das LETZTE Element
    // Merkhilfe: Der INDEX des letzten Elements eines Felds ist
    // gleich: LÄNGE minus 1

    // int last = zahlen[9];
    int last = zahlen[9];

    // wie belegt man ein Feld typischerweise vor:  for-Schleife
    for (int i = 0; i < 10; i++)
    {
        zahlen[i] = 2 * i;
    }

    //  wie gibt man ein Feld aus for-Schleife
    for (int i = 0; i < 10; i++)
    {
        printf("%d: %d\n", i, zahlen[i]);
    }
}

void blockschachtelung()
{
    int i = 123;
    printf("i: %d\n", i);

    // Block
    {
        int i = 11;  // Hier wird i aus Zeile 8 VERDECKT // Hidden
                     // I wouldn't do this !!! Code Smell
        printf("i: %d\n", i);
        // Das i aus Zeile 8 ist in dieser Zeile UNERREICHBAR !!!!!!!

        int j = 2;
        printf("j: %d\n", j);
    }

    printf("i: %d\n", i);
}

void printer ( int start, int ziel )   // count: Stellvertreter
{
    for (int i = start; i < ziel; ++i)
    {
        printf("Hello Seminar\n");

        if (i == 20) {
            // break;
            return;
        }
    }
    printf("Done Unterprogramm\n");
}

int malDrei(int value)
{
    int result;

    result = 3 * value;

    return result;
}

void main_ups()
{
    int wieOft = 5;
    printer(3, 6);              // Aufruf eines C-Unterprogramms - kein Ergebnis

    int ergebnis = malDrei(5);  // Aufruf einer C-Funktion - mit Ergebnis abholen
}

// ====================================

void for_loop()
{
    // simple for - loop
    for (int i = 0; i < 10; i++)
    {
        printf("i: %d\n", i);
    }

    printf("Fertig\n");

    // for - loop with break
    for (int i = 0; i < 10; i++)
    {
        printf("i: %d\n", i);

        // eine Besonderheit ist eingetreten
        if (i == 5) {
            // möchte vorzeitig ("unerwartet") die for-Schleife verlassen
            break;
        }
    }

    printf("Fertig\n");

    // for - loop with continue
    for (int i = 0; i < 10; i++)
    {
        // eine Besonderheit ist eingetreten - keine Ausgabe 
        if (i == 5) {
            // möchte für i == 5 keine Verarbeitung
            continue;
        }

        printf("i: %d\n", i);
    }
}

void what_is_modulo()
{
    int zaehler = 7;
    int nenner = 3;

    int result = zaehler / nenner;
    int rest = zaehler % nenner;

    // Achtung / Vorsicht
    double dresult = zaehler / nenner;

    // Eingabe von Nenner von der Konsole:
   // scanf_s("%d", &nenner);

    double d;
    scanf_s("%lf", &d);


    dresult = zaehler / nenner;

    dresult = zaehler / 3.0;

    dresult = zaehler / (double) nenner;   // Typ-Konvertierung nach double
}

void what_is_a_condition()
{
    int value;

    value = 2;

    if (value) {

        printf("Condition is fulfilled\n");
    }

    if (value == 0) {   // Vergleich auf Gleichheit

        printf("Condition is fulfilled\n");
    }

    if (value != 0) {   // Vergleich auf Ungleichheit

        printf("Condition is fulfilled\n");
    }

    printf("Done\n");
}

void while_statement()
{
    int a = 10;

    while ( a < 5 )
    {
        printf("a: %d\n", a);

        a = a + 1;
    }

    printf("Done (1)\n");

    do
    {
        printf("a: %d\n", a);
        a = a + 1;
    }
    while (a < 5);

    printf("Done (2)\n");
}

void if_statement_three()
{
    int a = 0;

    a = 3; 

    if (a > 5)
    {
        printf("condition fulfilled\n");
    }
    else
    {
        printf("condition NOT fulfilled\n");
    }


    a = 5;

    if (a < 10)
    {
        printf("condition fulfilled\n");
    }
    else if (a >= 10 && a < 20)
    {
        printf("condition NOT fulfilled\n");
    }
    else if (a >= 20)
    {
        printf("else condition fulfilled\n");
    }

    // EIN VERGLEICH

    a = 5;

    if (a < 10)
    {
        printf("condition fulfilled\n");
    }
    
    if (a >= 10 && a < 20)
    {
        printf("condition NOT fulfilled\n");
    }
    
    if (a >= 20)
    {
        printf("else condition fulfilled\n");
    }

    printf("Done\n");
}

void if_statement_two()
{
    int a = 0;        // declaration
    int b = 0;        // declaration

    a = 10;            // statement: assignment
    b = 5;             // statement: assignment

    if (a > 5 && b < 10)   //  logical AND
    {
        printf("value is greater than 5\n");
        printf("value is really greater than 5\n");
    }

    if (a > 5 || b < 10)   //  logical OR  // zwei senkrechte
    {
        printf("value is greater than 5\n");
        printf("value is really greater than 5\n");
    }

    if ( ! (a > 5)  )   //  logical NOT  // 
    {
        printf("value is greater than 5\n");
        printf("value is really greater than 5\n");
    }

    printf("Done");
}

void if_statement()
{
    int value = 0;  // declaration

    value = 13;      // statement: assignment

    // Querbezug zu VBA
    // SET value = 3     

    if (value > 5)
    {
        printf("value is greater than 5\n");
        printf("value is really greater than 5\n");
    }

    // Querbezug zu VBA
    if (value > 5)
    {   // THAN
        printf("value is greater than 5\n");
        printf("value is really greater than 5\n");
    }  //  END IF

    value = 3;

    // Achtung: if-Anweisungen mit EINER Anweisung
    if (value > 5) {
        printf("value is greater than 5\n");
    }

    printf("value is really greater than 5\n");

    printf("Done");
}

void variables_datatypes_constants()
{
    // Konstante // Literal
    123;        // statement ... tut nichts
    123.456;    // constant: float oder double: double
    123.456f;   // constant: float oder double: float
    123l;       // long
    123ll;      // long long

    int value = 0;        // declaration
    int secondValue = 0;  // declaration
    int result;

    value = 2;            // assignment
    secondValue = 3;      // assignment

             // 2 + 3 * 5 : "Punkt vor Strich"
    result = (value + secondValue) * 5; // assignment // arithmetic expression
}

void sizeof_example ()
{
    printf("Hello World\n");

    printf("Sizeof (int):       %zu\n", sizeof(int));
    printf("Sizeof (short):     %zu\n", sizeof(short));
    printf("Sizeof (long long): %zu\n", sizeof(long long));

   // getchar();
}

void main()
{
    inkrement_zweimal();
}
