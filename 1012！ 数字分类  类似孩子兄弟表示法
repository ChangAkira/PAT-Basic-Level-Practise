// 1012 数字分类 
// 这边第一下想到的办法是类似于树的孩子兄弟表示法？不过有一个链表（横向那个）是不需要的，因为确定都是被5除，所以直接开5个就好了不需要用链表实现可变数量
//当然也可以直接读入一个数字立马进行分类，不过这里主要是为了练习数据结构和代码能力，所以下面这样写
//第一次做的时候对数字分类的这个类理解有误，实际上我觉得是题目自己没说清楚

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct node_c {
	int data;
	struct node_c* next;
}node_c;

//我们这里用头插法，这样比较简单
//整个题目写一半了突然发现“按给出顺序进行交错求和”，那还是应该用尾插法，再维护一个tail吧
node_c* insert(node_c* tail, int num) {
	node_c* newnode = (node_c*)malloc(sizeof(node_c));
	newnode->data = num;
	newnode->next = NULL;
	tail->next = newnode;
	return newnode;
}

int main() {

	

	node_c* head0 = (node_c*)malloc(sizeof(node_c));
	node_c* head1 = (node_c*)malloc(sizeof(node_c));
	node_c* head2 = (node_c*)malloc(sizeof(node_c));
	node_c* head3 = (node_c*)malloc(sizeof(node_c));
	node_c* head4 = (node_c*)malloc(sizeof(node_c));

	head0->next = NULL;
	head1->next = NULL;
	head2->next = NULL;
	head3->next = NULL;
	head4->next = NULL;
	node_c* tail0, *tail1, *tail2, *tail3, *tail4;
	tail0 = head0;
	tail1 = head1;
	tail2 = head2;
	tail3 = head3;
	tail4 = head4;

	int i = 0; 
	scanf("%d", &i);
	int num_input;
	for (int j = 0; j < i; j++) {
		scanf("%d", &num_input);
		switch (num_input % 5) {
		case 0:
			if (num_input % 2 == 0) {
				tail0 = insert(tail0, num_input);
			}
			break;
		case 1:
			tail1=insert(tail1, num_input);
			break;
		case 2:
			tail2=insert(tail2, num_input);
			break;
		case 3:
			tail3=insert(tail3, num_input);
			break;
		case 4:
			tail4=insert(tail4, num_input);
			break;
		}
	}
	node_c *printnode=head0->next;
	int print_sum = 0;
	if (head0->next == NULL) {
		printf("N ");
	}
	else {
		for (print_sum = 0; printnode!= NULL;) {
			if (printnode->data % 2 == 0) {
				print_sum += printnode->data;
			}
			printnode = printnode->next;
		}
		printf("%d ", print_sum);
	}
	


	printnode=head1->next;
	if (head1->next == NULL) {
		printf("N ");
	}
	else {
		int flag = 1;
		for (print_sum = 0; printnode!= NULL;) {
			if (flag == 1) {
				print_sum += printnode->data;
			}
			else {
				print_sum -= printnode->data;
			}
			printnode = printnode->next;
			flag = -flag;
		}
		printf("%d ", print_sum);
	}
	

	int count = 0;
	printnode=head2->next;
	if (head2->next == NULL) {
		printf("N ");
	}
	else {
		for (; printnode!= NULL;) {
			count++;
			printnode = printnode->next;
		}
		printf("%d ", count);
	}
	
	
	if (head3->next == NULL) {
		printf("N ");
	}
	else {
		printnode = head3->next;
		for (print_sum = 0, count = 0; printnode!= NULL;) {
			print_sum += printnode->data;
			count++;
			printnode = printnode->next;
		}
		printf("%.1f ", (float)print_sum / count);
	}

	
	
	printnode=head4->next;
	int maxnum = 0;
	if (head4->next == NULL) {
		printf("N");
	}
	else {
		for (; printnode!= NULL;) {
			if (printnode->data >maxnum) {
				maxnum= printnode->data;
			}
			printnode = printnode->next;
		}
		printf("%d", maxnum);
	}
	

	return 0;
}
