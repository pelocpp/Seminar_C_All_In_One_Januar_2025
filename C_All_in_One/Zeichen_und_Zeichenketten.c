#include <stdio.h>

void test_zeichen()
{
    char ch = 'A';

    printf("Ein Zeichen: %c\n", ch);

    int n = 65;  // 65 == ASCII Wert von 'A'

    printf("n:           %c\n", n);

    char ch2 = 66;

    printf("Zweites Zeichen: %c\n", ch2);

    printf("Zweites Zeichen: %d\n", ch2);

    printf("Drittes Zeichen: %c\n", 1234);

    // ASCII-Tabelle auf der Konsole ausgeben
    for (int i = 32; i <= 127; ++i) {

        printf("i: %3d == ch: %c\n", i, i);
    }

    // Anhang:

    char special1 = '\n';
    char special2 = '\t';
    char special3 = '\r';
    char special4 = '\\';
}

// ====================================================

void test_zeichen_kette()
{
    // a) konstante Zeichenkette - per Definition inklusive terminierende Null am Ende
    printf("%s\n", "ABCDEF");

    // b) Mit Zeiger / Adresse
    const char* cp = "UVWXYZ";
    printf("%s\n", cp);

    // c) Feld von Zeichen
    char s1[] = "123456";
    printf("%s\n", s1);

    // d) Feld von Zeichen
    // char s2[6] = "654321";   // hier wird auf Grund von 6 das letzte Zeichen weggelassen / abgeschnitten
    char s2[7] = "654321";      //
    printf("%s\n", s2);

    // e) Feld von Zeichen
    char s3[] = { '1', '2', '3', '4', '5', '6', '\0' };
    printf("%s\n", s3);

    // f) Feld von Zeichen
    char s4[20] = "654321\0";
    printf("%s\n", s4);

    // g) Feld von Zeichen
    char s5[20] = "12345\\ABC";
    printf("%s\n", s5);
}

// ===============================================================

// "ABC" ==> 3
int length1(const char* cp)
{
    int offset = 0;

    // pointer arithmetic
    while ( *(cp + offset) != '\0' ) {
        ++offset;
    }

    return offset;
}

int length2(char kette[])   // Länge: Da muss eine 0 am Ende drin sein 
{
    int index = 0;

    while ( kette[index] != '\0' ) {
        ++index;
    }

    return index;
}

int length3(const char* cp)
{
    int offset = 0;

    // Array - Schreibweise // Syntax
    while ( cp[offset] != '\0'  ) {
        ++offset;
    }

    // Pointer Arithmetic Schreibweise // Syntax
    while ( *(cp + offset)  != '\0') {
        ++offset;
    }

    return offset;
}

void test_length2()
{
    int len1 = length1("123");
    int len2 = length2("123");
    int len3 = length3("123");
}

// ===========================================

void toUpper(char* s)
{
    int offset = 0;

    while ( s[offset] != '\0' ) {

        if (s[offset] >= 0x61 && s[offset] < 0x7b) {

            s[offset] = s[offset] - 0x20;
        }

        ++offset;
    }
}

void test_toUpper()
{
    char zeichen[] = "123abcdexyz789";
    printf("vorher:  %s\n", zeichen);

    toUpper(zeichen);

    toUpper(zeichen);
    printf("nachher: %s\n", zeichen);
}
