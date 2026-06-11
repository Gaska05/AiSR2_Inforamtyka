#include <iostream>
#define SIZE 10

int main(){
    printf("Prosty kalkulator\n");
    float number1, number2;
    printf("Podaj pierwsza liczbe\n");
    scanf("%f", &number1);
    printf("Podaj druga liczbe\n");
    scanf("%f", &number2);

    printf("Dodawanie\n");
    printf("%.2f + %.2f = %.2f\n", number1, number2, number1 + number2);
    printf("Odejmowanie\n");
    printf("%.2f - %.2f = %.2f\n", number1, number2, number1 - number2);
    printf("Mnozenie\n");
    printf("%.2f * %.2f = %.2f\n", number1, number2, number1 * number2);
    printf("Dzielenie\n");
    printf("%.2f / %.2f = %.2f\n", number1, number2, number1 / number2);

    int tab[SIZE] = {45, 12, 89, 3, 56, 28, 91, 15, 74, 33};

    printf("Wartosci w tablicy: \n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n\n");

    int min = tab[0];
    int max = tab[0];
    float sum = 0;

    for (int i = 0; i < SIZE; i++) {
        if (tab[i] < min) min = tab[i];
        if (tab[i] > max) max = tab[i];
        sum += tab[i];
    }

    printf("Minimum: %d\n", min);
    printf("Maksimum: %d\n", max);
    printf("Suma: %.2f\n", sum);
    printf("Srednia: %.2f\n\n", sum / SIZE);

    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }

    printf("Tablica po sortowaniu:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    float median;
    if (SIZE % 2 == 0) {
        median = (tab[SIZE / 2 - 1] + tab[SIZE / 2]) / 2.0;
    } else {
        median = tab[SIZE / 2];
    }

    printf("Mediana: %.2f\n", median);

    return 0;
}