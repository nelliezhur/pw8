#include <stdio.h>
#include "myarrfunc.h"
void findmin(int *arr, int n, int k, int m) {
  if (k < 0 || m >=n || k > m) {
    printf("ERR\n");
    return;
  }
  int min = *(arr + k);
  for (int i = k + 1; i <= m; i++) {
    if (*(arr + i) < min) {
      min = *(arr + i);
    }
  }
  printf("Минимальный элемент [%d...%d]: %d\n", k, m, min);
}
void finddif(int *arr, int n, int k, int m) {
  if (k < 0 || m >= n ||  k > m) {
    printf("ERR\n");
    return;
  }
  int min = *(arr + k);
  int max = *(arr + k);
  for (int i = k + 1; i <= m; i++) {
    if (*(arr + i) < min) {
      min = *(arr + i);
    }
    if (*(arr + i) > max) {
      max = *(arr + i);
    }
  }
  printf("Разница между max и min [%d...%d]: %d\n", k, m, max - min);
}
void findbel(int *arr, int n, int k) {
  int count = 0;
  printf("Индексы элементов меньше %d: ", k);
  for (int i = 0; i < n; i++) {
    if (*(arr + i) < k) {
      printf("%d ", i);
      count++;
    }
  }
  if(count == 0) {
    printf("Таких элементов нет");
  }
  printf("\n");
}
