//
// Created by Brian_Tsui on 2022.09.23.
//


// minPathSum


#include<iostream>
#include<vector>



using namespace std;


class Solution{
public:
    // 最小路径和
    int minPathSum(vector<vector<int>> &grid){
        // 记录网格的行数
        int m=grid.size();
        // 记录网格的列数
        int n=grid[0].size();

        // 新建一个二维数组记录每个位置的最小路径
        vector<vector<int>> result(m,vector<int>(n,0));

        // 初始化第一个节点的最小路径
        result[0][0]=grid[0][0];
        // 初始化最左边一列的最小路径
        for(int i=1;i<m;i++){
            result[i][0]=result[i-1][0]+grid[i][0];
        }
        // 初始化最上边一行的最小路径
        for(int i=1;i<n;i++){
            result[0][i]=result[0][i-1]+grid[0][i];
        }

        // 利用状态转移方程
        // 遍历每一个位置的最小路径
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                result[i][j]=min(result[i-1][j],result[i][j-1])+grid[i][j];
            }
        }
        // 返回最小路径和
        return result[m-1][n-1];
    }
};


int main(){


    cout<<"Hello minPathSum !"<<endl;

    return 0;
}