/* match.c */
#include <stdio.h>


int starmatch(const char *str, const char *pat);
int match(const char *str, const char *pat)
{
    for (;; str++, pat++) {
        switch (*pat) {
            case 0:
                return *str == 0;
            case '*':
                return starmatch(str, pat+1);
            case '?':
                if (!*str)
                    return 0;
                break;
            default:
                if (*str != *pat)
                    return 0;
        }
    }
}

int starmatch(const char *str, const char *pat)
{
    int i;
    for (i=0; ; i++) {
        int res = match(str+i, pat+1);
        if (res)
            return 1;
        if (!str[i])
            return 0;
    }
}

int main(int argc, char **argv)
{
    if (argc < 3) {
        fprintf(stderr, "No string given\n");
        return 1;
    }
    
    return match(argv[1], argv[2]);
}