//
// Created by Brian_Tsui on 2022.09.22.
//


// merge


#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>


using namespace std;


class Solution{
public:
    // 合并区间
    vector<vector<int>> merge(vector<vector<int>> &intervals){
        // 定义数组记录最后的结果
        vector<vector<int>> result;
        // 如果输入数组长度为0
        if(intervals.size()==0){
            // 则结果必然是空数组
            return result;
        }
        // 对给定数组进行排序
        sort(intervals.begin(),intervals.end());
        // 暂时保存当前的区间
        vector<int> temp_interval=intervals[0];
        // 遍历,依次合并所有的区间
        for(int i=1;i<intervals.size();i++){
            // 若下一个区间的左端点小于等于当前区间的右端点
            if(intervals[i].front()<=temp_interval.back()&&intervals[i].back()>=temp_interval.back()){
                // 符合条件,进行合并
                temp_interval.back()=intervals[i].back();
            }
            // 若下一个区间的左端点大于当前区间的右端点
            else if(intervals[i].front()>temp_interval.back()){
                // 不符合条件,不进行合并
                // 保存当前区间
                result.push_back(temp_interval);
                // 新开辟一个区间
                temp_interval=intervals[i];
            }
        }
        // 保存最后的区间
        result.push_back(temp_interval);
        // 返回合并后的区间
        return result;


    }
};


int main(){


    cout<<"Hello merge !"<<endl;

    return 0;
}