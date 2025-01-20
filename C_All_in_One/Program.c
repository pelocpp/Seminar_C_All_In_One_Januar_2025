#include <stdio.h>
#include <string.h>

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

    getchar();
}

void main()
{
    what_is_a_condition();
}