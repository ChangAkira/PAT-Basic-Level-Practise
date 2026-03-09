// 1036 跟奥巴马一起编程
#include <math.h>
#include <stdio.h>
int main() {
    int cnt;
    char c;
    scanf("%d %c", &cnt, &c);
    int cnt_2 = round(cnt / 2.0);
    if (cnt == 1) {
        printf("%c", c);
        return 0;
    }
    if (cnt == 0) {
        return 0;
    }
    for (int i = 0; i < cnt; i++) {
        printf("%c", c);
    }
    printf("\n");
    for (int i = 0; i < cnt_2 - 2; i++) {
        printf("%c", c);
        for (int j = 0; j < cnt - 2; j++) {
            printf(" ");
        }
        printf("%c\n", c);
    }
    for (int i = 0; i < cnt; i++) {
        printf("%c", c);
    }
    return 0;
}