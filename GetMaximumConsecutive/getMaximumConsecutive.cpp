/*

2023.2.4

你能构造出连续值的最大数目

难度:Medium

给你一个长度为 n 的整数数组 coins ，它代表你拥有的 n 个硬币。第 i 个硬币的值为 coins[i] 。如果你从这些硬币中选出一部分硬币，它们的和为 x ，那么称，你可以 构造 出 x 。

请返回从 0 开始（包括 0 ），你最多能 构造 出多少个连续整数。

你可能有多个相同值的硬币。

链接:https://leetcode.cn/problems/maximum-number-of-consecutive-values-you-can-make/description/

*/

#include<iostream>
#include<vector>
#include<algorithm>

class Solution
{
public:
    int getMaximumConsecutive(std::vector<int> &coins)
    {
        std::sort(coins.begin(),coins.end());

        int res = 0;    //初始可构造0

        for(auto it_coins : coins)
        {
            if(it_coins > res+1)  //无法连续
            {
                break;
            }

            res += it_coins;
        }

        return res + 1;
    }
};

int main()
{
    std::vector<int> arr{1, 3};

    Solution test;

    std::cout<< test.getMaximumConsecutive(arr)<<"\n";

    return 0;
}