//
// Created by Brian_Tsui on 2022.09.09.
//


// removeNthFromEnd


#include<iostream>
#include<stack>
#include<iterator>

using namespace std;


// Definition for singly-linked list
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


class Solution_0{
public:
    ListNode *removeNthFromEnd(ListNode *head,int n){
        // 建立一个指针指向单链表的头节点
        ListNode *new_node=new ListNode(0,head);
        // 建立一个指针用于遍历单链表的长度并删除节点
        ListNode *cache_node=new_node;
        // 建立一个指针用于指向待删除节点
        ListNode *to_delete;

        // 记录单链表的长度
        int list_length=0;

        // 遍历单链表,直到单链表结束
        while(cache_node->next!=nullptr){
            // 单链表长度+1
            list_length++;
            // 指针指向下一个节点
            cache_node=cache_node->next;
        }

        // 指针重新指向单链表的头节点
        cache_node=new_node;
        // 第二次遍历单链表,遍历到待删除节点的位置
        for(int i=0;i<list_length-n;i++){
            // 指针指向下一个节点
            cache_node=cache_node->next;
        }
        // 指针指向待删除节点
        to_delete=cache_node->next;
        // 更改指针实现删掉一个节点
        cache_node->next=cache_node->next->next;
        // 删除节点,回收节点分配的空间
        delete to_delete;
        // 指针指向头节点
        new_node=new_node->next;
        // 返回头节点
        return new_node;

    }
};


class Solution_1{
public:
    ListNode *removeNthFromEnd(ListNode *head,int n){
        // 建立一个指针指向单链表的头节点
        ListNode *new_node=new ListNode(0,head);
        // 建立一个指针用于遍历单链表的长度并删除节点
        ListNode *cache_node=new_node;
        // 建立一个指针用于指向待删除节点
        ListNode *to_delete;

        // 建立一个栈,利用栈先进后出的特点来寻找要删除的节点
        stack<ListNode *> cache_stack;

        // 循环,将单链表的所有节点入栈
        while(cache_node!=nullptr){
            cache_stack.push(cache_node);
            cache_node=cache_node->next;
        }

        // 按第N个元素出栈,使栈顶元素恰好为要删除的元素的上一个
        for(int i=0;i<n;i++){
            cache_stack.pop();
        }
        // 记录栈顶元素
        cache_node=cache_stack.top();
        // 保存待删除的单链表节点
        to_delete=cache_node->next;
        // 更改指针实现删除一个节点
        cache_node->next=cache_node->next->next;
        // 删除节点,并回收节点分配的空间
        delete to_delete;

        // 指针指向头节点
        new_node=new_node->next;
        // 返回头节点
        return new_node;

    }
};


class Solution{
public:
    ListNode *removeNthFromEnd(ListNode *head,int n){
        // 建立一个指针指向单链表的头节点
        ListNode *new_node=new ListNode(0,head);
        // 建立两个指针用于共同遍历单链表并删除节点
        ListNode *left=new_node;
        ListNode *right=new_node->next;

        // 建立一个指针用于指向待删除节点
        ListNode *to_delete;

        // 移动右指针,使两个指针之间的距离为N
        for(int i=0;i<n;i++){
            right=right->next;
        }

        // 保持两个指针之间的距离为N
        while(right!=nullptr){
            // 同时移动左右两个指针
            left=left->next;
            right=right->next;
        }
        // 保存待删除的单链表节点
        to_delete=left->next;
        // 更改指针实现删除一个节点
        left->next=left->next->next;

        delete to_delete;

        // 指针指向头节点
        new_node=new_node->next;
        // 返回头节点
        return new_node;

    }
};


int main(){

    string a="test123@@@@";

    string::iterator b=a.begin();



    cout<<"Hello removeNthFromEnd !"<<endl;

    return 0;
}