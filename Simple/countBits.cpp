//
// Created by 94456 on 7/13/2022.
//


#include<iostream>
#include<vector>


using namespace std;


class Solution
{
public:
    // 比特位计数
    vector<int> countBits(int n)
    {
        // 建立数组存放二进制表示中1的个数

        // 数组初始化时
        // (x,y)  x:元素数  y:初始值
        // {x,y}  初始两个元素: x和y

        vector<int> count(n+1,0);
        // 遍历计算二进制表示中1的个数
        for(int i=1;i<=n;i++)
        {
            // 利用发现的规律进行比特位计数
            count[i]=count[i&(i-1)]+1;
        }
        // 返回保存比特位计数的数组
        return count;
    }
};


int main()
{

    printf("Hello countBits ! \n");

    vector<int> a(3,1);

    a[4]=6;

    for(int i=0;i<a.size();i++)
    {
        printf(to_string(a[i]).c_str());
    }

    return 0;
}