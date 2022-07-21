//
// Created by 94456 on 7/6/2022.
//


#include<iostream>
#include<vector>


using namespace std;


class Solution_0
{
public:
    // 每一层楼梯，都有两种方法可以到达
    // 即:从前一阶过来或者从前两阶过来
    int climbStairs(int n)
    {
        // 每次上一层或两层,则
        // 第一层:1种方法
        // 第二层:2种方法
        // 第三层:(1+2=3)种方法(从第一层上来(1种)+从第二层上来(2种))
        // 第四层:(2+3=5)种方法(从第二层上来(2种)+从第三层上来(3种))
        // ...
        // 第n层:从第(n-2)层上来+从第(n-1)层上来
        if(n<=3)
        {
            return n;
        }

        // 预先分配内存,储存每一层的值
        // 直到找到目标楼层可能的方法数
        vector<int> result(n+1);
        result[0]=0;
        result[1]=1;
        result[2]=2;

        for(int i=3;i<=n;i++)
        {
            result[i]=result[i-1]+result[i-2];
        }

        return result[n];
    }
};


class Solution
{
public:
    // 每一层楼梯，都有两种方法可以到达
    // 即:从前一阶过来或者从前两阶过来
    int climbStairs(int n)
    {
        // 每次上一层或两层,则
        // 第一层:1种方法
        // 第二层:2种方法
        // 第三层:(1+2=3)种方法(从第一层上来(1种)+从第二层上来(2种))
        // 第四层:(2+3=5)种方法(从第二层上来(2种)+从第三层上来(3种))
        // ...
        // 第n层:从第(n-2)层上来+从第(n-1)层上来
        if(n<=3)
        {
            return n;
        }

        int result;

        // 递归查找n-1层和n-2层可能的方法数
        result=climbStairs(n-1)+climbStairs(n-2);

        return result;
    }
};


int main()
{

    printf("test\n");

    return 0;
}





