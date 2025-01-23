// ===========================================================================
// jaggedArrays.c // jagged Arrays
// ===========================================================================

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>   // malloc, free
#include <crtdbg.h>

#include <stdio.h>    // printf
#include <time.h>     // time

// Jagged Arrays am STACK
// Jagged Arrays am HEAP

static void jagged_arrays_01()
{
    char array1[] = "Dies";
    char array2[] = "ist";
    char array3[] = "eine";
    char array4[] = "Zeile";

    char* jaggedArray[4] = { array1 , array2 , array3 , array4 };

    for (int i = 0; i < 4; ++i) {
        printf("%d: %s\n", i, jaggedArray[i]);
    }
}

static void jagged_arrays_02()
{
    // Beobachtung: Die Dimension des Jagged Arrays ist fest // hier: 4

    int array1[3] = { 1, 2, 3 };
    int array2[1] = { 1 };
    int array3[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int array4[5] = { 1, 2, 3, 4, 5 };

    int* jaggedArray[4] = { array1 , array2 , array3 , array4 };

    int sizes[4] = { 3, 1, 9, 5 };

    for (int i = 0; i < 4; ++i) {

        for (int k = 0; k < sizes[i]; ++k) {
            printf("%d: %d    ", k, jaggedArray[i][k]);
        }
        printf("\n");
    }
}

int getZufallszahl(int untereGrenze, int obereGrenze)
{
    // zwischen untereGrenze und obereGrenze
    int zufall = rand();
    zufall = (zufall % (obereGrenze - untereGrenze)) + untereGrenze;
    // printf("Zufall: %d\n", zufall);
    return zufall;
}

static void jagged_arrays_03()
{
    // allocate jagged array
    int lengthArray = getZufallszahl(5, 10);
    int** jaggedArray = calloc(lengthArray, sizeof(int*));

    // need array of sizes
    int* sizes = calloc(lengthArray, sizeof(int));

    // fill jagged array with dynamically allocated arrays
    for (int i = 0; i < lengthArray; ++i) {

        // allocate a row
        int lengthRow = getZufallszahl(1, 10);
        int* row = calloc(lengthRow, sizeof(int));

        // initialize this row
        for (int k = 0; k < lengthRow; ++k) {
            row[k] = i;
        }

        // add length of this row into sizes array
        sizes[i] = lengthRow;

        // add row address into jagged array - array of addresses of int arrays
        jaggedArray[i] = row;
    }

    // print jagged array
    for (int i = 0; i < lengthArray; ++i) {

        for (int k = 0; k < sizes[i]; ++k) {
            printf("%3d", jaggedArray[i][k]);
        }
        printf("\n");
    }
}

static void createJaggedArray(int* length, int** sizes, int*** array)
{
    // allocate jagged array
    int lengthArray = getZufallszahl(5, 10);
    int** jaggedArray = calloc(lengthArray, sizeof(int*));

    // need array of sizes
    int* rowLengths = calloc(lengthArray, sizeof(int));

    // fill jagged array with dynamically allocated arrays
    for (int i = 0; i < lengthArray; ++i) {

        // allocate a row
        int lengthRow = getZufallszahl(1, 10);
        int* row = calloc(lengthRow, sizeof(int));

        // initialize this row
        for (int k = 0; k < lengthRow; ++k) {
            row[k] = i;
        }

        // add length of this row into sizes array
        rowLengths[i] = lengthRow;

        // add row address into jagged array - array of addresses of int arrays
        jaggedArray[i] = row;
    }

    // copy values and addresses to caller
    *length = lengthArray;
    *sizes = rowLengths;
    *array = jaggedArray;
}

static void printJaggedArray(int lengthArray, int* sizes, int** jaggedArray)
{
    // print jagged array
    for (int i = 0; i < lengthArray; ++i) {

        for (int k = 0; k < sizes[i]; ++k) {
            printf("%3d", jaggedArray[i][k]);
        }
        printf("\n");
    }
}

static void releaseJaggedArray(int lengthArray, int* sizes, int** jaggedArray)
{
    // release at first each row
    for (int i = 0; i < lengthArray; ++i) {
        free(jaggedArray[i]);
    }

    // release array of sizes
    free(sizes);

    // release jagged array itself
    free(jaggedArray);
}

static void jagged_arrays_04()
{
    int length = 0;
    int* sizes = NULL;
    int** array = NULL;

    createJaggedArray(&length, &sizes, &array);

    printJaggedArray(length, sizes, array);

    releaseJaggedArray(length, sizes, array);
}

void main_jaggedArrays()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // set seed
    srand((unsigned int)time(NULL) * 1000);

    //jagged_arrays_01();
    //jagged_arrays_02();
    //jagged_arrays_03();
    jagged_arrays_04();
}

