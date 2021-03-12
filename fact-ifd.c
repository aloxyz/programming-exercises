#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    int x = atoi(argv[1]);
    float y = atoi(argv[2]);
    double z = atoi(argv[3]);
    int max = atoi(argv[4]);

    printf("max: %d\n-------", max);

    printf("\nint %d:\n\n", x);
    while(x < max) {
        int tmp = x;
        for(int i = x - 1; i >= 2; i--) {
            tmp *= i;
        }
        printf("%d! = %d\n", x, tmp);
        x++;
    }
    printf("\nfloat %.2f:\n\n", y);
    while(y < max) {
        float tmp = y;
        for(int i = y - 1; i >= 2; i--) {
            tmp *= i;
        }
        printf("%.2f! = %.2f\n", y, tmp);
        y++;
    }
    printf("\ndouble %.4lf:\n\n", z);
    while(z < max) {
        double tmp = z;
        for(int i = z - 1; i >= 2; i--) {
            tmp *= i;
        }
        printf("%.4lf! = %.4lf\n", z, tmp);
        z++;
    }
}
