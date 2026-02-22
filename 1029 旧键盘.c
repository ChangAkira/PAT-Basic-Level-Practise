// 1029 旧键盘
// 明显哈希表
// 我们顺序就按照A-Z 0-9 _ 顺序，共37个。
// 如果逐字母比对肯定会出问题的，说不定会乱套。不如用两个哈希表，最后进行比较
// 等会儿，输出的时候要用发现顺序输出，反正然后经过一点点思考，发现一个哈希表就够了，存实际输入的字符
// 其实大概直接ascll就行了？

#include <stdio.h>
#include <string.h>

int main() {
    char a[85];
    char b[85];
    int d[37] = {0};
    scanf("%s", a);
    scanf("%s", b);
    int lena = strlen(a);
    int lenb = strlen(b);
    for (int i = 0; i < lenb; i++) {
        if ((b[i] >= 'A' && b[i] <= 'Z') || (b[i] >= 'a' && b[i] <= 'z')) {
            if (b[i] >= 'a' && b[i] <= 'z') {
                b[i] = b[i] + ('A' - 'a');
            }
            d[b[i] - 'A'] = 1;
        } else if (b[i] >= '0' && b[i] <= '9') {
            d[b[i] - '0' + 26] = 1;
        } else if (b[i] == '_') {
            d[36] = 1;
        } else {
            ;
        }
    }

    for (int i = 0; i < lena; i++) {
        if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z')) {
            if (a[i] >= 'a' && a[i] <= 'z') {
                a[i] = a[i] + ('A' - 'a');
            }
            if (d[a[i] - 'A'] != 1) {
                printf("%c", a[i]);
                d[a[i] - 'A'] = 1;
            }
        } else if (a[i] >= '0' && a[i] <= '9') {
            if (d[a[i] - '0' + 26] != 1) {
                printf("%c", a[i]);
                d[a[i] - '0' + 26] = 1;
            }
        } else if (a[i] == '_') {
            if (d[36] != 1) {
                printf("%c", a[i]);
                d[36] = 1;
            }
        } else {
            ;
        }
    }

    return 0;
}