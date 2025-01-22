#include <stdio.h>
#include <string.h>

// Strukturen

struct Person
{
    char vorname[50];
    char nachname[50];

    int age;
};

struct time
{
    int hours;
    int minutes;
    int seconds;
};

typedef struct time Time;

static void testStruktur_01()
{
    // Vorbelegung einer Struktur Variablen

    Time t1;                // that's bad

    Time t2 = { 1, 2, 3 };  // die Werte werden DER REIHE NACH
                                   // den Variablen in der Struktur zugewiesen

                                   // designated initializer syntax
                                   // 
    Time t3 = { .minutes = 1, .hours = 2, .seconds = 3 };

    Time t4 = { .minutes = 0 };

    Time t5 = { 0 };

    Time t6 = { 123 };
}

static void testStruktur_02()
{
    Time now = { 0 };

    now.hours = 9;
    now.minutes = 52;
    now.seconds = 0;

    printf("Aktuelle Uhrzeit: %02d:%02d:%02d", now.hours, now.minutes, now.seconds);
}

static void printTime(const Time* t) {      // Call-by-Address

    printf("Uhrzeit: %02d:%02d:%02d\n", t->hours, t->minutes, t->seconds);
}

static void resetTimeBad(Time t) {   // Call-by-Value

    t.hours = 0;
    t.minutes = 0;
    t.seconds = 0;
}

static void resetTime(Time* t) {    // Call-by-Address

    //t.hours = 0;
    //t.minutes = 0;
    //t.seconds = 0;

    //(*t).hours = 0;
    //(*t).minutes = 0;
    //(*t).seconds = 0;

    t->hours = 0;
    t->minutes = 0;
    t->seconds = 0;
}


static Time emptyTime() { 

    Time empty = { 0 };

    return empty;
}

static void testStruktur_03()
{
    Time now = { 0 };

    now.hours = 9;
    now.minutes = 52;
    now.seconds = 0;

    printTime(&now);

    resetTime(&now);

    printTime(&now);
}

static void testStruktur_04()
{
    Time t = emptyTime();

    printTime(&t);
}

void testStruktur()
{
    testStruktur_04();
}
