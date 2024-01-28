#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int factor1;
    int factor2;
} Factors;

Factors factorize(int n) {
    Factors result = {0, 0};

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            result.factor1 = i;
            result.factor2 = n / i;
            break;
        }
    }

    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (!file) {
        perror("Error opening file");
        return 1;
    }

    int number;
    while (fscanf(file, "%d", &number) != EOF) {
        Factors factors = factorize(number);
        if (factors.factor1 != 0 && factors.factor2 != 0) {
            printf("%d=%d*%d\n", number, factors.factor1, factors.factor2);
        }
    }

    fclose(file);
    return 0;
}

