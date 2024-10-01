#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

void QuickSort(int a[], int left, int right) {
    int L = left, R = right;
    int temp;
    int pivot = a[(left + right) / 2];

    while (L <= R) {
        while (a[L] < pivot) {
            L++;
        }
        while (a[R] > pivot) {
            R--;
        }
        if (L <= R) {
            if (L != R) {
                temp = a[L];
                a[L] = a[R];
                a[R] = temp;
            }
            L++;
            R--;
        }
    }
    if (left < R) {
        QuickSort(a, left, R);
    }
    if (L < right) {
        QuickSort(a, L, right);
    }
}
int main() {
    // 난수 생성을 위한 시드 설정 (42로 고정)
    srand(42);

    // 난수 생성 범위 및 개수 설정
    int min = 1;
    int max = 1000000;
    int num_random_numbers = MAX_SIZE;

    // 10000개의 난수를 저장할 배열 선언
    int random_numbers[MAX_SIZE];

    // 난수 10000개 생성하여 배열에 저장
    for (int i = 0; i < num_random_numbers; i++) {
        random_numbers[i] = (rand() % (max - min + 1)) + min;
    }
    QuickSort(random_numbers, 0, num_random_numbers - 1);

    printf("3274번 째 크기를 가지는 정수 : %d\n", random_numbers[3273]);

    return 0;
}
