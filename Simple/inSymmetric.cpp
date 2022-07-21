//
// Created by 94456 on 7/7/2022.
//


#include<iostream>
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
    // 递归方法
    // 左右子树相等的时候,需要满足:
    // 左子树的左边==右子树的右边
    // 左子树的右边==右子树的左边
    bool isMirror(TreeNode *left_subtree,TreeNode *right_subtree)
    {
        // 如果左右子树都为空,返回true
        if(!left_subtree && !right_subtree)
        {
            return true;
        }
        // 如果左右子树有一个不空,返回false
        if(!left_subtree || !right_subtree)
        {
            return false;
        }
        // 如果左右子树的节点值不相等,返回false
        if(left_subtree->val!=right_subtree->val)
        {
            return false;
        }
        // 递归判断子树
        return isMirror(left_subtree->left,right_subtree->right)
            && isMirror(left_subtree->right,right_subtree->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        // 如果根节点为空,返回true
        if(!root)
        {
            return true;
        }
        // 递归判断
        return isMirror(root->left,root->right);
    }
};


class Solution
{
public:
    // 迭代方法
    // 使用迭代的方法,需要借助外部的容器
    bool isSymmetric(TreeNode *root)
    {
        // 如果左右子树都为空,则返回true
        if(!root)
        {
            return true;
        }

        // 创建一个队列用来缓存树
        queue<TreeNode *> q;

        // 分别将树的根节点的左右节点放入队列
        q.push(root->left);
        q.push(root->right);

        // 队列不空就一直迭代
        while(!q.empty())
        {
            // 左节点
            auto p1=q.front();
            q.pop();

            // 右节点
            auto p2=q.front();
            q.pop();

            // 如果两个节点都是为空节点,则跳过本次循环
            if(!p1&&!p2)
            {
                continue;
            }
            // 如果左右节点有一个不为空,则返回false
            if(!p1||!p2)
            {
                return false;
            }
            // 如果两个节点的值不相等,则返回false
            if(p1->val!=p2->val)
            {
                return false;
            }

            // 1.
            // 将左节点的左子节点进队列
            q.push(p1->left);
            // 将右节点的右子节点进队列
            q.push(p2->right);

            // 2.
            // 将左节点的右子节点进队列
            q.push(p1->right);
            // 将右节点的左子节点进队列
            q.push(p2->left);

            // 其中,1和2的位置可以互换

        }
        //如果通过迭代对比,则返回true
        return true;
    }
};


int main()
{

    int a=1;

    printf(to_string(a).c_str());


    auto b=1;

    auto c="string";

    printf(typeid(b).name());
    printf("\n\n");
    printf(typeid(c).name());

    printf("\n");


    int d=a;

    int *e=&a;


    printf("%d\n",d);
    printf("%d\n",e);


    return 0;
}












