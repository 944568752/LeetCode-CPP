//
// Created by 94456 on 7/6/2022.
//


#include<iostream>
#include<vector>


using namespace std;


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


class Solution
{
public:
    // 按照中序遍历的规则,递归的进行遍历
    void inorder(TreeNode *root,vector<int> &result_order)
    {
        // 如果根节点为空
        if(!root)
        {
            // 返回一个空值
            // 可以当做一个返回主函数的命令
            return;
        }

        // 遍历左子树
        inorder(root->left,result_order);
        // 将根节点存入结果向量中
        result_order.push_back(root->val);
        // 遍历右子树
        inorder(root->right,result_order);

    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        // 创建一个结果向量储存遍历结果
        vector<int> result_order;
        // 递归的中序遍历二叉树
        inorder(root,result_order);
        // 返回遍历的结果
        return result_order;
    }
};


int main()
{

    return 0;
}