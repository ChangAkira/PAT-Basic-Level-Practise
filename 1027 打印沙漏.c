// 1027 打印沙漏
// 我想，应该先求出来打印几层，然后框框一打印
//写着写着又把自己给绕进去了……

void printFunc(int cntTotal, char a, int cnt) { // cntTotal表示一共的层数，cnt表示现在是第几层(或者倒数第几层cnt2)
    int cnt2 = cnt >= (cntTotal / 2 + 1) ? cntTotal - cnt + 1 : cnt;
    for (int i = 1; i < cnt2; i++) {
        printf(" ");
    }
    // 可以发现一共有几层，第一层就会打印几个符号
    for (int i = 0; i < cntTotal - 2 * (cnt2 - 1); i++) {
        printf("%c", a);
    }
    printf("\n");
    if (cnt == cntTotal) {
        return;
    }
    printFunc(cntTotal, a, cnt + 1);
    return;
}

int cntNum(int n,int* nUsed) {
    int i;
    n--;
    (*nUsed)++;
    for (i = 1; n >= 0; i++) {
        n = n - 2*(2 * (i) + 1);
        (*nUsed)+=2*(2 * (i) + 1);
    }
    (*nUsed)-=2*(2 * (i-1) + 1);
    return i-1;
}

int main() {
    char a;
    int n;
    int nUsed=0;
    scanf("%d %c", &n, &a);
    int cntTotal = 2*cntNum(n,&nUsed)-1;
    printFunc(cntTotal, a, 1);
    printf("%d",n-nUsed);
    return 0;
}