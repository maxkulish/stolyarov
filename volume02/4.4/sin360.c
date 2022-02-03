#include <stdio.h>
#include <math.h>

int main()
{
    FILE *f;
    int grad;

    f = fopen("sincons.txt", "w");
    if (!f) {
        perror("sincos.txt");
        return 1;
    }

    for (grad = 0; grad < 360; grad++) {
        double rads, s, c;
        rads = (double)grad * M_PI / 180.0;
        s = sin(rads);
        c = cos(rads);

        fprintf(f, "%03d % 7.5f % 7.5f\n", grad, s, c);
    }
    fclose(f);
    return 0;
}

void intfilesum(FILE *f, int *sum, int *count)
{
    int n;
    *count = 0;
    *sum = 0;
    while (fscanf(f, "%d", &n) == 1) {
        *sum += n;
        (*count)++;
    }
}