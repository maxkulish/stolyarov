#include <stdio.h>

void string50(FILE *f1, FILE *f2)
{
    char buf[51];
    while (fgets(buf, sizeof(buf), f1)) {
        int i;
        int nlpos = -1;
        for (i = 0; i < sizeof(buf) && buf[i]; i++)
            if (buf[i] == '\n') {
                nlpos = i;
                break;
            }
        if (nlpos == -1) {
            int c;
            fputc('\n', f2);
            while((c = fgetc(f1)) != EOF)
                if (c == '\n')
                    break;
        } else {
            buf[nlpos] = '\0';
            fprintf(f2, "[%s]\n", buf);
        }
    }
}

int main(int argc, char **argv)
{
    if (argc < 3) {
        fprintf(stderr, "Too few arguments\n");
        return 1;
    }

    FILE *from, *to;
    from = fopen(argv[1], "r");
    if (!from) {
        perror(argv[1]);
        return 2;
    }

    to = fopen(argv[2], "w");
    if (!to) {
        perror(argv[2]);
        return 3;
    }

    string50(from, to);
}