#include <iostream>


#define SIZE 10

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


void Choose() {
    printf("\n=== MENU ===\n");
    printf("1. Wypisz zawartosc tablicy\n");
    printf("2. Znajdz wartosc minimalna\n");
    printf("3. Znajdz wartosc maksymalna\n");
    printf("4. Oblicz sume elementow\n");
    printf("5. Oblicz srednia\n");
    printf("6. Wprowadz wlasne wartosci do tablicy\n"); // Nowa opcja w menu
    printf("0. Wyjscie (Exit)\n");
    printf("Wybierz opcje: ");
}

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
            case 0:
                printf("Zamykanie programu...\n");
                break;
            default:
                printf("Nieprawidlowa opcja! Sprobuj ponownie.\n");
        }
    } while (opcja != 0);

    return 0;
}
