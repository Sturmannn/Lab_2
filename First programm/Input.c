#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void create_mas(int n, int min, int max, unsigned char** mas) {
    int i = 0;
    *mas = (unsigned char**)malloc(n * sizeof(unsigned char*));
    for (i = 0; i < n; i++) 
        (*mas)[i] = rand() * 1.0 / RAND_MAX * (max - min) + min;
}

void gen_range(int *n, int *min, int *max){
    do {
        printf("Введите количество чисел, которые вы хотите сгенерировать:\n");
        scanf_s("%d", n);
        printf("Введите минимальное число диапазона:\n");
        scanf_s("%d", min);
        printf("Введите максимальное число диапазона:\n");
        scanf_s("%d", max);
        if (*min > *max || *n <= 0 || *min < 0 || *max < 0) {
            system("CLS");
            printf("Вы неправильно задали значения, повторите снова!\n\n");
        }
    } while ((*min > *max) || (*n <= 0) || (*min < 0) || (*max < 0));
}

void print_mas(FILE* f, int n, unsigned char* mas) {
    int i = 0;
    for (i = 0; i < n; i++) fprintf(f, "%d\n", mas[i]);
}

int main()
{
    int i, n, min, max, input;
    unsigned char* mas = 0;
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    FILE* file1 = 0;
    FILE* file2 = 0;
    fopen_s(&file1, "..\\text_file.txt", "w");
    
    do {
        printf("Как вы хотите заполнить массив:\n1) Сгенерировать случайным образом\n2) Считать из файла\n3) Задать значения вручную (с клавиатуры)\nВыбор: ");
        input = getch();
        printf("%d\n", input - '0');
               
        switch (input) {
        case '1':
            gen_range(&n, &min, &max);
            fprintf(file1, "%d\n%d %d\n", n, min, max);
            create_mas(n, min, max, &mas);
            print_mas(file1, n, mas);
            fclose(file1);
            break;
        case '2':
            fopen_s(&file2, "..\\scanf.txt", "r");
            fscanf_s(file2, "%d\n%d", &n, &min);
            fscanf_s(file2, "%d\n", &max);
            fprintf(file1, "%d\n%d %d\n", n, min, max);
            mas = (unsigned char*)malloc(n * sizeof(unsigned char));
            for (i = 0; i < n; i++) fscanf_s(file2, "%d\n", &mas[i]);
            print_mas(file1, n, mas);
            fclose(file1);
            fclose(file2);
            break;
        case '3':
            gen_range(&n, &min, &max);
            mas = (unsigned char*)malloc(n * sizeof(unsigned char));
            printf("Введите значения:\n");
            for (i = 0; i < n; i++) {
                scanf_s("%d", &mas[i]);
                if (mas[i] < min || mas[i] > max) {
                    printf("Вы ввели значение не из нужного диапазона, перепишите число\n");
                    i -= 1;
                }
            }
            fprintf(file1, "%d\n%d %d\n", n, min, max);
            print_mas(file1, n, mas);
            break;
        default:
            system("CLS");
            printf("Вы неправильно задали значения, повторите снова!\n\n");
        }
    } while (input > '3' && input < '1');
    return 0;
}