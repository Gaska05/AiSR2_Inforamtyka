#include <stdio.h>
#include <stdlib.h>
#include <time.h>
main()
{
    int i, aSize;
    int * randomNums;
    time_t t;
    int biggest, smallest;
    srand(time(&t));
    printf("Podaj dolny prog licz pseudolosywuch\n ");
    scanf(" %d", &smallest);
    printf("Podaj gorny prog licz pseudolosywuch\n ");
    scanf(" %d", &biggest);

    randomNums = (int *) malloc(sizeof(int));
while(1) {

    printf("Ile liczb losowych chcesz zapisac w tablicy?\n ");
    scanf(" %d", &aSize);

    if (aSize == 0) {
        break;
    }
    randomNums = (int *) realloc(randomNums, aSize * sizeof(int));
    for (i = 0; i < aSize; i++) {
        randomNums[i] = (rand() % (biggest - smallest + 1)) + smallest;
    }


    for (i = 0; i < aSize; i++) {
        printf("%d\n", randomNums[i]);
    }
}
    free(randomNums);
    return(0);
}