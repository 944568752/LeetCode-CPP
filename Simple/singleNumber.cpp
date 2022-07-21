//
// Created by 94456 on 7/8/2022.
//


#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>



using namespace std;


class Solution_0
{
public:
    // 基于哈希表的方法
    int singleNumber(vector<int> &nums)
    {
        // map基于红黑树实现,查找的时间复杂度O(n)
        // map<int,int> arr;

        // unordered_map基于哈希表实现,查找的时间复杂度较低O(1)
        unordered_map<int,int> arr;

        // 遍历数组
        for(int i=0;i<nums.size();i++)
        {
            // 用哈希表存储每个数组的出现次数
            arr[nums[i]]++;
        }

        // 遍历数组
        for(int i=0;i<nums.size();i++)
        {
            // 找出哈希表中只出现一次的数字
            if(arr[nums[i]]==1)
            {
                // 返回该数字
                return nums[i];
            }
        }
        // 没有则返回0
        return 0;

    }
};


class Solution
{
public:
    // 基于异或运算的方法
    int singleNumber(vector<int> &nums)
    {

        // 保存最终的结果
        int result_number=nums[0];

        // 遍历数组
        for(int i=1;i<nums.size();i++)
        {
            // 进行异或运算
            result_number^=nums[i];
        }

        // 返回最终的结果
        return result_number;
    }
};


int main()
{

    printf("Test ! \n ");


    int a=2;
    int b=6;

    int c=a^b;

    printf(to_string(c).c_str());

    return 0;
}




