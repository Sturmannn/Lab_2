#ifndef __FUNCTIONS_H__
#define	__FUNCTIONS_H__

//Сортировки
void bubble_sort(unsigned char* mas, int size);
void insert_sort(unsigned char* mas, int size);
void quick_sort(unsigned char* mas, int left, int right);

void firstNorma(unsigned char* mas, int size); // Первая норма вектора
void secondNorma(unsigned char* mas, int size);
void pNorma(unsigned char* mas, int size, double p); // Норма вектора Гёльдера
void infNorma(unsigned char* mas, int size); // Бесконечная норма вектора
void normirovka(unsigned char* mas, int size); // Нормировка массива

#endif

