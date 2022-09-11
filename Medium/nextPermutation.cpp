//
// Created by Brian_Tsui on 2022.09.11.
//


// nextPermutation


#include<iostream>
#include<vector>
#include<algorithm>



using namespace std;


class Solution{
public:
    // 下一个排列
    void nextPermutation(vector<int> &nums){
        // 如果数组的长度小于等于1
        if(nums.size()<=1){
            // 则直接返回该数组本身即可
            return;
        }
        // 记录要交换的数的位置
        int index;
        // 从后向前循环,寻找要交换的数的位置
        for(index=nums.size()-1;index>0;index--){
            // 如果一个数比前面的数要大
            if(nums[index]>nums[index-1]){
                // 则该数为要交换的数的位置
                // 停止循环遍历
                break;
            }
        }
        // 如果最终要交换的位置在最前面,则表示找不到更大排序
        if(index==0){
            // 此时对数组进行排序即可
            sort(nums.begin(),nums.end());
        }
        else{
            // 对交换位置之后的数进行排序
            sort(nums.begin()+index,nums.end());
            // 遍历排序后的数,找到待交换的数
            for(int i=index;i<nums.size();i++){
                // 如果该数比待交换的数大
                if(nums[i]>nums[index-1]){
                    // 交换两个数
                    swap(nums[i],nums[index-1]);
                    // 结束遍历
                    break;
                }
            }
        }
    }
};


int main(){

    cout<<"Hello nextPermutation !"<<endl;

    return 0;
}