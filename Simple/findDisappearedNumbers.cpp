//
// Created by 94456 on 7/14/2022.
//


#include<iostream>
#include<vector>


using namespace std;


class Solution
{
public:
    // 找到数组中消失的数字
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        // 记录数组长度
        int length=nums.size();
        // 记录数组中消失的数字
        vector<int> result;

        // 遍历数组,记录数组中出现过的数字
        for(int i=0;i<length;i++)
        {
            // 按照发现的规律在对应索引的值处进行记录
            nums[(nums[i]-1)%length]+=length;
        }

        // 遍历数组,记录数组中消失的数字
        for(int i=0;i<length;i++)
        {
            // 如果遍历之后数组中某个值仍然小于数组长度
            if(nums[i]<=length)
            {
                // 则该索引+1 便是数组中消失的数字
                result.push_back(i+1);
            }
        }
        // 返回记录数组中消失数字的数组
        return result;

    }
};


int main()
{

    printf("Hello findDisappearedNumbers ! \n");

    return 0;
}