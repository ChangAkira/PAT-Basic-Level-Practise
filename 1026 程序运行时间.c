// 1026 程序运行时间
// 没得说

#include <stdio.h>
#include<math.h>
int main() {
    float a = 0, b = 0;
    scanf("%f%f", &a, &b);
    int c = round((b - a) / 100);
    int d = c / 3600;
    int e = (c - d * 3600) / 60;
    int f = c - d * 3600 - e * 60;
    printf("%02d:%02d:%02d\n", d, e, f);
    return 0;
}