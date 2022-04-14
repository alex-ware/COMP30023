#include <stdio.h>
#include <arpa/inet.h>

int main() {
    char a[4];
    int *b = (void*)a;
    short int *c = (void*)a;

    *b = htonl (1);
    printf("*b %d  *c %d\n", *b, *c);

    *b = htonl (65536);
    printf("*b %d  *c %d\n", *b, *c);
}