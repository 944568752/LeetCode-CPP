//
// Created by 94456 on 7/5/2022.
//


#include<iostream>
#include<climits>
#include<vector>

using namespace std;

class Solution_0
{
public:
    // 贪心
    // 在遍历的过程中一直加，如果和为负数，则跳过该序列
    // 只有和为正数的序列才有可能成为最大连续子序列
    int maxSubArray(vector<int> &nums)
    {
        // int max_result=INT_MIN;
        // int max_result=nums[0];

        // 给最大结果赋最小值
        int max_result=INT_MIN;
        int sum=0;

        // 遍历求和
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums.at(i);
            // 每加一个数字，判断当前子序列和sum是否比当前最大子序列和max_result大
            // 如果大，则当前子序列和sum代替当前最大子序列和max_result
            if(sum>max_result)
            {
                max_result=sum;
            }
            // 如果当前子序列和sum为负数，则跳过当前子序列重新开始
            if(sum<0)
            {
                sum=0;
            }
        }
        // 返回最大子序列和
        return max_result;
    }
};


class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // 将输入序列的第一个值作为最大结果的初始值
        int max_result=nums[0];
        // 定义一个向量来存储当前连续子序列的最大和
        // dp[i]表示以nums[i]为结尾的连续子序列的最大和
        vector<int> dp(nums.size());
        dp[0]=nums[0];

        // 遍历求和
        for(int i=1;i<nums.size();i++)
        {
            // 保存当前子序列的最大和
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            // 以nums[i]为结尾的当前连续子序列的最大和与当前最大子序列和比较
            // 如果大，则成为当前最大子序列和
            max_result=max(max_result,dp[i]);
        }
        // 返回最大子序列和
        return max_result;
    }
};

int main()
{
    vector<int> a={-2,1,-3,4,-1,2,1,-5,4};

    Solution s;

    int d=s.maxSubArray(a);

    printf("%d\n",d);

    vector<int> *b=&a;

    int c=b->at(0);

    printf("%d\n",a[0]);

    printf("%d",INT_MIN);
    return 0;
}