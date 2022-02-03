#include <stdio.h>

int main() {
    int c;

    c = getchar();
    while (c != EOF) {
        if (c == '\n')
            printf("OK\n");
        c = getchar();
    }
    return 0;
}