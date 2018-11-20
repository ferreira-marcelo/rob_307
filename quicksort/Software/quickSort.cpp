
// An iterative implementation of quick sort
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

typedef struct vector {

    int* elements;
    int size;

} Vector;

Vector* createVector (const char* nameFile){
    Vector* newVector;
    newVector = (Vector*) malloc (sizeof(Vector));

    string line;
    FILE * pFile;
    pFile = fopen (nameFile,"r");
    if (pFile == NULL) perror ("Error opening file");
    else{
        if (! feof (pFile)){
            fscanf (pFile, "%d", &newVector->size);

            newVector->elements = (int*) malloc (newVector->size*sizeof(int));
            int i = 0;
            for (i=0;i<newVector->size;i++){
                if (! feof (pFile))
                    fscanf (pFile, "%d", &newVector->elements[i]);
            }
        }
        fclose (pFile);
    }

    return newVector;
}

// A utility function to swap two elements
void swap ( int* a, int* b )
{
    //printf("swap start...\n");
    int t = *a;
    *a = *b;
    *b = t;
    //printf("swap finished.\n");
}

/* This function is same in both iterative and recursive*/
int partition (int arr[], int l, int h)
{
    //printf("patition start...\n");
    int x = arr[h];
    int i = (l - 1);

    for (int j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    //printf("patition fisished.\n");
    return (i + 1);
}

/* A[] --> Array to be sorted,
   l  --> Starting index,
   h  --> Ending index */
void quickSortIterative (int arr[], int l, int h)
{
    // Create an auxiliary stack
    int* stack;
    stack = (int*) malloc ((h - l + 1)*sizeof(int));

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[ ++top ] = l;
    stack[ ++top ] = h;

    // Keep popping from stack while is not empty
    while ( top >= 0 )
    {
        // Pop h and l
        h = stack[ top-- ];
        l = stack[ top-- ];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition( arr, l, h );

        // If there are elements on left side of pivot,
        // then push left side to stack
        if ( p-1 > l )
        {
            stack[ ++top ] = l;
            stack[ ++top ] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if ( p+1 < h )
        {
            stack[ ++top ] = p + 1;
            stack[ ++top ] = h;
        }
    }
    free (stack);
}

// A utility function to print contents of arr
void printArr( int arr[], int n )
{
    int i;
    for ( i = 0; i < n; ++i )
        printf( "%d ", arr[i] );
}

// Driver program to test above functions
int main()
{
    double readTime;
    double calculTime;
    clock_t readStopTime;
    clock_t readStartTime;
    clock_t calculStopTime;
    clock_t calculStartTime;

    readStartTime = clock();

    Vector* vec;
    printf("reading...\n");
    vec = createVector("data.txt");
    printf("reade done\n");

    printf("sorting...\n");

    calculStartTime = clock();
    quickSortIterative(vec->elements,0,vec->size-1);
    calculStopTime = clock();

    readStopTime = clock();
    printf("sort done\n");
    //printVector(vec);

    calculTime = (calculStopTime - calculStartTime) / (CLOCKS_PER_SEC / (double) 1000.0);
    readTime = (readStopTime - readStartTime) / (CLOCKS_PER_SEC / (double) 1000.0);
    printf("Size of vector: %d\n",vec->size);
    printf("Time of calcul: %f\n",calculTime);
    printf("Clocks of calcul: %f\n", (double)(calculStopTime - calculStartTime));
    printf("Time total: %f\n",readTime);
    printf("Clocks total: %f\n", (double)(readStopTime - readStartTime));

    free(vec->elements);
    free(vec);

    return 0;
}
