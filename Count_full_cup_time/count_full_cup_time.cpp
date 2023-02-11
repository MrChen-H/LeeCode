/*

2023.2.11: 装满杯子需要的最短总时长

难度: easy

现有一台饮水机，可以制备冷水、温水和热水。每秒钟，可以装满 2 杯 不同 类型的水或者 1 杯任意类型的水。

给你一个下标从 0 开始、长度为 3 的整数数组 amount ，其中 amount[0]、amount[1] 和 amount[2] 分别表示需要装满冷水、温水和热水的杯子数量。返回装满所有杯子所需的 最少 秒数。

链接: https://leetcode.cn/problems/minimum-amount-of-time-to-fill-cups/description/
*/

#include<iostream>
#include<vector>
#include<algorithm>

class Solution
{

public:
    static int fillCups(std::vector<int>amount)
    {
        
        int res = 0;
        while(1)
        {
            std::sort(amount.begin(),amount.end());
            if (amount[2] > 0 && amount[1] > 0)
            {
                amount[2]--;
                amount[1]--;
                res++;
            }
            else if(amount[2]>0 && amount[0]>0)
            {
                amount[2]--;
                amount[0]--;
                res++;
            }
            else if(amount[2]>0)
            {
                amount[2]--;
                res++;
            }
            if (amount[0] <= 0 && amount[1] <= 0 && amount[2] <= 0)
            {
                return res;
            }
            
        }
        return res;
    }
};

int main()
{
    std::cout << Solution::fillCups({4,4,4})<<"\n";
    return 0;
}