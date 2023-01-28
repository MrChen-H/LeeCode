#pragma once
#ifndef HEAD_H_
#define HEAD_H_
struct ListNode//链表节点结构，题目给出 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};
    class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) //需完成的功能函数
        {
            int val = 0;//记录和值进位
            ListNode* New = new ListNode;//返回的链表头节点
            ListNode* ptr = New;//指向头节点的工具指针
            ListNode* Ptr1 = l1;//指向形参L1的工具指针
            ListNode* Ptr2 = l2;//指向形参L2的工具指针
            int sum = 0;//接收两节点和的变量
            while (Ptr1!= nullptr || Ptr2!= nullptr)//两个链表有一个没有遍历结束则继续循环处理
            {
                int Sum;//追踪记录节点和
                if (Ptr1==nullptr||Ptr2==nullptr)//当L1 Or L2 节点遍历结束为空时(处理两表长度不一)
                {
                    if (Ptr2 == nullptr)//当某一链表遍历结束以 0 值填补
                    {
                        sum = Ptr1->val + 0;
                    }
                    else
                    {
                        sum = 0 + Ptr2->val;
                    }
                }
                else//都不为空正常处理
                {
                    sum = Ptr1->val + Ptr2->val;
                }
                Sum = sum;//更新跟踪
                ListNode* newNode = new ListNode;//创建结果链表的需插入节点
                if (sum >= 10)//如果和值大于10
                {
                    sum %= 10;//去除十位
                }
                if (val > 0)//如果上一位有满十进一
                {
                    newNode->val = sum + val;//新节点值为上一节点进位+当前节点去和值%10
                    val = 0;//重置进位
                    if (newNode->val >= 10)//当当前值大于10的时候
                    {
                        val = newNode->val / 10;//使进位+1
                        newNode->val=newNode->val%10;//当前值做去十位处理
                    }
                }
                else
                {
                    newNode->val = sum;//情况正常，一般处理
                }
                val += Sum / 10;//获取进位
                ptr->next = newNode;//将节点连上结果链表
                ptr = ptr->next;//移动工具指针
                
                if (Ptr1!=nullptr)//当形参链表还未遍历完毕时移动形参链表指针
                {
                    Ptr1 = Ptr1->next;//防止两链表长度不一，可能发生某一链表节点访问未知空间
                }
                if (Ptr2!=nullptr)//同上
                {
                    Ptr2 = Ptr2->next;
                }
            }
            if (val!=0)//判断处理完毕后进位是否归零
            {
                ListNode* newNode = new ListNode;//当进位没有归零，创建新的节点(最后一次处理完毕后，最终位大于10)
                newNode->val = val;
                ptr->next = newNode;
            }
            return New->next;//返回结果链表头的下一位(头指针数据域无意义)
        }
    };
#endif // !HEAD_H_

