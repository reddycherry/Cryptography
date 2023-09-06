#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Function to compute the greatest common divisor
uint64_t gcd(uint64_t a, uint64_t b) {
    if (!b) return a;
    return gcd(b, a % b);
}

// Function to compute modular exponentiation
uint64_t mod_exp(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    uint64_t p = 61; 
    uint64_t q = 53;
    uint64_t n = p * q;
    uint64_t phi = (p - 1) * (q - 1);

    // Choose an integer e
    uint64_t e;
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1) break;
    }

    // Calculate d
    uint64_t d = 0;
    for (uint64_t i = 2; i < phi; i++) {
        if ((e * i) % phi == 1) {
            d = i;
            break;
        }
    }

    printf("Public Key: (%lu, %lu)\n", e, n);
    printf("Private Key: (%lu, %lu)\n", d, n);

    uint64_t message;
    printf("Enter a numeric message to encrypt (smaller than %lu): ", n);
    scanf("%lu", &message);

    uint64_t ciphertext = mod_exp(message, e, n);
    printf("Original Message: %lu\n", message);
    printf("Encrypted Message: %lu\n", ciphertext);

    uint64_t decrypted_message = mod_exp(ciphertext, d, n);
    printf("Decrypted Message: %lu\n", decrypted_message);

    return 0;
}
