//
// Created by Brian_Tsui on 2022.09.22.
//


// uniquePaths


#include<iostream>
#include<vector>


using namespace std;


class Solution{
public:
    // 递归遍历不同位置上的路径数量
    void Get_sub_path(int m,int n,int &result){
        // 如果任何一维到达边界
        // 即可确定不存在其他分支路径了
        if(m==0||n==0){
            // 路径数量+1
            result++;
            // 结束该分支的递归
            return;
        }
        // 向右移一步,然后递归遍历
        Get_sub_path(m-1,n,result);
        // 向左移一步,然后递归遍历
        Get_sub_path(m,n-1,result);
    }
    // 不同路径
    int uniquePaths(int m,int n){
        // 记录路径数量
        int result=0;
        // 递归遍历
        Get_sub_path(m-1,n-1,result);
        // 返回路径数量
        return result;
    }
};


//class Solution {
//public:
//    // 不同路径
//    int uniquePaths(int m, int n) {
//        // 首先初始化一个m行n列的二维数组
//        // 用来存储每一个位置的路径数量
//        vector<vector<int>> result(m, vector<int>(n));
//        // 递归遍历行
//        for(int i = 0;i < m;i++)
//        {
//            // 递归遍历列
//            for(int j = 0;j < n;j++)
//            {
//                // 如果任何一维到达边界
//                // 即可确定不存在其他分支路径了
//                if(i == 0 || j == 0)
//                    // 该点路径数量为1
//                    result[i][j] = 1;
//                else
//                    // 如果不是边界,则使用状态转移方程来计算当前点路径的数量
//                    result[i][j] = result[i - 1][j] + result[i][j - 1];
//            }
//        }
//        // 右下角的元素就是所有路径的总数
//        return result[m - 1][n - 1];
//    }
//};



int main(){

    Solution *s=new Solution();
    int m=51;
    int n=9;
    int result = s->uniquePaths(m,n);

    cout<<result<<endl;

    cout<<"Hello uniquePaths !"<<endl;

    return 0;
}