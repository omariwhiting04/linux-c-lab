#include <stdio.h> 

long long fact(int n) {
     if (n <= 1) return 1;
     return (long long)n * fact(n-1);
     }

     int main (void) {
     int n; 
     printf("Enter n: ");
     scanf("%d", &n);
     if (n < 0) {
          printf("Factorial underfined for negatives.\n");
          return 1;
         } 
        printf("fact(%d) = %lld\n", n, fact(n));
        return 0;
        } 
     
