//
// Created by Brian_Tsui on 2022.09.12.
//


// Search



#include<iostream>
#include<vector>


using namespace std;


class Solution{
public:
    // 搜索旋转排序数组
    int search(vector<int> &nums,int target){
        // 记录输入的数组长度
        int n=nums.size();
        // 如果输入的数组长度为0
        if(n==0){
            // 返回-1
            return -1;
        }
        // 如果输入的数组长度为1
        if(n==1){
            // 判断数组中唯一的数是否为目标值
            if(nums[0]==target){
                // 如果数组中唯一的数是目标值
                // 返回0
                return 0;
            }
            else{
                // 如果数组中唯一的数不是目标值,返回-1
                return -1;
            }
        }

        // 左
        int left=0;
        // 右
        int right=n-1;
        // 在左边小于等于右边的条件下
        // 持续循环
        while(left<=right){
            // 计算中点位置
            int middle=(left+right)/2;
            // 如果中点的值等于目标值
            // (如果left==right,此时亦满足该条件)
            if(nums[middle]==target){
                // 则返回中点的下标
                return middle;
            }
            // 如果左边的值小于中点的值
            // 这意味着左边是有序的,未经旋转
            if(nums[left]<=nums[middle]) {
                // 如果目标值在左边的范围内
                if (nums[left] <= target && nums[middle] >= target) {
                    // 此时的右边更新为中点-1
                    right = middle - 1;
                }
                else{
                    // 如果不在范围内,
                    // 则此时左边更新为中点+1
                    // 继续查找
                    left=middle+1;
                }
            }
            // 这意味着左边经过了旋转,右边是有序的
            else{
                // 如果目标值在右边的范围内
                if(nums[right]>=target&&nums[middle]<=target){
                    // 此时左边更新为中点+1
                    left=middle+1;
                }
                else{
                    // 如果目标值不再左右边的范围内
                    // 此时右边更新为中点-1
                    right=middle-1;
                }
            }
        }
        // 如果循环结束后仍然没有结果
        // 返回-1
        return -1;
    }
};


int main(){

    Solution *s=new Solution();

    vector<int> a={5,6,7,1,2,3,4};
    vector<int> c={3,1};

    int b=s->search(a,5);

    cout<<b<<endl;


    cout<<"Hello search !"<<endl;

    int d=0;
    char e[]="Hello world!";
    cout<<sizeof(e)<<endl;

    int f[1];
    cout<<sizeof(f)<<endl;

    return 0;
}