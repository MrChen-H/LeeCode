#pragma once
#ifndef HEAD_H_
#define HEAD_H_
struct ListNode//����ڵ�ṹ����Ŀ���� 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};
    class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) //����ɵĹ��ܺ���
        {
            int val = 0;//��¼��ֵ��λ
            ListNode* New = new ListNode;//���ص�����ͷ�ڵ�
            ListNode* ptr = New;//ָ��ͷ�ڵ�Ĺ���ָ��
            ListNode* Ptr1 = l1;//ָ���β�L1�Ĺ���ָ��
            ListNode* Ptr2 = l2;//ָ���β�L2�Ĺ���ָ��
            int sum = 0;//�������ڵ�͵ı���
            while (Ptr1!= nullptr || Ptr2!= nullptr)//����������һ��û�б������������ѭ������
            {
                int Sum;//׷�ټ�¼�ڵ��
                if (Ptr1==nullptr||Ptr2==nullptr)//��L1 Or L2 �ڵ��������Ϊ��ʱ(���������Ȳ�һ)
                {
                    if (Ptr2 == nullptr)//��ĳһ������������� 0 ֵ�
                    {
                        sum = Ptr1->val + 0;
                    }
                    else
                    {
                        sum = 0 + Ptr2->val;
                    }
                }
                else//����Ϊ����������
                {
                    sum = Ptr1->val + Ptr2->val;
                }
                Sum = sum;//���¸���
                ListNode* newNode = new ListNode;//�����������������ڵ�
                if (sum >= 10)//�����ֵ����10
                {
                    sum %= 10;//ȥ��ʮλ
                }
                if (val > 0)//�����һλ����ʮ��һ
                {
                    newNode->val = sum + val;//�½ڵ�ֵΪ��һ�ڵ��λ+��ǰ�ڵ�ȥ��ֵ%10
                    val = 0;//���ý�λ
                    if (newNode->val >= 10)//����ǰֵ����10��ʱ��
                    {
                        val = newNode->val / 10;//ʹ��λ+1
                        newNode->val=newNode->val%10;//��ǰֵ��ȥʮλ����
                    }
                }
                else
                {
                    newNode->val = sum;//���������һ�㴦��
                }
                val += Sum / 10;//��ȡ��λ
                ptr->next = newNode;//���ڵ����Ͻ������
                ptr = ptr->next;//�ƶ�����ָ��
                
                if (Ptr1!=nullptr)//���β�����δ�������ʱ�ƶ��β�����ָ��
                {
                    Ptr1 = Ptr1->next;//��ֹ�������Ȳ�һ�����ܷ���ĳһ����ڵ����δ֪�ռ�
                }
                if (Ptr2!=nullptr)//ͬ��
                {
                    Ptr2 = Ptr2->next;
                }
            }
            if (val!=0)//�жϴ�����Ϻ��λ�Ƿ����
            {
                ListNode* newNode = new ListNode;//����λû�й��㣬�����µĽڵ�(���һ�δ�����Ϻ�����λ����10)
                newNode->val = val;
                ptr->next = newNode;
            }
            return New->next;//���ؽ������ͷ����һλ(ͷָ��������������)
        }
    };
#endif // !HEAD_H_

