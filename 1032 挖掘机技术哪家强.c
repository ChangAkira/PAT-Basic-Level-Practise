// 1032 挖掘机技术哪家强
#include <stdio.h>

int scores[100005] = {};

int main() {
    int cnt;
    int temp;
    int index;
    int max = 0;
    int maxIndex = 0;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++) {
        scanf("%d%d", &index, &temp);
        scores[index] += temp;
        if (scores[index] >= max) {
            max = scores[index];
            maxIndex = index;
        }
    }
    printf("%d %d", maxIndex, max);
    return 0;
}