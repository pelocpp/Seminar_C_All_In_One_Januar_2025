// =================
// DynamicIntArray.h

struct dynamicIntArray
{
    int*   m_data;
    size_t m_length;
};

typedef struct dynamicIntArray DynamicIntArray;

int  initDynamicIntArray    (DynamicIntArray* array, size_t length);
void printDynamicIntArray   (DynamicIntArray* array);
void fillDynamicIntArray    (DynamicIntArray* array, int value);
void releaseDynamicIntArray (DynamicIntArray* array);
void set                    (DynamicIntArray* array, int index, int value);
int  resizeDynamicIntArray  (DynamicIntArray* array, int newLength);