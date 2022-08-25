//
// Created by 94456 on 8/25/2022.
//


// addTwoNumbers


#include<iostream>


using namespace std;


// Definition for singly-linked list.
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


class Solution{
public:
    ListNode *addTwoNumbers(ListNode *l1,ListNode *l2){
        // 指向表示和的结果链表的表头
        ListNode *result=new ListNode(0);
        // 指向表示和的结果链表的表尾
        ListNode *result_tail=result;

        // 记录两数相加之和
        int sum=0;

        // 直到两个链表均为空时,结束循环
        while(l1!=nullptr||l2!=nullptr){
            // 1. l1空,l2不空
            if(l1==nullptr&&l2!=nullptr){
                // 计算l2节点的值与进位的和
                int add=l2->val+sum;
                // 记录两数相加之和
                result_tail->next=new ListNode(add%10);
                // 记录两数相加的进位
                sum=add/10;

                // 向下遍历l2
                l2=l2->next;
                // 结果链表的尾指针后移一位
                result_tail=result_tail->next;
            }
            // 2. l1不空,l2空
            else if(l1!=nullptr&&l2==nullptr){
                // 计算l1节点的值与进位的和
                int add=l1->val+sum;
                // 记录两数相加之和
                result_tail->next=new ListNode(add%10);
                // 记录两数相加的进位
                sum=add/10;

                // 向下遍历l1
                l1=l1->next;
                // 结果链表的尾指针后移一位
                result_tail=result_tail->next;
            }
            // 3. l1和l2均不空
            else{
                // 计算l1节点的值、l2节点的值与进位的和
                int add=l1->val+l2->val+sum;
                // 记录三数相加之和
                result_tail->next=new ListNode(add%10);
                // 记录三数相加的进位
                sum=add/10;

                // 向下遍历l1
                l1=l1->next;
                // 向下遍历l2
                l2=l2->next;
                // 结果链表的尾指针后移一位
                result_tail=result_tail->next;
            }
        }
        // 如果最后还有进位
        if(sum!=0){
            // 记录进位的值
            result_tail->next=new ListNode(sum);
        }
        // 返回表示和的结果链表的头节点
        return result->next;
    }
};




int main(){

    printf("Hello addTwoNumbers ! \n");

    return 0;
}