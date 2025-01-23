// ===========================================
// Header for this Program
// ===========================================

#pragma once

// ===========================================
// global constants
#define   Length    20

// ===========================================
// global variables // external declarations
extern int g_intValue;

// ===========================================
// global data types

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

// ===========================================
// forward / function external declarations

extern void zeiger_demo();
extern void rufemalDreiAuf();
extern void rufemalDreiAufEx();
extern void zeiger_demo_with_pointer_arithmetic();

extern void test_zeichen();
extern void test_zeichen_kette();
extern void test_length2();
extern void test_toUpper();
extern void test_chr_append();

extern void testStruktur();
extern void test_dynamic();
extern void test_global_variables();
extern void test_defines();
extern void mainMultidimensionalArrays();
extern void main_jaggedArrays();
extern void mainUnionsBitfieldsEnums();
extern void test_DynamicIntArray();

// ===========================================
// End-of-File
// ===========================================
