#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "Functions.h"


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Rus");
    int n, min, max, input;
    bool flag = 0;
    unsigned char* mas;
    unsigned char* arr;
    FILE* file;
    fopen_s(&file, "..\\text_file.txt", "r");
    fscanf_s(file, "%d\n", &n);
    fscanf_s(file, "%d %d\n", &min, &max);
    mas = (int*)malloc(n * sizeof(int));
    arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        fscanf_s(file, "%d\n", &mas[i]);
    memcpy(arr, mas, n * sizeof(unsigned char));

reset: printf("У вас есть массив! Что вы хотите сделать?\n1) Распечатать неотсортированный массив\n2) Сортировать массив по возрастанию (не убыванию)\n3) Работа с массивом(Вычисление нормировок)\n4) Выход из программы\nВыбор: ");
    do {
        if (flag == 0 && argc > 1 && argv[1][0] >= '1' && argv[1][0] <= '4') sscanf_s(argv[1], "%d", &input);
        else scanf_s("%d", &input);
        switch (input) {
        case 1:
            for (int i = 0; i < n; i++) printf("arr[%d] = %d\n", i, arr[i]);
            system("pause");
        case 2:
            system("CLS");
            printf("Какой вариант сортировки вы хотите использовать?\n1) Сортировка пузырьком\n2) Сортировка вставками\n3) Быстрая сортировка (Хоара)\n4) Вернуться назад\nВыбор: ");
            do {
                if (flag == 0 && argc > 2 && argv[2][0] >= '1' && argv[2][0] <= '4') sscanf_s(argv[2], "%d", &input);
                else scanf_s("%d", &input);
                flag = 1;
                switch (input) {
                case 1:
                    system("CLS");
                    clock_t b_time = clock();
                    bubble_sort(mas, n);
                    clock_t e_time = clock() - b_time;
                    printf("Сортировка массива пузырьком...\n");
                    for (int i = 0; i < n; i++) printf("mas[%d] = %d\n", i, mas[i]);
                    printf("Сортировка заняла %g сек.\n", (double)e_time / CLOCKS_PER_SEC);
                    system("pause");
                    system("CLS");
                    goto reset;
                case 2:
                    system("CLS");
                    b_time = clock();
                    insert_sort(mas, n);
                    e_time = clock() - b_time;
                    printf("Сортировка массива вставками...\n");
                    for (int i = 0; i < n; i++) printf("mas[%d] = %d\n", i, mas[i]);
                    printf("Сортировка заняла %g сек.\n", (double)e_time / CLOCKS_PER_SEC);
                    system("pause");
                    system("CLS");
                    goto reset;
                case 3:
                    system("CLS");
                    b_time = clock();
                    quick_sort(mas, 0, n - 1);
                    e_time = clock() - b_time;
                    printf("Сортировка массива методом Хоара(быстрая)...\n");
                    for (int i = 0; i < n; i++) printf("mas[%d] = %d\n", i, mas[i]);
                    printf("Сортировка заняла %g сек.\n", (double)e_time / CLOCKS_PER_SEC);
                    system("pause");
                    system("CLS");
                    goto reset;
                case 4:
                    system("CLS");
                    goto reset;
                default:
                    printf("Вы ввели неверные значения, попробуйте заново!\n");
                }
            } while (input < 1 || input > 4);
        case 3:
            system("CLS");
            printf("1) Вычислить первую норму вектора\n2) Вычислить вторую норму вектора\n3) Вычислить норму вектора Гёльдера\n4) Вычислить бесконечную норму вектора\n5) Вычислить нормировку вектора\nВыбор: ");
            do {
                scanf_s("%d", &input);
                switch (input) {
                case 1:
                    system("CLS");
                    firstNorma(mas, n);
                    system("pause");
                    system("CLS");
                    goto reset;
                case 2:
                    system("CLS");
                    secondNorma(mas, n);
                    system("pause");
                    system("CLS");
                    goto reset;
                case 3:
                    system("CLS");
                    pNorma(arr, n, 1.0);
                    system("pause");
                    system("CLS");
                    goto reset;
                case 4:
                    system("CLS");
                    infNorma(mas, n);
                    system("pause");
                    system("CLS");
                    goto reset;
                case 5:
                    system("CLS");
                    normirovka(arr, n);
                    system("pause");
                    system("CLS");
                    goto reset;
                default:
                    printf("Вы ввели неверные значения, попробуйте заново!\n");
                }
            } while (input < 1 || input > 4);
        case 4:
            break;
        default:
            printf("Вы ввели неверные значения, попробуйте заново!\n");
        }
    } while (input < 1 || input > 4);
    free(mas);
    free(arr);
    return 0;
}