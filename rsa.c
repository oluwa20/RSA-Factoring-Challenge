#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

void factorize_rsa(mpz_t n) {
    mpz_t p, q;
    mpz_inits(p, q, NULL);

    mpz_set_ui(p, 2);

    // Try to find a factor using Pollard's rho algorithm
    while (mpz_cmp_ui(p, 1000000) < 0) {
        mpz_mod(q, n, p);
        if (mpz_cmp_ui(q, 0) == 0) {
            // Found a factor
            mpz_divexact(q, n, p);
            gmp_printf("%Zd=%Zd*%Zd\n", n, p, q);
            break;
        }
        mpz_nextprime(p, p);
    }

    mpz_clears(p, q, NULL);
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

    mpz_t n;
    mpz_init(n);

    // Read the RSA number from the file
    if (mpz_inp_str(n, file, 10) == 0) {
        perror("Error reading RSA number from file");
        mpz_clear(n);
        fclose(file);
        return 1;
    }

    factorize_rsa(n);

    mpz_clear(n);
    fclose(file);
    return 0;
}

