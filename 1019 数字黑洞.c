// 我终于又回来做题了
// 1019 数字黑洞     懒得用int还要除10啊乘10啊
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 比较函数，写标准一点
int compare(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}

void swaparr(char arr[], int left, int right) {
    char temp;
    while (left < right) {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

int main() {
    char arr[5] = {};
    int n;//先用 int 读入，这样输入 67 会自动变成 0067，输入 0 会变成 0000
    scanf("%d", &n);
    sprintf(arr, "%04d", n);
    if ((arr[0] == arr[1] && arr[0] == arr[2] && arr[0] == arr[3])) {
        printf("%s - %s = 0000", arr, arr);
        return 0;
    }
    char arr1[5] = {};
    char arr2[5] = {};
    int diff;
    while (1) {
        qsort(arr, 4, sizeof(char), compare);
        strcpy(arr1, arr);
        swaparr(arr1, 0, 3);
        int a = atoi(arr);
        int b = atoi(arr1);
        diff = b - a;
        printf("%s - %s = %04d", arr1, arr, diff);
        if (diff == 6174) {
            break;
        }
        printf("\n");
        sprintf(arr, "%04d", diff);
    }

    return 0;
}