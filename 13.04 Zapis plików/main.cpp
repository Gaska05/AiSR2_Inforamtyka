#include <stdio.h>
#include <stdlib.h>
FILE * fptr;
int main() {
    fptr = fopen("plik.txt", "a");
    if (fptr == 0) {
        printf("Blad otwierania pliku!\n");
        exit(1);
    }
    fprintf(fptr, "\nNapis dodawany na koncu pliku.\n");
    fclose(fptr);
    return (0);

}