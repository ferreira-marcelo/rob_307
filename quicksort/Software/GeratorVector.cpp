#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (){
    int n = 100000000;
    int max = 100000000;
    FILE * pFile;
    pFile = fopen ("data.txt","w");
    if (pFile == NULL) perror ("Error opening file");
    else{
        printf("creating elements...\n");
        fprintf(pFile, "%d\n", n);

        int i = 0;
        int random;
        for (i=0;i<n;i++){
            fprintf (pFile, "%d\n", rand() % max);
        }
        printf("finished create Elements\n");
    }
    fclose (pFile);

    return 0;
}
