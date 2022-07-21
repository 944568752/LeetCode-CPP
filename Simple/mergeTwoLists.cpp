//
// Created by 94456 on 7/4/2022.
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


class Solution_0
{
public:
    ListNode *mergeTwoLists(ListNode *list1,ListNode *list2)
    {
        // 如果list1为空，无需合并，结果直接是list2
        if(list1==nullptr)
        {
            return list2;
        }
        // 如果list2为空，无需合并，结果直接是list1
        if (list2==nullptr)
        {
            return list1;
        }

        // 创建一个结果链表，保存合并的结果
        ListNode *resultNode=new ListNode();
        ListNode *p=resultNode;

        // 循环
        while(list1!=nullptr&&list2!=nullptr)
        {
            // 若list1的表头小于list2的表头
            if(list1->val<list2->val)
            {
                // 结果链表的表头指针指向list1的表头
                p->next=list1;
                // list1的表头指针后移
                list1=list1->next;
            }
            else
            // 若list2的表头小于list1的表头
            {
                // 结果链表的表头指针指向list2的表头
                p->next=list2;
                // list2的表头指针后移
                list2=list2->next;
            }
            // 结果链表的表头指针后移
            p=p->next;
        }
        // 如果list1为空
        if(list1==nullptr)
        {
            // 则将list2接到结果链表之后
            p->next=list2;
        }
        // 如果list2为空
        else if(list2==nullptr)
        {
            // 则将list1接到结果链表之后
            p->next=list1;
        }

        // 与正确结果相比，resultNode多了一个表头
        // 需要去掉表头
        resultNode=resultNode->next;
        // 输出合并结果
        return resultNode;
    }
};


class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1,ListNode *list2)
    {
        // 如果list1为空，无需合并，结果直接是list2
        if(list1==nullptr)
        {
            return list2;
        }
        // 如果list2为空，无需合并，结果直接是list1
        if (list2==nullptr)
        {
            return list1;
        }

        // 递归
        if(list1->val<list2->val)
        {
            list1->next=mergeTwoLists(list1->next,list2);
            return list1;
        }
        list2->next=mergeTwoLists(list1,list2->next);
        return list2;
    }
};


int main()
{


    int b;

    printf("%d",b);

    return 0;
}