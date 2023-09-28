#include <stdio.h>
#include <stdlib.h>

unsigned long long strtoull(const char *nptr, char **endptr, int base);

int is_prime(unsigned long long num) {
    if (num <= 1) {
        return 0;
    }
    if (num <= 3) {
        return 1;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return 0;
    }
    for (unsigned long long i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

void factorize(unsigned long long n, unsigned long long *p, unsigned long long *q) {
    *p = 0;
    *q = 0;

    for (unsigned long long i = 2; i <= n / 2; ++i) {
        if (is_prime(i) && n % i == 0) {
            *p = i;
            *q = n / i;
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        unsigned long long n = strtoull(line, NULL, 10);
        unsigned long long p, q;
        factorize(n, &p, &q);

        printf("%llu=%llu*%llu\n", n, p, q);
    }

    fclose(file);
    return 0;
}
