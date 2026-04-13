#include <stdio.h>
#include <string.h>

#define EMPTY -1

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int table[m];
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    for (int q = 0; q < n; q++) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            int base = key % m;
            int inserted = 0;
            for (int i = 0; i < m; i++) {
                int pos = (base + i * i) % m;
                if (table[pos] == EMPTY) {
                    table[pos] = key;
                    inserted = 1;
                    break;
                }
            }
            // If table is full, insertion silently fails
        } 
        else if (strcmp(op, "SEARCH") == 0) {
            int base = key % m;
            int found = 0;
            for (int i = 0; i < m; i++) {
                int pos = (base + i * i) % m;
                if (table[pos] == key) {
                    found = 1;
                    break;
                }
                if (table[pos] == EMPTY) {
                    break; // stop early if empty slot encountered
                }
            }
            if (found) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }

    return 0;
}
