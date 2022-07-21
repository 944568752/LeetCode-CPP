//
// Created by 94456 on 7/8/2022.
//


#include<iostream>
#include<vector>


using namespace std;


class Solution
{
public:
    // 买卖股票的最佳时机
    int maxProfit(vector<int> &prices)
    {

        // 全局股票价格的最小值
        int minprice=prices[0];
        // 全局股票收益的最大值
        int maxprofit=0;

        // 遍历数组
        for(int i=1;i<prices.size();i++)
        {
            // 更新全局股票价格的最小值
            minprice=min(minprice,prices[i]);
            // 更新全局股票收益的最大值
            maxprofit=max(maxprofit,prices[i]-minprice);
        }

        // 返回全局的最大股票收益
        return maxprofit;

    }
};


int main()
{

    printf("Test ! \n");

    return 0;
}