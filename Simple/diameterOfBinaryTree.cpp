//
// Created by 94456 on 8/23/2022.
//


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
    // 本题是递归遍历求二叉树高度的变体
    // 返回从某节点出发,左右子树高度之和的最大值即为题目中要求的二叉树直径

    // 全局变量存储二叉树的最大直径
    // 记录当前节点间的最大距离
    int width=0;

    // 获得以当前节点为根节点的二叉树的高度(宽度)
    int ObtainHigh(TreeNode *root){
        if(root==nullptr){
            return 0;
        }
        return max(ObtainHigh(root->left),ObtainHigh(root->right))+1;
    }

    // 计算以当前节点为根节点的二叉树的左右子树之和,并更新当前节点间的最大距离
    void ObtainNodeWidth(TreeNode *root){
        if(root==nullptr){
            return;
        }
        if((ObtainHigh(root->left)+ ObtainHigh(root->right))>width){
            width=ObtainHigh(root->left)+ ObtainHigh(root->right);
        }
        // 递归遍历左子树
        ObtainNodeWidth(root->left);
        // 递归遍历右子树
        ObtainNodeWidth(root->right);
    }

    int diameterOfBinaryTree(TreeNode *root){
        ObtainNodeWidth(root);
        return width;
    }

};


int main()
{

    printf("Hello Second Program ! \n");

    return 0;
}