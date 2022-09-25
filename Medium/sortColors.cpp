//
// Created by Brian_Tsui on 2022.09.25.
//


// sortColors


#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    // 颜色分类
    void sortColors(vector<int> &nums){
        // 记录给定数组的长度
        int n=nums.size();

        // 如果数组的长度为1
        // 此时直接返回
        if(n<=1){
            return;
        }

        // 左边指针
        // 记录红白交界
        int left=0;
        // 右边指针
        // 记录白蓝交界
        int right=n-1;

        // 当前的位置索引
        int index=0;

        // 如果当前的位置小于右指针
        // 进行遍历
        while(index<=right){
            // 当前遍历值为0
            if(nums[index]==0){
                // 将当前值交换到左边界
                swap(nums[index],nums[left]);
                // 左边界向右移动一位
                left++;
            }
            // 当前遍历值为2
            else if(nums[index]==2){
                // 将当前值交换到右边界
                swap(nums[index],nums[right]);
                // 右边界向左移动一位
                right--;
                // 此时未确定交换到index的数的大小
                // 因此不可以遍历下一个
                continue;
            }
            // index向右移动一位
            // 遍历下一个值
            index++;
        }
    }

};



int main(){


    cout<<"Hello sortColors !"<<endl;

    return 0;
}