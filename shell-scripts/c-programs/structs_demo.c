#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int  age;
};

int main(void){
    struct Person p;
    strcpy(p.name, "Alice");
    p.age = 25;
    printf("%s is %d\n", p.name, p.age);
    return 0;
}
