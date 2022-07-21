//
// Created by 94456 on 7/7/2022.
//


#include<iostream>
#include<stack>
#include<deque>



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
    // 深度优先递归遍历
    int maxDepth(TreeNode *root)
    {
        // 如果根节点为空,则返回深度0
        if(!root)
        {
            return 0;
        }

        // 遍历左子树的深度
        int left_depth=maxDepth(root->left);
        // 遍历右子树的深度
        int right_depth=maxDepth(root->right);

        // 返回左右子树的最大深度+1
        return max(left_depth,right_depth)+1;
    }
};


class Solution_1
{
public:
    // 基于栈的深度优先遍历
    int maxDepth(TreeNode *root)
    {
        // 记录深度
        int maxdepth = 0;
        // 在栈中同时存放节点和当前深度
        stack<pair<TreeNode *, int>> p;

        // 根节点不空,则将根节点和当前深度1入栈
        if (root) {
            p.push(pair<TreeNode *, int> (root, 1));
        }

        // 若栈不空,则开始深度优先遍历
        while (!p.empty())
        {
            // 栈顶节点
            TreeNode *stack_top=p.top().first;
            // 栈顶节点的深度
            int st_depth=p.top().second;
            // 将栈顶节点出栈
            p.pop();

            // 记录当前最大深度
            maxdepth=max(maxdepth,st_depth);

            // 如果左节点不空,则将左节点和左节点的深度(当前节点深度+1)入栈
            if(stack_top->left)
            {
                p.push(pair<TreeNode *,int> (stack_top->left,st_depth+1));
            }
            // 如果右节点不空,则将右节点和右节点的深度(当前节点深度+1)入栈
            if(stack_top->right)
            {
                p.push(pair<TreeNode *,int> (stack_top->right,st_depth+1));
            }

        }
        // 返回记录的最大深度
        return maxdepth;

    }

};



class Solution
{
public:
    // 基于双端队列的广度优先遍历
    int maxDepth(TreeNode *root)
    {
        // 记录深度
        int maxdepth=0;
        // 双端队列用于存放每一层的节点
        deque<TreeNode *> p;

        // 如果根节点为空,则返回深度0
        if(!root)
        {
            return 0;
        }

        // 若根节点不空,则将根节点入队
        p.push_back(root);

        // 若队不空,则开始广度优先遍历
        while(!p.empty())
        {
            // 每遍历到一层,最大深度自增1
            maxdepth++;

            // 记录当前队中的节点数量
            int num=p.size();

            // 遍历一层的所有节点
            for(int i=1;i<=num;i++)
            {
                // 保存队首节点后,将队首节点出队
                TreeNode *q=p.front();
                p.pop_front();

                // 若左节点不空,则将左节点入队
                if(q->left)
                {
                    p.push_back(q->left);
                }
                // 若右节点不空,则将右节点入队
                if(q->right)
                {
                    p.push_back(q->right);
                }

            }

        }
        // 返回记录的最大深度
        return maxdepth;

    }
};



int main()
{

    printf("Test ! \n");

    int a=1;
    int b=2;

    int c=a>b?5:6;



    return 0;
}