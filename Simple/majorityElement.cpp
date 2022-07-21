//
// Created by 94456 on 7/10/2022.
//


#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<stack>



using namespace std;


class Solution_0
{
public:
    int mejorityElement(vector<int> &nums)
    {
        // map基于红黑树实现,查找的时间复杂度O(n)
        // map<int,int> visited;
        // unordered_map基于哈希表实现,查找的时间复杂度较低O(1)
        unordered_map<int,int> visited;

        // 遍历数组
        for(int i=0;i<nums.size();i++)
        {
            // 记录当前数字出现的次数
            visited[nums[i]]++;

            // 如果当前数字出现的次数大于数组长度的一半
            if(visited[nums[i]]>nums.size()/2)
            {
                // 则该数字是多数元素
                return nums[i];
            }
        }

        // 如果没有多数元素,返回-1
        return -1;

    }
};


class Solution_1
{
public:
    // 基于排序的方法
    // 多数元素的出现次数大于当前数组长度的一半
    // 因此排序后的数组中心位置必定是多数元素
    int majorityElement(vector<int> &nums)
    {

        // 需要#include<algorithm>
        // 对数组进行从小到大的排序
        sort(nums.begin(),nums.end());
        // 返回中位数
        return nums[nums.size()/2];

    }
};



class Solution_2
{
public:
    // 基于随机数的方法
    // 因为多数元素的出现次数大于当前数组长度的一半
    // 所以从数组中随机选一个数,这个数大概率就是我们要找的多数元素
    int majorityElement(vector<int> &nums)
    {
        // 在C/C++中,rand函数可以用来产生随机数,
        // 但是这不是真正意义上的随机数,是一个伪随机数.

        // 伪随机数是根据种子(seed)为基准以某个递推公式推算出来的一个系数,
        // 但这并不是真正的随机数.
        // 当计算机正常开机后,这个种子的值便固定下来.
        // 除非重新启动系统,否则这个种子的值并不会改变.

        // 因此,为了解决伪随机数的问题,C/C++提供了srand()函数,
        // 它的函数原型是 void srand(int a) ,可以用来改变这个种子的值.

        // time(nullptr)函数
        // 得到一个从1900年1月1日到现在的时间秒数,
        // 这样每一次运行程序的时间不同就可以保证产生不同的随机种子值,
        // 从而得到不同的随机数

        // 设置随机种子,确保每次得到不同的随机数
        srand(time(nullptr));

        // 直到返回多数元素后才停止循环
        while(true)
        {
            // 保存当前数组的长度
            int n=nums.size();
            // 统计随机数出现的次数
            int count=0;

            // 随机取出数组中的一个元素
            // C++中 rand()函数不需要参数，
            // 会返回一个从0到最大随机数的任意整数
            int random_integer=nums[rand()%n];

            // 遍历数组
            for(int nu:nums)
            {
                // 统计随机整数的出现次数
                if(nu==random_integer)
                {
                    count++;
                }
            }

            // 如果当前数字的出现次数大于数组长度的一半
            if(count>n/2)
            {
                // 则该数字是多数元素
                return random_integer;
            }
        }

    }
};


class Solution_3
{
public:
    // 基于随机数的方法
    // 因为多数元素的出现次数大于当前数组长度的一半
    // 所以从数组中随机选一个数,这个数大概率就是我们要找的多数元素
    int majorityElement(vector<int> &nums)
    {
        // 在C/C++中,rand函数可以用来产生随机数,
        // 但是这不是真正意义上的随机数,是一个伪随机数.

        // 伪随机数是根据种子(seed)为基准以某个递推公式推算出来的一个系数,
        // 但这并不是真正的随机数.
        // 当计算机正常开机后,这个种子的值便固定下来.
        // 除非重新启动系统,否则这个种子的值并不会改变.

        // 因此,为了解决伪随机数的问题,C/C++提供了srand()函数,
        // 它的函数原型是 void srand(int a) ,可以用来改变这个种子的值.

        // time(nullptr)函数
        // 得到一个从1900年1月1日到现在的时间秒数,
        // 这样每一次运行程序的时间不同就可以保证产生不同的随机种子值,
        // 从而得到不同的随机数

        // 设置随机种子,确保每次得到不同的随机数
        srand(time(nullptr));

        // 直到返回多数元素后才停止循环
        while(true)
        {
            // 保存当前数组的长度
            int n=nums.size();
            // 统计随机数出现的次数
            int count=0;

            // 随机取出数组中的一个元素
            // C++中 rand()函数不需要参数，
            // 会返回一个从0到最大随机数的任意整数
            int random_integer=nums[rand()%n];

            // 遍历数组
            for(int nu:nums)
            {
                // 统计随机整数的出现次数
                if(nu==random_integer)
                {
                    count++;
                }

                // 如果当前数字的出现次数大于数组长度的一半
                if(count>n/2)
                {
                    // 则该数字是多数元素
                    return random_integer;
                }

            }

        }

    }
};



class Solution_4
{
public:
    // 基于分治的方法
    // 每一次都把一个大区间划分为两个子区间,并分别寻找两个子区间的多数元素,并递归进行
    // 其中,大区间的多数元素肯定是子区间的多数元素之一

    // 统计子区间元素n的个数
    int Element_count(vector<int> &nums,int n,int left,int right)
    {
        // 记录元素n的个数
        int count=0;
        // 循环遍历子区间
        for(int i=left;i<=right;i++)
        {
            // 统计元素n的个数
            if(nums[i]==n)
            {
                count++;
            }
        }
        // 返回元素n的个数
        return count;
    }

    // 递归的寻找子区间的多数元素
    int sub_majorityElement(vector<int> &nums,int left,int right)
    {
        // 如果左边位置等于右边位置
        if(left==right)
        {
            // 此时子区间长度为1
            // 返回子区间本身的唯一元素
            return nums[left];
        }
        // 区间的中点
        int middle=(left+right)/2;

        // 递归寻找左边子区间的多数元素
        int sub_left=sub_majorityElement(nums,left,middle);
        // 递归寻找右边子区间的多数元素
        int sub_right=sub_majorityElement(nums,middle+1,right);

        // 判断左边子区间的多数元素是否为大区间的多数元素
        if(Element_count(nums,sub_left,left,right)>(right-left+1)/2)
        {
            // 如果是,则返回
            return sub_left;
        }
        // 判断右边子区间的多数元素是否为大区间的多数元素
        if(Element_count(nums,sub_right,left,right)>(right-left+1)/2)
        {
            // 如果是,则返回
            return sub_right;
        }

        // 如果没有多数元素,返回-1
        return -1;
    }

    int majorityElement(vector<int> &nums)
    {
        return sub_majorityElement(nums,0,nums.size()-1);
    }
};



class Solution_5
{
public:
    // Boyer - Moore 摩尔投票法

    // 候选人是众数,所以得票数一定是最多的
    // 赞成票一定大于反对票,最终众数胜出

    // 可以理解为:每个数为一队,打群架.
    // 两个不是一队的人,势均力敌,双双倒下.
    // 因为众数队人多,所以最后获胜的一定是众数队

    int majorityElement(vector<int> &nums)
    {
        // 记录当前的数
        int mode=-1;
        // 当前数的个数
        int count=0;

        // 遍历整个数组
        for(int nu:nums)
        {
            // 如果相同
            if(nu==mode)
            {
                // 当前数的个数+1
                count++;
            }
            else
            {
                // 如果不同,当前数的个数-1
                count--;
                // 如果当前数被消耗殆尽
                if(count<0)
                {
                    // 则将下一个数设置为当前的数
                    // 并设置个数为1
                    count=1;
                    mode=nu;
                }
            }
        }
        // 返回多数元素
        return mode;
    }
};


class Solution
{
public:
    // Boyer - Moore 基于栈的摩尔投票法

    // 候选人是众数,所以得票数一定是最多的
    // 赞成票一定大于反对票,最终众数胜出

    // 可以理解为:每个数为一队,打群架.
    // 两个不是一队的人,势均力敌,双双倒下.
    // 因为众数队人多,所以最后获胜的一定是众数队

    int majorityElement(vector<int> &nums)
    {

        // 建立一个栈来存放可能是多数元素的节点
        stack<int> visited;

        // 遍历整个数组
        for(int nu:nums)
        {

            // 若栈为空或当前元素等于栈顶元素
            if(visited.empty()||nu==visited.top())
            {
                // 当前元素进栈
                visited.push(nu);
            }
            // 若当前元素不等于栈顶元素
            else if(nu!=visited.top())
            {
                // 栈顶元素出栈
                visited.pop();
            }
        }

        // 返回栈顶元素
        // 此时栈中只剩下多数元素
        return visited.top();

    }
};



int main()
{

    printf("Test \n ");

    int a=time(nullptr);
    printf(to_string(a).c_str());

    return 0;
}