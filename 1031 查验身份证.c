// 1031 查验身份证
#define bool int
#define true 1
#define false 0

#include <stdio.h>
#include <string.h>

bool isValidFunc(char ID[], int weights[], char isValid[]) {
    int len;
    if ((len = strlen(ID)) != 18)
        return false;
    int sumWeight = 0;
    for (int i = 0; i < 17; i++) {
        if(ID[i]<'0'||ID[i]>'9'){
            return false;
        }
        sumWeight += (ID[i] - '0') * weights[i];
    }
    if (isValid[sumWeight % 11] != ID[17]) {
        return false;
    } else {
        return true;
    }
}

int main() {
    int weights[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char isValid[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int nValidCnt = 0;
    char temp[20];
    int cnt = 0;
    scanf("%d",&cnt);
    for (int i = 0; i < cnt; i++) {
        scanf("%s", temp);
        if (!isValidFunc(temp, weights, isValid)) {
            printf("%s\n", temp);
            nValidCnt++;
        }
    }
    if (nValidCnt == 0) {
        printf("All passed");
    }
    return 0;
}