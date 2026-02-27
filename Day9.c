#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%s", str);   // read string (no spaces)

    int len = strlen(str);

    // Print characters in reverse order
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}
