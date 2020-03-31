/*
ID: cbach122
LANG: C
TASK: gift1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lookup_name(char *name, char **givers, int num_givers) {
    for(int i = 0; i < num_givers; i++) {
        int result = strncmp(name, givers[i], 14);
        if(result == 0) return i;
    }
    return -1;
}

int main() {
    char *givers[10];
    int num_givers;

    FILE *fin = fopen("gift1.in", "r");
    fscanf(fin, "%d", &num_givers);

    for(int i = 0; i < num_givers; i++) {
        char *name = malloc(sizeof(char) * 14);
        fscanf(fin, "%s", name);
        givers[i] = name;
    }

    int accounts[14];
    for(int i = 0; i < 14; i++) accounts[i] = 0;

    for(int i = 0; i < num_givers; i++) {
        int total, num_receive;

        char giver_name[14];
        fscanf(fin, "%s", giver_name); // process name
        fscanf(fin, "%d %d", &total, &num_receive);

        if(total == 0 || num_receive == 0) continue;

        int amt = total / num_receive;
        int extra = total % num_receive;

        int acc_num = lookup_name(giver_name, givers, num_givers);
        accounts[acc_num] -= total;
        accounts[acc_num] += extra;

        for(int j = 0; j < num_receive; j++) {
            char *name = malloc(sizeof(char) * 14);
            fscanf(fin, "%s", name);
            int account_num = lookup_name(name, givers, num_givers);
            accounts[account_num] += amt;
            free(name);
        }
    }

    FILE *fout = fopen("gift1.out", "w");
    for(int i = 0; i < num_givers; i++) {
        int acc_num = lookup_name(givers[i], givers, num_givers);
        fprintf(fout, "%s %d\n", givers[i], accounts[acc_num]);
    }

    return 0;
}

