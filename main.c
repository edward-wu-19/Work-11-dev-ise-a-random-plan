#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

unsigned int generate_int(int bytes);

int main() {
    printf("\n");
    unsigned int arr[10];
    // unsigned int x;
    // x = generate_int(10);
    // printf("%u\n", x);

    int i;
    printf("Generating random numbers...\n\n");
    for (i = 0; i < 10; i++){
        arr[i] = generate_int(10);
    }

    printf("Printing random numbers...\n");
    for (i = 0; i < 10; i++){
        printf("\trandom %d: %u\n", i, arr[i]);
    }

    printf("\nWriting numbers to file...\n");
    int goo = open("./something", O_RDWR | O_CREAT, 0003);
    int gr = write(goo, arr, sizeof(arr));

    printf("\nReading numbers from file...\n");
    unsigned int arr2[10];
    int unt = open("./something", O_RDONLY);
    int len2 = read(unt, arr2, sizeof(arr2));
    arr2[len2] = '\0';

    printf("\nVerifying numbers...\n");
    for (i = 0; i < 10; i++){
        printf("\trandom %d: %u\n", i, arr2[i]);
    }

    return 0;
}

unsigned int generate_int(int bytes){

    unsigned int *a = (unsigned int *) calloc(1, sizeof(unsigned int));
    
    int foo = open("/dev/random", O_RDONLY);
    
    int len = read(foo, a, bytes);

    a[len] = '\0';

    return *a;
}
