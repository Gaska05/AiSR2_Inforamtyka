#include <iostream>
#include <stdio.h>
#include "tablica.h"


int main() {
    int myTab[SIZE] = {12, 5, 8, 1, 9, 23, 7, 4, -3, 10};
    int opcja;

    do {
        Choose();
        std::cin >> opcja;

        switch(opcja) {
            case 1:
                printf("Elementy tablicy: \n");
                tab1(myTab, SIZE);
                break;
            case 2:
                printf("Najmniejsza wartosc: %d\n", printMin(myTab, SIZE));
                break;
            case 3:
                printf("Najwieksza wartosc: %d\n", printMax(myTab, SIZE));
                break;
            case 4:
                printf("Suma elementow: %d\n", SumTab(myTab, SIZE));
                break;
            case 5:
                printf("Srednia wartosc: %.2f\n", AvarageTab(myTab, SIZE));
                break;
            case 6:
                fillTab(myTab, SIZE);
                printf("Tablica zostala zaktualizowana pomyslnie.\n");
                break;
            case 7:
                saveToFile(myTab, SIZE);
                break;
            case 8:
                loadFromFile(myTab, SIZE);
                break;
            case 0:
                printf("Zamykanie programu...\n");
                break;
            default:
                printf("Nieprawidlowa opcja.\n");
        }
    } while (opcja != 0);

    return 0;
}