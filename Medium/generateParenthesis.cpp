//
// Created by Brian_Tsui on 2022.09.10.
//



// generateParenthesis


#include<iostream>
#include<vector>


using namespace std;


class Solution{
public:
    // 括号生成递归子函数
    void generate_sub_Parenthesis(vector<string> &result,string s,int left,int right,int n){
        // 当前子串右括号为n,意味着深度优先遍历结束
        if(right==n){
            // 将子串存放到结果数组中
            result.push_back(s);
        }
        // 如果仍有左括号没放完,深度优先遍历,因此先添加左括号
        if(left<n){
            generate_sub_Parenthesis(result,s+"(",left+1,right,n);
        }
        // 如果仍有右括号没放完,深度优先遍历,因此添加右括号
        if(left>right){
            generate_sub_Parenthesis(result,s+")",left,right+1,n);
        }

    }

    // 括号生成
    vector<string> generateParenthesis(int n){
        // 定义一个数组保存子串
        vector<string> result;
        // 递归进行深度优先遍历
        generate_sub_Parenthesis(result,"",0,0,n);
        // 返回所有子串
        return result;
    }
};


int main(){

    cout<<"Hello generateParenthesis !"<<endl;

    return 0;
}