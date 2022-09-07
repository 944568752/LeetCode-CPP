//
// Created by Brian_Tsui on 2022.09.07.
//


// threeSum


#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


class Solution{
public:
    // 三数之和
    vector<vector<int>> threeSum(vector<int> &nums){
        // 记录三元组结果的数组
        vector<vector<int>> result;
        // 给定数组长度
        int n=nums.size();
        // 如果给定数组的长度小于3
        if(n<3){
            // 则必然不存在不重复的三元组
            // 返回空数组
            return result;
        }

        // sort是algorithm库下的一个函数
        // 用来对数组元素进行排序
        sort(nums.begin(),nums.end());

        // 如果排序后的数组第一个数(最小值)大于0或最后一个数(最大值)小于0
        // 则必不可能实现和为0的要求
        if(nums[0]>0||nums[n-1]<0){
            // 返回空数组
            return result;
        }

        // 遍历排序后的给定数组
        for(int i=0;i<n-2;i++){
            // 如果当前的数字已经大于0
            // 则后两个数字必然大于0
            // 则必然不能实现和为0的要求
            if(nums[i]>0){
                // 此时终止循环
                break;
            }
            // 如果当前数字在前面已经遍历过
            if(i>0&&nums[i]==nums[i-1]){
                // 则跳过本次循环
                continue;
            }

            // 确定当前数字后,为了实现和为0的要求
            // 记录另外两个数字需要满足的条件
            int residual_sum=0-nums[i];

            // 左指针
            int left=i+1;
            // 右指针
            int right=n-1;
            // 如果右指针在左指针之后,则持续遍历
            while(left<right){
                // 如果另外两个数字满足条件
                if(nums[left]+nums[right]==residual_sum){
                    // 建立一个子数组来保存符合要求的三元组
                    vector<int> sub_result;
                    // 将三元组存入子数组
                    sub_result.push_back(nums[i]);
                    sub_result.push_back(nums[left]);
                    sub_result.push_back(nums[right]);

                    // 将子数组存入结果三元组数组
                    result.push_back(sub_result);

                    // 左指针向前移动
                    left++;
                    // 右指针向后移动
                    right--;

                    // 如果在移动后,左指针指向的数与移动之前相同
                    while(left<right&&nums[left]==nums[left-1]){
                        // 继续向右移动
                        left++;
                    }
                    // 如果在移动后,右指针指向的数与移动之前相同
                    while(left<right&&nums[right]==nums[right+1]){
                        // 继续向左移动
                        right--;
                    }
                }
                // 如果另外两个数字不满足条件,且比应满足的条件小
                else if(nums[left]+nums[right]<residual_sum){
                    // 左指针向右移动
                    left++;
                }
                // 如果另外两个数字不满足条件,且比应满足的条件大
                else if(nums[left]+nums[right]>residual_sum){
                    // 右指针向左移动
                    right--;
                }

            }

        }
        // 返回记录三元组结果的数组
        return result;

    }
};


int main(){

    cout<<"Hello threeSum !"<<endl;

    return 0;
}