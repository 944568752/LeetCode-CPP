//
// Created by Brian_Tsui on 2022.09.20.
//


// canJump


#include<iostream>
#include<vector>


using namespace std;


class Solution{
public:
    // 跳跃游戏
    bool canJump(vector<int> &nums){
        // 给定数组的长度
        int n=nums.size();
        // 如果给定数据的长度为1,则已经到达最后一个下标
        if(n==1){
            return true;
        }
        // 记录当前能到达的最远位置
        // 初始能到达的最远位置为第一个点能到达的最远位置
        int max_position=nums[0];
        // 如果初始位置为0,则代表从第一个节点开始便无法跳跃
        if(max_position==0){
            return false;
        }
        // 从左到右开始遍历
        for(int i=1;i<n;i++){
            // 记录当前所能到达的最远位置
            max_position=max(max_position,nums[i]+i);
            // 如果当前能到达的最远位置大于数组的长度
            if(max_position>=n-1){
                // 表示可以到达最后一个下标
                return true;
            }
            // 如果当前能到达的最远位置等于当前位置
            if(max_position==i){
                // 这意味着会在当前位置止步不前
                return false;
            }
        }
        // 其他情况默认为不可到达
        return false;
    }
};


int main(){


    return 0;
}