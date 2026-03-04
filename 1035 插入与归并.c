// 1035 插入与归并
// 思考可以想到，当发现在某个位置是降序时，后面的数字如果都跟原来的顺序一致，那就是插入排序，如果不一致，那就是归并排序
// 总结：归并排序是全范围排，插入排序是从前到后排的
// 因为呢会涉及插入，所以我选择链表，这样插入的时间复杂度小。但是呢还要判断当前与输入的中间序列是否一致，这个时间复杂度是
// O(n)，但这个就算换别的数据结构也是一样的，顶多写起来简单实际上时间复杂度是一样的（比如用strcmp时）


#define bool int
#define true 1
#define false 0
#define NO_MORE_SPACES -1
#define ElementType int
#define SortType int
#define Insertion_Sort 1
#define Merge_Sort 2

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *prior;
    ElementType elem;
    struct Node *next;
} Node;

bool addNElem(Node *tailNode, int n) { // 尾插法加入n个元素
    for (int i = 0; i < n; i++) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->prior = tailNode;
        scanf("%d", &newNode->elem);
        newNode->next = NULL;
        tailNode->next = newNode;
        tailNode = newNode;
    }
    return true;
}

bool printChainList(Node *headNode) {
    Node *printNode = headNode->next;
    while (printNode != NULL) {
        printf("%d", printNode->elem);
        if (printNode->next != NULL) {
            printf(" ");
        }
        printNode = printNode->next;
    }
    return true;
}

bool isSame(Node *node1, Node *node2) {
    while (node1 != NULL) {
        if (node1->elem == node2->elem) {
            node1 = node1->next;
            node2 = node2->next;
            continue;
        } else {
            return false;
        }
    }
    return true;
}

SortType judgeSortType(Node *headNode1, Node *headNode2) { // 升序排列、都是正整数，那头结点的0参与进来也无妨
    Node *node1 = headNode1;
    Node *node2 = headNode2;
    while (node2 != NULL&&node2->next!=NULL) {
        if (node2->next->elem >= node2->elem) {
            node2 = node2->next;
            node1 = node1->next;
        } else {
            node2 = node2->next;
            node1 = node1->next;
            break;
        }
    }
    if (isSame(node1, node2)) {
        return Insertion_Sort;
    } else {
        return Merge_Sort;
    }
}

bool insertToList(Node *a1,Node *a2){//把a1插到a2的前面

}

bool insertionSort(Node *headnode,  Node *nodeptr) {//进行一次插入排序。要知道是要对哪个元素下手

}
bool mergeSort(Node *headNode) {

}

int main() {
    Node headNode1 = {NULL, 0, NULL};
    Node *tailNode1 = &headNode1;
    int cnt;
    scanf("%d", &cnt);
    addNElem(tailNode1, cnt);
    // printChainList(&headNode1);
    Node headNode2 = {NULL, 0, NULL};
    Node *tailNode2 = &headNode2;
    addNElem(tailNode2, cnt);

    if (judgeSortType(&headNode1, &headNode2) == Insertion_Sort) {
        printf("Insertion Sort\n");
        insertionSort(&headNode1);
    } else {
        printf("Merge Sort\n");
        while (!isSame(&headNode1, &headNode2)) {
            mergeSort(&headNode1);
        }
        mergeSort(&headNode1);
    }

    printChainList(&headNode1);

    return 0;
}