//
// Created by 94456 on 7/21/2022.
//


#include<iostream>


using namespace std;


class Solution_0
{
public:
    // 汉明距离
    int hammingDistance(int x,int y)
    {
        // 现将x与y异或
        // 相同为0,不同为1
        int n = x^y;
        // 统计不同数目的个数
        int count=0;
        // 当n大于0时,不断的右移
        while(n>0)
        {
            // 与1进行与操作
            // 仅有1&1=1,其他的都为0
            // 因此该操作可以判断当前n的最后一位是否为1
            count+=n&1;
            // 右移一位
            n>>=1;
        }
        // 返回不同数目的个数
        return count;
    }
};


class Solution
{
public:
    // 汉明距离
    int hammingDistance(int x,int y)
    {
        // 统计不同数目的个数
        int count = 0;
        // 当x或y不为零时,不断的右移
        while(x!=0||y!=0)
        {
            // 与1进行与操作
            // 仅有1&1=1,其他的都为0
            // 因此该操作可以判断当前n的最后一位是否为1

            // 分别取x和y的最后一位

            // 对x和y的最后一位进行异或操作
            // 判断两数是否相同
            count+=(x&1)^(y&1);
            // x右移
            x>>=1;
            // y右移
            y>>=1;
        }
        // 返回不同数目的个数
        return count;
    }
};



int main()
{

    int a=6;

    int b=7;

    b=b<<1;

    cout<<b<<endl;

    printf("Hello HammingDistance ! \n");

    return 0;
}