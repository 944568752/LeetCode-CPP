#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution
{
public:
    // 输入:整数数组+整数目标值
    // 输出:组成目标整数的两个数组元素的下标（任意顺序）
    vector<int> twoSum(vector<int> &nums,int target)
    {
        // unordered_map基于哈希表实现，查找的时间复杂度较低O(1)
        unordered_map<int,int> m;
        // map基于红黑树实现，查找的时间复杂度O(n)
        for(int i=0;i<nums.size();i++)
        {
            // 遍历，如果能组成目标整数，则输出下标
            if(m.count(target-nums[i]))
            {
                return {m[target-nums[i]],i};
            }

            // 将前面查找过的数据存入unordered_map,以便与后面未查找过的数据匹配
            m[nums[i]]=i;
        }
        // 未找到则返回空
        return {};
    }
};

int main()
{
    vector<int> nums={2,7,11,15};
    int target=9;

    Solution s;

    vector<int> c;
    c=s.twoSum(nums,target);

    for(int i=0;i<c.size();i++)
    {
        printf("Location : %d \n",c[i]);
    }

}