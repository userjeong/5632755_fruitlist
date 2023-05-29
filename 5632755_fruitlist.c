#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char name[100];
}element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value);
void error(char* message);
ListNode* insert(ListNode* head, ListNode* pre, element value);
ListNode* delete_first(ListNode* head);
ListNode* delete(ListNode* head, ListNode* pre);
void print_list(ListNode* head);

ListNode* concat_list(ListNode* head1, ListNode* head2);
ListNode* reverse(ListNode* head);

int main(void)

{
	ListNode* head = NULL;
	element data;
	strcpy(data.name, "Mango");
	head = insert_first(head, data);
	strcpy(data.name, "Orange");
	head = insert_first(head, data);
	strcpy(data.name, "Apple");
	head = insert_first(head, data);
	strcpy(data.name, "Grape");
	head = insert_first(head, data);
	strcpy(data.name, "Cherry");
	head = insert_first(head, data);
	strcpy(data.name, "Plum");
	head = insert_first(head, data);
	strcpy(data.name, "Guava");
	head = insert_first(head, data);
	strcpy(data.name, "Raspberry");
	head = insert_first(head, data);
	strcpy(data.name, "Banana");
	head = insert_first(head, data);
	strcpy(data.name, "Peach");
	head = insert_first(head, data);

	int num;
	while (1)
	{
		printf("\n========�޴�========\n");
		printf("[1] ���ο� ������ �Է��մϴ�.\n");
		printf("[2] ������ �����մϴ�.\n");
		printf("[3] ������ ���� ����� ����մϴ�.\n");
		printf("[4] ���α׷��� �����մϴ�.\n");
		print_list(head);
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			printf("�߰��� ���� �̸��� �Է��ϼ���.");
			break;
		case 2:
			printf("������ ���� �̸��� �Է��ϼ���.");
			break;
		case 3:
			print_list(head);
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("�߸��� ��ȣ�Դϴ�. �޴��� �ٽ� Ȯ�����ּ���.\n");
			
		}
	}

}

ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}


ListNode* concat_list(ListNode* head1, ListNode* head2)
{
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		ListNode* p = head1;
		while (p->link != NULL)
		{
			p = p->link;
		}
		p->link = head2;
		return head1;
	}
}

	ListNode* reverse(ListNode * head)
	{
		ListNode*r, *q, *p;
		r= NULL;
		q = NULL;
		p = head;
		while (p != NULL)
		{
			r = p; q = p; p =q ->link;
			q->link = r;

			return q;
		}
	}

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
}

ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;;
	free(removed);
	return head;
}

void print_list(ListNode* head)
{

	ListNode* p;

	for (p = head; p != NULL; p = p->link)
	{
		printf("%s->", p->data.name);
	}
	printf("NULL\n");
}

int is_empty(ListNode* head)
{
	return head == NULL;
}
