/*
ID: cbach122
LANG: C
TASK: friday
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fin = fopen("friday.in", "r");
    int num_years = 0;
    fscanf(fin, "%d", &num_years);
    fclose(fin);

    int friday13ths[7];
    for(int i = 0; i < 7; i++) friday13ths[i] = 0;

    int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int cur_year = 1900;
    int cur_day = 1; // Monday

    for(int i = cur_year; i < cur_year + num_years; i++) {
        if(i % 100 == 0 && i % 400 == 0) {
            printf("%d (century leap year)\n", i);
            months[1] = 29;
        } else if(i % 100 == 0 && i % 400 != 0) {
            printf("%d (not century leap year)\n", i);
            months[1] = 28;
        } else if (i % 4 == 0) {
            printf("%d (leap year)\n", i);
            months[1] = 29;
        } else {
            months[1] = 28;
        }

        for(int cur_month = 0; cur_month < 12; cur_month++) {
            for(int j = 1; j < months[cur_month]+1; j++) {
                cur_day = (cur_day + 1) % 7;

                if(j == 13) {
                    friday13ths[cur_day] += 1;
                }
            }
        }
    }

    FILE *fout = fopen("friday.out", "w");
    for(int i = 0; i < 7; i++) {
        if(i < 6) {
            fprintf(fout, "%d ", friday13ths[i]);
        } else {
            fprintf(fout, "%d\n", friday13ths[i]);
        }
    }

    return 0;
}

