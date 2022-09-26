//
// Created by Brian_Tsui on 2022.09.25.
//


// subSets


#include<iostream>
#include<vector>


using namespace std;


class Solution{
public:
    // 回溯查找所有子集
    void Recall(vector<int> &nums,vector<vector<int>> &result,vector<int> &temp,int n){
        // 如果所有的元素都在子集中
        // 中断停止回溯
        if(n>=nums.size()){
            return;
        }

        // 从当前位置遍历子集
        for(int i=n;i<nums.size();i++){
            // 将当前数字加入当前子集
            temp.push_back(nums[i]);
            // 储存形成的新子集
            result.push_back(temp);
            // 从当前位置的下一个位置进行回溯查找
            // 避免出现重复的元素
            Recall(nums,result,temp,i+1);
            // 将当前数字移出当前子集
            temp.pop_back();
        }

    }

    // 子集
    vector<vector<int>> subsets(vector<int> &nums){
        // 二维数组存储所有的子集
        vector<vector<int>> result;
        // 设置缓存存储当前子集
        vector<int> temp;

        // 一定存在一个空子集
        // 因此一开始便将空子集加入结果数组
        result.push_back(temp);

        // 回溯查找所有的子集
        Recall(nums,result,temp,0);

        // 返回所有的子集
        return result;
    }
};



int main(){


    cout<<"Hello subsets !"<<endl;

    return 0;
}