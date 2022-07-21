//
// Created by 94456 on 7/9/2022.
//


#include<iostream>
#include<unordered_set>


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
    // 常规遍历方法
    ListNode *getIntersectionNode(ListNode *headA,ListNode *headB)
    {
        // 记录经过的所有节点
        unordered_set<ListNode *> visited;
        // 记录当前节点
        ListNode *p=headA;

        // 循环遍历单链表A
        while(p!=nullptr)
        {
            // 保存访问过的节点
            visited.insert(p);
            // 访问下一个节点
            p=p->next;
        }

        // 遍历完单链表A后继续遍历单链表B
        p=headB;

        // 循环遍历单链表B
        while(p!=nullptr)
        {
            // 如果当前节点存在于已访问过的节点中
            if(visited.count(p))
            {
                // 则当前节点就是相交节点
                return p;
            }
            // 访问下一个节点
            p=p->next;
        }

        // 两个单链表不存在相交节点,返回null
        return nullptr;
    }
};


class Solution
{
public:
    // 基于双指针的方法
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // 如果单链表A和单链表B至少有一个为空,则两个单链表不存在相交节点,返回null
        if(headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }

        // 定义两个指针分别指向两个单链表的头节点
        ListNode *pA=headA;
        ListNode *pB=headB;

        // 在两个指针相遇之前,持续遍历两个单链表
        while(pA!=pB)
        {
            // 如果单链表A遍历结束
            if(pA==nullptr)
            {
                // 将pA指向单链表B的头节点
                pA=headB;
            }
            else
            {
                // 否则继续遍历
                pA=pA->next;
            }

            // 如果单链表B遍历结束
            if(pB==nullptr)
            {
                // 将pB指向单链表A的头节点
                pB=headA;
            }
            else
            {
                // 否则继续遍历
                pB=pB->next;
            }
        }
        // 两个指针相遇之后
        // 相遇点即为两个单链表的相交节点
        return pA;
    }
};


int main()
{

    printf("getintersectionNode ! \n");

    int a=-2;
    if(a)
    {
        printf("yes \n");
    }

    return 0;

}