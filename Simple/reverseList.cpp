//
// Created by 94456 on 7/10/2022.
//


#include<iostream>


using namespace std;



class ListNode
{
public:
    int val;
    ListNode *next;

    // Function overload
    ListNode() {
        this->val = 0;
        this->next = nullptr;
    }

    ListNode(int x) {
        this->val = x;
        this->next = nullptr;
    }

    ListNode(int x, ListNode *y) {
        this->val = x;
        this->next = y;
    }
};


class Solution
{
public:
    // 反转链表
    ListNode *reverseList(ListNode *head)
    {
        // 如果输入的链表为空
        if(head==nullptr)
        {
            // 则返回空
            return nullptr;
        }

        // 用来缓存输入链表
        ListNode *temporary=head;
        // 用来缓存结果链表
        ListNode *resultCache=nullptr;
        // 结果链表
        ListNode *resultList=nullptr;

        // 如果输入链表不空,则持续遍历
        while(temporary!=nullptr)
        {
            // 保存结果链表中已有的节点
            resultCache=resultList;
            // 将结果链表的头指针指向输入链表
            resultList=temporary;
            // 将输入链表的头指针指向结果链表中保存的输入链表的头节点之后的节点
            temporary=resultList->next;
            // 将结果链表的下一个节点指向之前缓存的结果链表
            resultList->next=resultCache;
        }
        // 返回最终的翻转链表
        return resultList;
    }
};


int main()
{

    Solution s;

    printf("Test reverseList ! \n");

    return 0;
}