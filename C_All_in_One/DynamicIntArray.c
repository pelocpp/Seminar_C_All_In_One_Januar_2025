// =================
// DynamicIntArray.c

#include <stdio.h>
#include <stdlib.h>

#include "DynamicIntArray.h"

static void test_DynamicIntArray_01()
{
    DynamicIntArray dia = { .m_data = NULL, .m_length = 0 };

    initDynamicIntArray(&dia, 10);
    printDynamicIntArray(&dia);
    fillDynamicIntArray(&dia, 10);
    printDynamicIntArray(&dia);

    // dia.m_data[999] = 123;
    set(&dia, 999, 123);
    set(&dia, 5, 20);
    printDynamicIntArray(&dia);

    resizeDynamicIntArray(&dia, 20); 


    releaseDynamicIntArray(&dia);

    DynamicIntArray empty = { .m_data = NULL, .m_length = 0 };
    releaseDynamicIntArray(&empty);
}


static void test_DynamicIntArray_02()
{
    DynamicIntArray dia = { .m_data = NULL, .m_length = 0 };

    initDynamicIntArray(&dia, 10);
    fillDynamicIntArray(&dia, 1);
    printDynamicIntArray(&dia);

    resizeDynamicIntArray(&dia, 20);
    printDynamicIntArray(&dia);

    resizeDynamicIntArray(&dia, 12);
    printDynamicIntArray(&dia);

    resizeDynamicIntArray(&dia, 5);
    printDynamicIntArray(&dia);

    releaseDynamicIntArray(&dia);
}






void test_DynamicIntArray()
{
    test_DynamicIntArray_02();
}

int initDynamicIntArray(DynamicIntArray* array, size_t length)
{
    array->m_data = calloc(length, sizeof(int));

    if (array->m_data == NULL) {
        printf("Out of memory");
        exit(1);
    }
    else {
        array->m_length = length;
        return 1;
    }
}

void releaseDynamicIntArray(DynamicIntArray* array)
{
    free(array->m_data);
}

void printDynamicIntArray(DynamicIntArray* array)
{
    printf("{ ");

    for (int i = 0; i < array->m_length; ++i) {
        printf("%d ", array->m_data[i]);
    }

    printf("}\n");
}

void fillDynamicIntArray(DynamicIntArray* array, int value)
{
    for (int i = 0; i < array->m_length; ++i) {
        array->m_data[i] = value;
    }
}

void set(DynamicIntArray* array, int index, int value)
{
    if (index >= 0 && index < array->m_length ) {
        array->m_data[index] = value;
    }
    else {
        printf("Wrong index: %d\n", index);
    }
}

int resizeDynamicIntArray(DynamicIntArray* array, int newLength)
{
    // allocate new buffer
    int* tmp = calloc(newLength, sizeof (int));
    if (tmp == NULL) {
        exit(1);
        return 0;
    }

    // compute count of values to copy
    size_t count = 0;
    if (newLength >= array->m_length) {
        count = array->m_length;
    }
    else {
        count = newLength;
    }

    // copy current buffer into new one
    for (int i = 0; i < count; ++i) {
        tmp[i] = array->m_data[i];
    }

    // delete 'old' buffer
    free(array->m_data);

    // switch to new buffer and adjust length
    array->m_data = tmp;
    array->m_length = newLength;

    return 1;
}