//
// Created by 94456 on 7/12/2022.
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
    // 回文链表
    bool isPalindrom(ListNode *head)
    {
        // 定义一个快指针,每次两个节点
        ListNode *fast=head;
        // 定义一个慢指针,每次一个节点
        ListNode *slow=head;

        // 缓存反转之后的前半部分链表
        ListNode *reverse_cache=nullptr;
        // 用于反转链表
        ListNode *node_cache=nullptr;

        // 遍历链表
        // 当快指针指向链表的尾部时
        // 慢指针刚好指向链表的中间
        while(fast!=nullptr&&fast->next!=nullptr)
        {
            // 快指针每次前进两个节点
            fast=fast->next->next;

            // 指向慢指针的下一个节点
            node_cache=slow->next;
            // 将反转链表接到慢指针指向的当前节点之后
            slow->next=reverse_cache;
            // 将新的反转链表接回原处
            reverse_cache=slow;
            // 慢指针指向下一个节点(前进一个节点)
            slow=node_cache;

        }

        // 如果回文链表的节点个数为奇数
        if(fast->next!=nullptr)
        {
            // 慢指针指向中心节点的右侧
            slow=slow->next;
        }

        // 遍历
        while(reverse_cache!=nullptr)
        {
            // 对比反转的前半链表与后半链表
            if(slow->val!=reverse_cache->val)
            {
                // 如果有节点值不相等,则不是回文链表
                // 返回false
                return false;
            }
            // 如果节点值相等,则继续向下遍历
            slow=slow->next;
            reverse_cache=reverse_cache->next;
        }
        // 如果都相等
        // 则该链表属于回文链表,返回true
        return true;



    }
};


void Test(int *a)
{
    // a++;
    *a=6;
    cout<<a<<endl;
}


int main()
{
    printf("isPalindrom Test ! \n ");

    int b=3;
    int *a=&b;

    cout<<a<<endl;
    cout<<b<<endl;

    Test(a);

    cout<<a<<endl;
    cout<<b<<endl;

    int c=2;
    cout<<c<<endl;

    int *d=&b;
    cout<<d<<endl;
    cout<<*d<<endl;

    *d++;
    *d++;

    cout<<d<<endl;
    cout<<*d<<endl;





    return 0;
}
