// 1030 完美数列
// 有点像是贪心？来简单分析一下
// 倍数p是固定的，那么选中一个最小值，最大值也是半固定的
// 感觉直接遍历？有点懵懵的
// 是啊，就直接遍历就好了
// 直接双重遍历有一个测试点会超时。问了AI，原来是滑动窗口、双指针，这个以前还没写过但是练完感觉可以懂的

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int *num1 = (int *)a;
    int *num2 = (int *)b;
    if (*num1 > *num2)
        return 1; // 从小到大排
    if (*num1 == *num2)
        return 0;
    if (*num1 < *num2)
        return -1;
}

int main() {
    int cnt, p;
    scanf("%d%d", &cnt, &p);
    int nums[100000];
    for (int i = 0; i < cnt; i++) {
        scanf("%d", &nums[i]);
    }
    qsort(nums, cnt, sizeof(int), compare);
    int min;
    long long max;
    int thisCnt = 0, lastCnt = 0;
    int j = 0;
    for (int i = 0; i < cnt; i++) {
        min = nums[i];
        max = (long long)nums[i] * p; // 这里不用long long的话最后一个测试点会通不过（溢出变成负数了）
        for (; j < cnt && nums[j] <= max; j++, thisCnt++)
            ; // j接着往后数就行了，不用回头找i
        if (thisCnt >= lastCnt)
            lastCnt = thisCnt;
        thisCnt--; // 前面min往前了一个
        // 另外其实不需要thisCnt，因为 j 是右边界（不包含在内），i 是左边界，所以当前合法的数字个数永远等于 j - i
    }
    printf("%d", lastCnt);
    return 0;
}