#include <stdio.h>
#include "myarrfunc.h"
int main() {
int n = 0;
int ok = 0;
char ch;
printf("Введите размер массива: ");
while (scanf("%d", &n) != 1 || n <= 0) {
  printf("ERR\n");
  while (getchar() != '\n') {}
  printf("Введите размер массива: ");
}
while(getchar() != '\n') {}
int arr[n];
while(1) {
  printf("a - изменить размер массива\n");
  printf("b - заполнить массив\n");
  printf("c - показать массив и адреса\n");
  printf("d - минимум на отрезке k-m\n");
  printf("e - разница max и min\n");
  printf("f - индексы элементов меньше k\n");
  printf("g - выход\n");
  printf("выбор: ");
scanf(" %c", &ch);
while (getchar() != '\n') {}
if(ch == 'g') {
  break;
}
switch(ch) {
  case 'a': {
    int newn;
    printf("Введите новый размер: ");
    if (scanf("%d", &newn) != 1 || newn <= 0 || newn > n) {
      printf("ERR\n");
      while (getchar() != '\n') {}
      break;
    }
    while(getchar() != '\n') {}
    n = newn;
    ok = 0;
    break;
  }
  case 'b':
    for (int i = 0; i < n; i++) {
      printf("arr[%d] = ", i);
      if (scanf("%d", arr + i) != 1) {
        printf("ERR\n");
        while (getchar() != '\n') {}
        i--;
      }
      else {
	while (getchar() != '\n') {}
      }
    }
    ok = 1;
    break;
  case 'c':
    if (ok == 0) {
      printf("Массив пустой\n");
      break;
    }
    for (int i = 0; i < n; i++) {
      printf("%d: %d (%p)\n", i, *(arr + i), arr + i);
    }
    break;
  case 'd': {
    if (ok == 0) {
      printf("Массив пустой\n");
      break;
    }
    int k, m;
    printf("Введите k и m: ");
    if (scanf("%d %d", &k, &m) != 2) {
      printf("ERR\n");
      while (getchar() != '\n') {}
      break;
    }
    while (getchar() != '\n') {}
    findmin(arr, n, k, m);
    break;
  }
  case 'e': {
    if (ok == 0) {
      printf("Массив пустой\n");
      break;
    }
    int k, m;
    printf("Введите k и m: ");
    if (scanf("%d %d", &k, &m) != 2) {
      printf("ERR\n");
      while (getchar() != '\n') {}
      break;
    }
    while(getchar() != '\n') {}
    finddif(arr, n, k, m);
    break;
  }
  case 'f': {
    if (ok == 0) {
      printf("Массив пустой\n");
      break;
    }
    int k;
    printf("Введите k: ");
    if (scanf("%d", &k) != 1) {
      printf("ERR\n");
      while (getchar() != '\n') {}
      break;
    }
    while (getchar() != '\n') {}
    findbel(arr, n, k);
    break;
  }
default:
  printf("ERR\n");
}
}
return 0;
}
