//
// Created by 94456 on 7/13/2022.
//


#include<iostream>
#include<vector>


using namespace std;


class Solution_0
{
public:
    // 基于双指针的移动零方法
    void moveZeros(vector<int> &nums)
    {
        // 记录数组的长度
        int n=nums.size();

        // 已经移动好的值
        int low=0;
        // 当前指向的值
        int high=0;

        // 遍历整个数组
        while(high<n)
        {
            // 如果当前的值不为0
            if(nums[high]!=0)
            {
                // 则将不为0的值移动到前面
                swap(nums[low],nums[high]);
                // 已经移动好的区域+1
                low++;
            }
            // 遍历下一个值
            high++;
        }

    }
};



class Solution
{
public:
    // 基于记录个数的移动零方法
    void moveZeroes(vector<int> &nums)
    {
        // 记录数组中0的个数
        int zero_count=0;

        // 遍历数组
        for(int i=0;i<nums.size()+zero_count;i++)
        {
            // 如果数组遍历完毕
            if(i>=nums.size())
            {
                // 将数组对应的后部标记为0
                nums[i-zero_count]=0;
            }
            // 如果数组未遍历完毕,且当前值为0
            else if(nums[i]==0)
            {
                // 数组中0的个数+1
                zero_count++;
            }
            // 如果数组未遍历完毕,且当前值不为0
            else
            {
                // 将不为0的值移动到前面0的位置
                nums[i-zero_count]=nums[i];
            }
        }

    }
};


int main()
{

    printf("Hello moveZeroes ! \n");


    return 0;
}