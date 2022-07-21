//
// Created by 94456 on 7/3/2022.
//


#include<iostream>
#include<stack>
#include<unordered_map>

using namespace std;


class Solution
{
public:
    bool isValid(string s)
    {
        // C++中单个字符是char
        stack<char> char_stack;
        // C++中字符串实际上是一个字符数组，因此也可以使用size()函数来获取数组长度
        for(int i=0;i<s.size();i++)
        {
            // 碰见左半边，就将对应的右半边进栈
            if(s[i]=='(')
            {
                char_stack.push(')');
            }
            else if(s[i]=='[')
            {
                char_stack.push(']');
            }
            else if(s[i]=='{')
            {
                char_stack.push('}');
            }
            // 栈为空或左右不匹配，输出false
            else if(char_stack.empty()||char_stack.top()!=s[i])
            {
                return false;
            }
            // 若匹配则出栈
            else
            {
                char_stack.pop();
            }
        }
        // 返回栈的状态
        // 栈空:则说明均匹配成功，返回ture
        // 栈不空:则说明未匹配成功，返回false
        return char_stack.empty();
    }
};



int main()
{

    string s="()[]{}";

    Solution solu;

    bool b=solu.isValid(s);

    printf("%b \n",b);

    return 0;
}