#include <stdio.h> 
int add(int a, int b) { return a + b; } 

int main(void) {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    
   if (num > 0) printf("positive\n");
   else printf("non-positive\n");
   
  for (int i = 1; i <= 5; i++) {
       printf("%d\n", i);
       }
       
      printf("add(3,4) = %d\n", add(3,4));
      
     return 0;
}

