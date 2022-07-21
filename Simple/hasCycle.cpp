//
// Created by 94456 on 7/9/2022.
//


#include<iostream>


using namespace std;


class ListNode
{
public:
    int val;
    ListNode *next;

    // Function overload
    ListNode()
    {
        this->val=0;
        this->next=nullptr;
    }

    ListNode(int x)
    {
        this->val=x;
        this->next=nullptr;
    }

    ListNode(int x,ListNode *y)
    {
        this->val=x;
        this->next=y;
    }

};


class Solution
{
public:
    // 判断环形链表
    bool hasCycle(ListNode *head)
    {
        // 如果链表为空,则肯定不是环形链表
        if(!head)
        {
            return false;
        }

        // 设置两个速度不同的指针
        // 如果两个指针相遇,则表示链表一定有环
        // 如果两个指针没有相遇且指到了null
        // 则表示已到了链表尾部,无环

        // 慢指针(初始指向链表头节点)
        ListNode *slow=head;
        // 快指针(初始指向链表头节点)
        ListNode *fast=head;

        // 如果快指针没有指到null
        // 表示遍历并未结束
        while(fast&&fast->next)
        {
            // 慢指针每次前进一个节点
            slow=slow->next;
            // 快指针每次前进两个节点
            fast=fast->next->next;

            // 两指针相遇则证明有环
            if(slow==fast)
            {
                return true;
            }

        }

        // 未相遇则证明无环
        return false;

    }
};


int main()
{

    printf("Test ! \n");

    return 0;
}