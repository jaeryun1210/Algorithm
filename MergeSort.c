#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

int sorted[MAX_SIZE];   //임시배열  

void merge(int random_numbers[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    //분할 정렬된 리스트 합병
    while (i <= mid && j <= right) {
        if (random_numbers[i] <= random_numbers[j]) {
            sorted[k++] = random_numbers[i++];
        }
        else {
            sorted[k++] = random_numbers[j++];
        }
    }

    while (i <= mid) {
        sorted[k++] = random_numbers[i++];
    }
    while (j <= right) {
        sorted[k++] = random_numbers[j++];
    }
    
    for (i = left; i <= right; i++) {
        random_numbers[i] = sorted[i];
    }
}

void merge_sort(int random_numbers[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        merge_sort(random_numbers, left, mid);
        merge_sort(random_numbers, mid + 1, right);
        merge(random_numbers, left, mid, right);
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

    merge_sort(random_numbers, 0, num_random_numbers - 1);

    printf("3274번 째 크기를 가지는 정수 : %d\n", random_numbers[3273]);

    return 0;
}
