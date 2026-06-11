#include "tablica.h"
#include <iostream>
#include <stdio.h>

void tab1(int tab[], int size) {
    for (int *ptr = tab; ptr < tab + size; ptr++) {
        printf("%d ", *ptr);
    }

    printf("\n");
}

int printMin(int tab[], int size) {
    int min = *tab;
    for (int *ptr = tab; ptr < tab + size; ptr++) {
        if (*ptr < min) min = *ptr;
    }
    return min;
}

int printMax(int tab[], int size) {
    int max = *tab;
    for (int *ptr = tab; ptr < tab + size; ptr++) {
        if (*ptr > max) max = *ptr;
    }
    return max;
}

int SumTab(int tab[], int size) {
    int sum = 0;
    for (int *ptr = tab; ptr < tab + size; ptr++) {
        sum += *ptr;
    }
    return sum;
}

float AvarageTab(int tab[], int size) {
    float sum = 0;
    for (int *ptr = tab; ptr < tab + size; ptr++) {
        sum += *ptr;
    }
    return sum / size;
}

void fillTab(int tab[], int size) {
    printf("Wprowadz %d nowych wartosci do tablicy:\n", size);
    for (int *ptr = tab; ptr < tab + size; ptr++) {
        printf("Podaj wartosc: ");
        std::cin >> *ptr;
    }
}


void saveToFile(int tab[], int size) {
    FILE *fptr;
    fptr = fopen("dane.txt", "w");

    if (fptr == 0) {
        printf("Blad zapisu pliku.\n");
        return;
    }


    for (int *ptr = tab; ptr < tab + size; ptr++) {
        fprintf(fptr, "%d\n", *ptr);
    }

    fclose(fptr);
    printf("Tablica zostala zapisana do pliku 'dane.txt'.\n");
}


void loadFromFile(int tab[], int size) {
    FILE *fptr;

    fptr = fopen("dane.txt", "r");

    if (fptr == 0) {
        printf("Blad otwierania pliku\n");
        return;
    }


    for (int *ptr = tab; ptr < tab + size; ptr++) {
        if (fscanf(fptr, "%d", ptr) != 1) {
            printf("Ostrzezenie: Plik mial mniej niz %d elementow.\n", size);
            break;
        }
    }

    fclose(fptr);
    printf("Tablica zostala wczytana z pliku 'dane.txt'.\n");
}

void Choose() {
    printf("\n=== MENU ===\n");
    printf("1. Wypisz zawartosc tablicy\n");
    printf("2. Znajdz wartosc minimalna\n");
    printf("3. Znajdz wartosc maksymalna\n");
    printf("4. Oblicz sume elementow\n");
    printf("5. Oblicz srednia\n");
    printf("6. Wprowadz dane do tablicy tablicy\n");
    printf("7. Zapisz tablice do pliku (dane.txt)\n");
    printf("8. Wczytaj tablice z pliku (dane.txt)\n");
    printf("0. Wyjscie \n");
    printf("Wybierz opcje: ");
}