#define _CRT_SECURE_NO_WARNINGS
/*2. �������
�������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ��� ���� �ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�

���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����

����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��



ʾ�� 1��


���룺l1 = [2, 4, 3], l2 = [5, 6, 4]
�����[7, 0, 8]
���ͣ�342 + 465 = 807.
ʾ�� 2��

���룺l1 = [0], l2 = [0]
�����[0]
ʾ�� 3��

���룺l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9]
�����[8, 9, 9, 9, 0, 0, 0, 1]


��ʾ��

ÿ�������еĽڵ����ڷ�Χ[1, 100] ��
0 <= Node.val <= 9
��Ŀ���ݱ�֤�б��ʾ�����ֲ���ǰ����*/
#include<iostream>
#include"head.h"
int main()
{
	//List One
	ListNode* L1 = new ListNode;
	ListNode* L2 = new ListNode;
	ListNode* L3 = new ListNode;
	ListNode* L7= new ListNode;
	ListNode* L8 = new ListNode;
	ListNode* L9 = new ListNode;
	ListNode* L10 = new ListNode;

	//List Tow
	ListNode* L4 = new ListNode;
	ListNode* L5 = new ListNode;
	ListNode* L6 = new ListNode;
	ListNode* L11 = new ListNode;



	L1->val = 9;
	L2->val = 9;
	L3->val = 9;
	L7->val = 9;
	L8->val = 9;
	L9->val = 9;
	L10->val = 9;
	L1->next = L2;
	L2->next = L3;
	L3->next = L7;
	L7->next = L8;
	L8->next = L9;
	L9->next = L10;
	

	L4->val = 9;
	L5->val = 9;
	L6->val = 9;
	L11->val = 9;
	L4->next=L5;
	L5->next=L6;
	L6->next =L11;
	//����Ϊ��������д��

	Solution So;
	ListNode* Print=So.addTwoNumbers(L1, L4);
	while (Print!=nullptr)
	{
		std:: cout << Print->val<<" ";
		Print = Print->next;
	}

}
//��������
//9 9 9 9 9 9 9
//9 9 9 9
