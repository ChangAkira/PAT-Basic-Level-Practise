// 1033 旧键盘打字
#define bool int
#define true 1
#define false 0

#include <stdio.h>
#include <string.h>

bool searchInUValidKeys(char isUVaildKeys[], char input) {
    int len = strlen(isUVaildKeys);
    for (int i = 0; i < len; i++) {
        if (isUVaildKeys[i] == input) {
            return true;
        }
    }
    return false;
}

bool isValidInput(char isUValidKeys[], char input, bool couldShift) {
    if (couldShift == false && (input >= 'A' && input <= 'Z')) {
        return false;
    }
    if (input >= 'a' && input <= 'z') {
        input = input - 32;
    }
    if (searchInUValidKeys(isUValidKeys, input)) {
        return false;
    } else {
        return true;
    }
}
int main() {
    char isUValidKeys[45];
    bool couldShift = 1;
    char input;
    int outPutCnt = 0;
    char temp;
    int cnt = 0;
    while (1) { // scanf会把最后一个\n留在缓冲区，而且如果没有坏掉的键，会把第二行当成坏键，如果用scanf("%s\n")那%s又会把空行的\n给吃掉
        temp = getchar();
        if (temp == '\n') {
            isUValidKeys[cnt] = '\0';
            break;
        } else {
            isUValidKeys[cnt] = temp;
            cnt++;
        }
    }
    if (searchInUValidKeys(isUValidKeys, '+')) {
        couldShift = 0;
    }
    while (1) {
        input = getchar();
        if (input == '\n') {
            break;
        } else {
            if (isValidInput(isUValidKeys, input, couldShift)) {
                printf("%c", input);
                outPutCnt++;
            }
        }
    }
    if (outPutCnt == 0) {
        printf("\n");
    }
    return 0;
}