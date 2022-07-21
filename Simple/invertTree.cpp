//
// Created by 94456 on 7/11/2022.
//


#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>



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


class Solution_0
{
public:
    // 基于递归的方法
    TreeNode *invertTree(TreeNode *root)
    {
        // 要处理的节点为空
        if(root==nullptr)
        {
            // 返回空
            return nullptr;
        }

        // 递归翻转左节点
        TreeNode *l=invertTree(root->left);
        // 递归翻转右节点
        TreeNode *r=invertTree(root->right);

        // 交换根节点的左右节点
        root->left=r;
        root->right=l;

        // 返回翻转后的二叉树
        return root;

    }
};


class Solution_1
{
public:
    // 基于递归的方法
    TreeNode *invertTree(TreeNode *root)
    {
        if(root==nullptr)
        {
            return nullptr;
        }

        // #include<algorithm>
        // C++中swap:交换相同类型的两个变量内容

        // 在这里交换根节点的左右节点
        swap(root->left,root->right);

        // 递归翻转左节点
        root->left=invertTree(root->left);
        // 递归翻转右节点
        root->right=invertTree(root->right);

        // 返回翻转后的二叉树
        return root;
    }
};


class Solution_2
{
public:
    // 基于栈的后续遍历方法
    TreeNode *invertTree(TreeNode *root)
    {
        // 建立一个栈用来缓存待翻转的二叉树
        stack<TreeNode *> tree_cache;

        // 如果二叉树的根节点不为空
        if(root!=nullptr)
        {
            // 二叉树的根节点入栈
            tree_cache.push(root);
        }

        // 如果栈不空,则持续遍历栈
        while(!tree_cache.empty())
        {
            // 保存栈顶节点
            TreeNode *top_node=tree_cache.top();
            // 如果栈顶节点不空
            if(top_node!=nullptr)
            {
                // 栈顶节点暂时出栈
                tree_cache.pop();
                // 如果栈顶节点的左节点不空
                if(top_node->left!=nullptr)
                {
                    // 栈顶节点的左节点进栈
                    tree_cache.push(top_node->left);
                }
                // 如果栈顶节点的右节点不空
                if(top_node->right!=nullptr)
                {
                    // 栈顶节点的右节点进栈
                    tree_cache.push(top_node->right);
                }

                // 将一开始出栈的栈顶节点再入栈
                tree_cache.push(top_node);
                // 将一个空节点入栈
                // 这个空节点为了标识当前需要翻转的根节点
                tree_cache.push(nullptr);
            }
            else
            {
                // 如果栈顶节点为空
                // 这个空节点就是之前入栈的用来标识当前需要翻转的根节点的空节点
                tree_cache.pop();

                // #include<algorithm>
                // C++中swap:交换相同类型的两个变量内容

                // 这里交换栈顶节点的左右节点
                swap(tree_cache.top()->left,tree_cache.top()->right);
                // 将已经交换过的栈顶节点出栈
                tree_cache.pop();
            }
        }
        // 返回翻转后的二叉树
        return root;
    }
};


class Solution
{
public:
    // 基于队列的层序遍历方法
    TreeNode *invertTree(TreeNode *root)
    {
        // 创建一个队列,用于层序遍历
        queue<TreeNode *> tree_cache;
        // 如果待翻转的二叉树根节点不为空
        if(root!=nullptr)
        {
            // 二叉树根节点入队
            tree_cache.push(root);
        }
        // 如果队列不空
        while(!tree_cache.empty())
        {
            // 缓存队头节点
            TreeNode *front_node;
            // 循环遍历队列
            for(int i=0;i<tree_cache.size();i++)
            {
                // 缓存队头节点
                front_node=tree_cache.front();
                // 队头节点出队
                tree_cache.pop();

                // #include<algorithm>
                // C++中swap:交换相同类型的两个变量内容

                // 交换队头节点的左右两个节点
                swap(front_node->left,front_node->right);

                // 如果左节点不空
                if(front_node->left!=nullptr)
                {
                    // 左节点进队
                    tree_cache.push(front_node->left);
                }
                // 如果右节点不空
                if(front_node->right!=nullptr)
                {
                    // 右节点进队
                    tree_cache.push(front_node->right);
                }
            }
        }

        // 返回翻转后的二叉树
        return root;
    }
};


int main()
{

    printf("invertTree test ! \n");

    return 0;
}