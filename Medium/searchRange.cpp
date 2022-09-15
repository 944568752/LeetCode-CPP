//
// Created by Brian_Tsui on 2022.09.13.
//


// searchRange


#include<iostream>
#include<bits/stdc++.h>
#include<vector>


using namespace std;


class Solution{
public:
    // 在排序数组中查找元素的第一个和最后一个位置
    vector<int> searchRange(vector<int> &nums,int target){
        // 记录排序数组的长度
        int n=nums.size();
        // 记录元素在排序数组中的第一个和最后一个位置
        vector<int> result={n-1,0};

        // 如果数组的长度小于1
        // 返回{-1,-1}
        if(n<1){
            result[0]=-1;
            result[1]=-1;
            return result;
        }


        // 首先查找元素的第一个位置

        // 左指针
        int left=0;
        // 右指针
        int right=n-1;
        // 在右指针指向左指针的左边之前,持续遍历
        while(left<=right){
            // 计算二分的中间位置
            int middle=(left+right)/2;
            // 如果中间位置的值等于目标值
            if(nums[middle]==target){
                // 则元素的第一个位置更新
                result[0]=middle;
                // 右指针指向中间位置的左边
                // 以查找更往前的位置
                right=middle-1;
            }
            // 如果中间位置的值大于目标位置
            else if(nums[middle]>target){
                // 右指针指向中间位置的左边
                // 向左边查找更小的数
                right=middle-1;
            }
            // 如果中间位置的值大于目标位置
            else if(nums[middle]<target){
                // 左指针指向中间位置的右边
                // 向右边查找更大的数
                left=middle+1;
            }
        }


        // 其次查找元素的最后一个位置

        // 重新初始化左右指针的值
        left=0;
        right=n-1;
        // 在右指针指向左指针的左边之前,持续遍历
        while(left<=right){
            // 计算二分的中间位置
            int middle=(left+right)/2;
            // 如果中间位置的值等于目标值
            if(nums[middle]==target){
                // 则元素的最后一个位置更新
                result[1]=middle;
                // 左指针指向中间位置的右边
                // 以查找更往后的位置
                left=middle+1;
            }
            // 如果中间位置的值大于目标位置
            else if(nums[middle]>target){
                // 右指针指向中间位置的左边
                // 向左边查找更小的数
                right=middle-1;
            }
            // 如果中间位置的值小于目标位置
            else if(nums[middle]<target){
                // 左指针指向中间位置的右边
                // 向左边查找更大的数
                left=middle+1;
            }
        }

        // 如果查找完毕后,第一个位置或最后一个位置不是目标数值(为默认值)
        // 返回{-1,-1}
        if(nums[result[0]]!=target||nums[result[1]]!=target){
            result[0]=-1;
            result[1]=-1;
            return result;
        }
        else {
            // 如果第一个位置和最后一个位置都是目标值
            // 则意味着查找成功
            return result;
        }
    }
};


int main(){

    // 数组初始化
    vector<int> a(4,3);
    vector<int> b={1,2,3};

    // 列表初始化
    int c[3]={1,3,2};
    int d[]={1,2};
    int e[3]={};

    int f[8];
    memset(f,-1,sizeof(f));


    vector<int> input={5,7,7,8,8,10};
    Solution *s=new Solution();
    vector<int> result(2);
    result=s->searchRange(input,8);

    cout<<result[0]<<' '<<result[1]<<endl;


    cout<<"Hello searchRange !"<<endl;

    return 0;
}