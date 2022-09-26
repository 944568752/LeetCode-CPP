//
// Created by Brian_Tsui on 2022.09.26.
//


// exist


#include<iostream>
#include<vector>
#include<bits/stdc++.h>


using namespace std;


class Solution{
public:
    // 分别对应着:
    // 左移
    // 右移
    // 上移
    // 下移
    int move_x[4]={-1,1,0,0};
    int move_y[4]={0,0,-1,1};

    // 深度优先遍历搜索单词
    bool dfs(vector<vector<char>> &board,string word,int index,int i,int j){
        // 如果当前字符与目标字符串首字符不相同
        if(board[i][j]!=word[index]){
            // 则遍历失败
            return false;
        }
        // 如果当前遍历深度与目标字符串的长度相同
        if(index==word.size()-1){
            // 遍历成功
            return true;
        }

        // 暂存当前字符
        char temp=board[i][j];
        // 标记已经使用的字符
        board[i][j]='@';

        // 向上下左右四个方向遍历
        for(int k=0;k<4;k++){
            // 遍历后的位置索引
            int search_x=i+move_x[k];
            int search_y=j+move_y[k];

            // 如果索引越界或者当前字符已被使用
            if(search_x<0||search_x>=board.size()||search_y<0||search_y>=board[0].size()||board[search_x][search_y]=='@'){
                // 则换个方向索引
                continue;
            }

            // 深度优先遍历
            if(dfs(board,word,index+1,search_x,search_y)){
                return true;
            }
        }

        // 恢复当前字符
        board[i][j]=temp;

        // 如果此时未搜索到该单词,则认定该单词检索失败
        return false;

    }

    // 单词搜索
    bool exist(vector<vector<char>> &board,string word){
        // 遍历二维字符网格的行
        for(int i=0;i<board.size();i++){
            // 遍历二维字符网格的列
            for(int j=0;j<board[0].size();j++){
                // 进行深度优先遍历
                if(dfs(board,word,0,i,j)){
                    return true;
                }
            }
        }

        return false;

    }
};


int main(){

    Solution *s=new Solution();




    cout<<"Hello exist !"<<endl;

    return 0;
}