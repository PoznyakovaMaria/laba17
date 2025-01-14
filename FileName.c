#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

//������������ �������
int* full_array(int* ptrarr, int n) {
    for (int i = 0; i < n; i++) {
        ptrarr[i] = rand() % 100;
    }
    return ptrarr;
}
//����� �������
void put_array(int* ptrarr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", ptrarr[i]);
    }
    printf("\n");
}
//����������� ����������
void sort_buble(int* ptrarr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (ptrarr[j] > ptrarr[j + 1]) {
                int temp = ptrarr[j];
                ptrarr[j] = ptrarr[j + 1];
                ptrarr[j + 1] = temp;
            }
        }
    }
}
//��������� ����������
void sort_kokteil(int* ptrarr, int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        for (int i = left; i < right; i++) {
            if (ptrarr[i] > ptrarr[i + 1]) {
                int temp = ptrarr[i];
                ptrarr[i] = ptrarr[i + 1];
                ptrarr[i + 1] = temp;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if (ptrarr[i] < ptrarr[i - 1]) {
                int temp = ptrarr[i];
                ptrarr[i] = ptrarr[i - 1];
                ptrarr[i - 1] = temp;
            }
        }
        left++;
    }
}
//���������� ������� �������
void sort_select(int* ptrarr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (ptrarr[j] < ptrarr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = ptrarr[i];
        ptrarr[i] = ptrarr[min_idx];
        ptrarr[min_idx] = temp;
    }
}
//���������� ���������
void sort_insert(int* ptrarr, int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && ptrarr[j - 1] > ptrarr[j]) {
            int temp = ptrarr[j - 1];
            ptrarr[j - 1] = ptrarr[j];
            ptrarr[j] = temp;
            j--;
        }
    }
}
int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    printf("������� ������ �������: ");
    scanf("%d", &n);
    int* ptrarr = (int*)malloc(n * sizeof(int));

    //����� �������
    full_array(ptrarr, n);
    put_array(ptrarr, n);
    clock_t t = clock();
    sort_select(ptrarr, n);
    double time = (double)(clock() - t) / CLOCKS_PER_SEC;

    printf("������:\n");
    put_array(ptrarr, n);
    printf("�����: %.10f \n", time);
    free(ptrarr);
    return 0;
}
