/*

2023.2.20: 最好的扑克手牌
难度: easy

给你一个整数数组 ranks 和一个字符数组 suit 。你有 5 张扑克牌，第 i 张牌大小为 ranks[i] ，花色为 suits[i] 。

下述是从好到坏你可能持有的 手牌类型 ：

"Flush"：同花，五张相同花色的扑克牌。
"Three of a Kind"：三条，有 3 张大小相同的扑克牌。
"Pair"：对子，两张大小一样的扑克牌。
"High Card"：高牌，五张大小互不相同的扑克牌。
请你返回一个字符串，表示给定的 5 张牌中，你能组成的 最好手牌类型 。

注意：返回的字符串 大小写 需与题目描述相同。



示例 1：

输入：ranks = [13,2,3,1,9], suits = ["a","a","a","a","a"]
输出："Flush"
解释：5 张扑克牌的花色相同，所以返回 "Flush" 。
示例 2：

输入：ranks = [4,4,2,4,4], suits = ["d","a","a","b","c"]
输出："Three of a Kind"
解释：第一、二和四张牌组成三张相同大小的扑克牌，所以得到 "Three of a Kind" 。
注意我们也可以得到 "Pair" ，但是 "Three of a Kind" 是更好的手牌类型。
有其他的 3 张牌也可以组成 "Three of a Kind" 手牌类型。

链接:https://leetcode.cn/problems/best-poker-hand/description/

备注: 程序可以优化

*/

#include<iostream>
#include<unordered_map>
#include<vector>

class Solution
{
public:
    static std::string bestHand(std::vector<int> &ranks, std::vector<char> &suits)
    {
        std::unordered_map<int,int> number_map;
        std::unordered_map<char, int> suits_map;

        for (int i = 0; i < ranks.size(); i++)
        {
            number_map[ranks[i]]++;
            suits_map[suits[i]]++;
        }
        int num = 0;
        int fl = 0;

        for (int i = 0; i < ranks.size();i++)
        {
            if(number_map[ranks[i]]>num)
            {
                num = number_map[ranks[i]];
            }
            if(suits_map[suits[i]]>fl)
            {
                fl = suits_map[suits[i]];
            }
        }

        if (fl == (unsigned)5)
        {
            return "Flush";
        }
        if (num >= (unsigned)3)
        {
            return "Three of a kind";
        }
        if (num >= (unsigned)2)
        {
            return "Pair";
        }


        return "High Card";
    }
};

int main()
{
    std::vector<int> tes_num{2, 1, 2, 1, 1};
    std::vector<char> suits{'a', 'a', 'a', 'a', 'a'};

    std::cout << Solution::bestHand(tes_num,suits)<<"\n";
}