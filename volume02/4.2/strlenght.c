#include <stdio.h>


int string_length01(const char *str)
{
    int i;
    i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

int string_length02(const char *str)
{
    int i;
    for (i = 0; str[i]; i++)
        {}
    return i;
}

int string_length03(const char *str)
{
    const char *p;
    p = str;
    while(*p)
        p++;
    return p - str;
}

int main()
{
    int str1, str2, str3;
    str1 = string_length01("hello");
    printf("Str1 length: %d\n", str1);
    str2 = string_length02("hellohello");
    printf("Str1 length: %d\n", str2);
    str3 = string_length03("hello");
    printf("Str1 length: %d\n", str3);
}