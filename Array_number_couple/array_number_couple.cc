/*
2023.2.16: 数组能形成多少数对

难度: easy

给你一个下标从 0 开始的整数数组 nums 。在一步操作中，你可以执行以下步骤：

从 nums 选出 两个 相等的 整数
从 nums 中移除这两个整数，形成一个 数对
请你在 nums 上多次执行此操作直到无法继续执行。

返回一个下标从 0 开始、长度为 2 的整数数组 answer 作为答案，其中 answer[0] 是形成的数对数目，answer[1] 是对 nums 尽可能执行上述操作后剩下的整数数目。

链接: https://leetcode.cn/problems/maximum-number-of-pairs-in-array/description/

题解思路: 利用hash_map
*/

#include<iostream>
#include<vector>
#include<unordered_map>

class Solution
{
public:
    static std::vector<int> numberOfPairs(std::vector<int> &nums)
    {
        std::vector<int> res;
        int res_number = 0;
        int res_late_number = 0;

        std::unordered_map<int, int> nums_map;

        for (const auto it_nums : nums)
        {
            if(nums_map.count(it_nums))
            {
                nums_map[it_nums]++;
            }
            else
            {
                nums_map[it_nums] = 1;
            }
        }
        for(const auto it_map : nums_map)
        {
            res_number += it_map.second / 2;
            res_late_number += it_map.second % 2;
        }
        res.push_back(res_number);
        res.push_back(res_late_number);
        return res;
    }
};
int main()
{
    std::vector<int> res{0};

    res = Solution::numberOfPairs(res);

    std::cout << res[0] << " " <<res[1]<<"\n";
    return 0;

}