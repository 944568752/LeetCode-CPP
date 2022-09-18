//
// Created by Brian_Tsui on 2022.09.18.
//


// rotate


#include<iostream>
#include<vector>


using namespace std;


class Solution{
public:
    // 旋转图像
    void rotate(vector<vector<int>> &matrix){
        // 上下反转
        // 仅需反转一半即可
        for(int i=0;i<matrix.size()/2;i++){
            for(int j=0;j<matrix.size();j++){
                // 交换
                swap(matrix[i][j],matrix[matrix.size()-1-i][j]);
            }
        }

        // 沿着主对角线反转
        for(int i=1;i<matrix.size();i++){
            // 仅需反转左下三角或右上三角即可
            for(int j=i+1;j<matrix.size();j++){
                // 交换
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};


int main(){

    Solution *s=new Solution();



    cout<<"Hello rotate !"<<endl;

    return 0;
}