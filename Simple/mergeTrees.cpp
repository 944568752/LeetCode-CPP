//
// Created by 94456 on 8/25/2022.
//


// mergeTrees


#include<iostream>


using namespace std;


// Definition for a binary tree node
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        this->val=0;
        this->left=nullptr;
        this->right=nullptr;
    }

    TreeNode(int x)
    {
        this->val=x;
        this->left=nullptr;
        this->right=nullptr;
    }

    TreeNode(int x,TreeNode *left,TreeNode *right)
    {
        this->val=x;
        this->left=left;
        this->right=right;
    }
};


class Solution{
public:
    // 递归遍历,合并二叉树
    TreeNode *mergeTrees(TreeNode *root1,TreeNode *root2){
        // 如果Tree1为空,则直接返回Tree2
        if(root1==nullptr){
            return root2;
        }
        // 如果Tree2为空,则直接返回Tree1
        if(root2==nullptr){
            return root1;
        }
        // 如果两个节点都不为空,则合并,值相加
        TreeNode *merged=new TreeNode(root1->val+root2->val);
        // 递归合并两个节点的左子树
        merged->left=mergeTrees(root1->left,root2->left);
        // 递归合并两个节点的右子树
        merged->right=mergeTrees(root1->right,root2->right);
        return merged;
    }
};


int main(){

    int *a = new int[10] {1,2,3,4,5,6,7,8};

    for(int i=0;i<10;i++){
        printf("%d\n",a[i]);
    }

    printf("mergeTrees ! \n");

    return 0;
}