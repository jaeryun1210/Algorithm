#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

void selection(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_num = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_num]) {
                min_num = j;
            }
        }
        if (min_num != i) {
            int temp = a[i];
            a[i] = a[min_num];
            a[min_num] = temp;
        }
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

    selection(random_numbers, num_random_numbers);

    printf("3274번 째 크기를 가지는 정수 : %d\n", random_numbers[3273]);

    return 0;
}
