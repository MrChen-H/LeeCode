#define _CRT_SECURE_NO_WARNINGS
/*2. 两数相加
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。



示例 1：


输入：l1 = [2, 4, 3], l2 = [5, 6, 4]
输出：[7, 0, 8]
解释：342 + 465 = 807.
示例 2：

输入：l1 = [0], l2 = [0]
输出：[0]
示例 3：

输入：l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9]
输出：[8, 9, 9, 9, 0, 0, 0, 1]


提示：

每个链表中的节点数在范围[1, 100] 内
0 <= Node.val <= 9
题目数据保证列表表示的数字不含前导零*/
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
	//以上为测试用例写法

	Solution So;
	ListNode* Print=So.addTwoNumbers(L1, L4);
	while (Print!=nullptr)
	{
		std:: cout << Print->val<<" ";
		Print = Print->next;
	}

}
//测试用例
//9 9 9 9 9 9 9
//9 9 9 9
