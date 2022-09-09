#include <stdio.h>

struct X {
    char a;
    double b;
    short c;
    char d;
};

#define offsetof(TYPE, field) (&(((TYPE *)0)->field))

#define add 1+2

//((TYPE *)0)->a

int main() {

    printf("offset of a: %ld\n", offsetof(struct X, a));
    printf("offset of b: %ld\n", offsetof(struct X, b));
    printf("offset of c: %ld\n", offsetof(struct X, c));
    printf("offset of d: %ld\n", offsetof(struct X, d));

    return 0;
}

// Output:
// offset of a: 0
// offset of b: 8
// offset of c: 16
// offset of d: 18