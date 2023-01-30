/*
给你两个链表 list1 和 list2 ，它们包含的元素分别为 n 个和 m 个。

请你将 list1 中下标从 a 到 b 的全部节点都删除，并将list2 接在被删除节点的位置。

试例:
输入：list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
输出：[0,1,2,1000000,1000001,1000002,5]
解释：我们删除 list1 中下标为 3 和 4 的两个节点，并将 list2 接在该位置。上图中蓝色的边和节点为答案链表。

题目链接:https://leetcode.cn/problems/merge-in-between-linked-lists/description/
*/

#include<iostream>
#include<list>
struct ListNode
{    
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        int index = 0;

        ListNode *ptr_1 = nullptr;
        ListNode *ptr_2 = nullptr;

        ptr_1 = list1;
        

        for (int i = 0; i < a-1; i++)
        {
            ptr_1 = ptr_1->next;    //找到a的位置
        }
        ptr_2 = ptr_1;    //记录当前位置

        for (int i = a - 1; i < b + 1; i++)
        {
            ptr_1 = ptr_1->next;   //找到b的位置
        }
        ptr_2->next = list2;  //在a位置链接list2的头结点

        while (list2->next != nullptr)//使list2移动到链表尾部
        {
            list2 = list2->next;
        }
        list2->next = ptr_1;//list2尾部在list b处链接list1 剩余节点

        return list1;
    }
};

int main()
{
    return 0;
}