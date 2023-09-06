#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compute (a^b) mod p
long long int power(long long int a, long long int b, long long int p) {
    if (b == 1)
        return a;
    else
        return (((long long int)pow(a, b)) % p);
}

int main() {
    long long int p, g, a, b, x, y, ka, kb; 
    
    // Both the persons will be agreed upon the public keys G and P 
    printf("Enter the value of p (prime number): ");
    scanf("%lld", &p); 

    printf("Enter the value of g (primitive root of p): ");
    scanf("%lld", &g); 
  
    // Alice will choose the private key a 
    printf("Enter the value of a (Alice's private key): ");
    scanf("%lld", &a); 
    x = power(g, a, p); // gets the generated key 
  
    // Bob will choose the private key b 
    printf("Enter the value of b (Bob's private key): ");
    scanf("%lld", &b); 
    y = power(g, b, p); // gets the generated key 
  
    // Generating the secret key after the exchange of keys 
    ka = power(y, a, p); // Secret key for Alice 
    kb = power(x, b, p); // Secret key for Bob 
  
    printf("Secret key for Alice: %lld\n", ka);
    printf("Secret key for Bob: %lld\n", kb);
  
    return 0;
}
