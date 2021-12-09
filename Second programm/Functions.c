#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void bubble_sort(unsigned char* mas, int size) { // Сортировка пузырьком
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            if (mas[j] < mas[i]) {
                int tmp = mas[j];
                mas[j] = mas[i];
                mas[i] = tmp;
            }
}

void insert_sort(unsigned char* mas, int size) { // Сортировка вставками
    for (int i = 1; i < size; i++) {
        int k = i;
        while (k > 0 && mas[k - 1] > mas[k]) {
            int tmp = mas[k - 1];
            mas[k - 1] = mas[k];
            mas[k] = tmp;
            k -= 1;
        }
    }
}

void quick_sort(unsigned char* mas, int left, int right) { // Быстрая сортировка(Хоара)
    int i = left, j = right;
    int sr = mas[(left + right) / 2];
    int tmp;
    while (i <= j) {
        while (mas[i] < sr) i++;
        while (mas[j] > sr) j--;
        if (i <= j) {
            tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j) quick_sort(mas, left, j);
    if (right > i) quick_sort(mas, i, right);
}

void firstNorma(unsigned char* mas, int size)
{
    int i = 0, sum = 0;
    for (i = 0; i < size; i++) sum += mas[i];
    for (i = 0; i < size; i++) printf("%d\n", sum);
}

void secondNorma(unsigned char* mas, int size)
{
    int i = 0, sum = 0;
    for (i = 0; i < size; i++) sum += pow(mas[i], 2);
    printf("Результат вычисления второй нормы вектора: %g\n", sqrt(sum));
}

void pNorma(unsigned char* mas, int size, double p)
{
    int i = 0, x = 0;

    for (i = 0; i < size; i++) x += pow(fabs(mas[i]), p);
    printf("Результат вычисления первой нормы вектора: %g\n", pow(x, 1.0 / p));
}

void infNorma(unsigned char* mas, int size)
{
    int i = 0;
    unsigned char max = 0;

    for (i = 0; i < size; i++) if (mas[i] > max) max = mas[i];
    printf("Результат вычисления бесконечной нормы вектора: %d\n", max);
}

void normirovka(unsigned char* mas, int size)
{
    int i = 0;
    double x = 0;
    for (i = 0; i < size; i++) x += pow(mas[i], 2);

    x = round(sqrt(x));

    for (i = 0; i < size; i++) printf("%d / %g --> %g\n", mas[i], x, mas[i] * 1.0 / x);
}

