// 1025 反转链表
// 这个一看就有点思路。一个思路是题目说是单链表，但我偷偷用双向链表，反转链表就把prior和next交换一下
// 另一种就是用头插法创建另一个链表，也能反转，这样占用空间比较大
// 因为毕竟题目要单链表，所以这里选择第二种方法
// 等会儿，刚才没仔细看题，这什么玩意儿
// 不需要自己实现单链表吗？不是，题目直接给出了地址，这怎么弄？一个个比对地址是否匹配吗？直接扔进一个大数组里吗？
// 好奇怪的题啊，是我们可以直接操控数据存在哪个虚拟地址中吗？没听说过这种用法啊？
// 估计是扔大数组了

#include <stdio.h>
struct L {
    int data;
    int next;
} List[100000];

int arr[100000] = {0};

void arrswap(int arr[], int i, int swapcnt) {
    int left = i - swapcnt + 1;
    int right = i;
    int temp;
    while (left <= right) {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        right--;
        left++;
    }
}

int main() {
    int base, cnt, swapcnt;
    scanf("%d%d%d", &base, &cnt, &swapcnt);
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < cnt; i++) {
        scanf("%d%d%d", &a, &b, &c);
        List[a].data = b;
        List[a].next = c;
    }

    int cnt2 = 0;
    for (int i = base; i != -1; i = List[i].next, cnt2++) {
        arr[cnt2] = i;
    }
    for (int i = 0, k = 1; i < cnt2; i++, k++) {
        if (k == swapcnt) {
            arrswap(arr, i, swapcnt);
            k = 0;
        }
    }
    for (int i = 0; i < cnt2; i++) {

        if (i != cnt2 - 1) {
            printf("%05d %d %05d", arr[i], List[arr[i]].data, arr[i + 1]);

        } else {
            printf("%05d %d -1", arr[i], List[arr[i]].data);
        }
        printf("\n");
    }
    return 0;
}