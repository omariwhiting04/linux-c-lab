#include <stdio.h>
#include <string.h>

int main(void){
    FILE *file = fopen("output.txt", "w");
    if (!file){ perror("fopen"); return 1; }
    fprintf(file, "Text\n");
    fclose(file);
    printf("Wrote output.txt\n");
    return 0;
}
