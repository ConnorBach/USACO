/*
ID: cbach122
LANG: C
TASK: ride 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fin = fopen("ride.in", "r");

    char comet1[8];
    char comet2[8];

    fscanf(fin, "%s %s", comet1, comet2);
    fclose(fin);

    int prod1 = 1, prod2 = 1;

    for(int i = 0; i < strnlen(comet1, 8); i++) {
        prod1 *= comet1[i] - 64;
    }
    
    for(int i = 0; i < strnlen(comet2, 8); i++) {
        prod2 *= comet2[i] - 64;
    }

    prod1 %= 47;
    prod2 %= 47;

    FILE *fout = fopen("ride.out", "w");
    if(prod1 == prod2) {
        fprintf(fout, "GO\n");
    } else {
        fprintf(fout, "STAY\n");
    }

    return 0;
}
