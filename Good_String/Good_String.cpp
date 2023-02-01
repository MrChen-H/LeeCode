/*
给你一个由英文字母组成的字符串 s ，请你找出并返回 s 中的 最好 英文字母。返回的字母必须为大写形式。如果不存在满足条件的字母，则返回一个空字符串。

最好 英文字母的大写和小写形式必须 都 在 s 中出现。

英文字母 b 比另一个英文字母 a 更好 的前提是：英文字母表中，b 在 a 之 后 出现。

链接: https://leetcode.cn/problems/greatest-english-letter-in-upper-and-lower-case/
*/

#include<iostream>
#include<algorithm>

class Solution
{
public:
    std::string greatestLetter(std::string s)
    {
        std::string Res{"\0"};
        for(auto it : s)
        {
            if (s.find(toupper(it)) != s.npos && s.find(tolower(it)) != s.npos)
            {
                Res.push_back(it);
            }
        }
        std::sort(Res.begin(),Res.end());
        if(Res.back()=='\0')
        {
            return Res;
        }
        if (Res.back() >= 'A' && Res.back() <= 'Z')
        {
            
            return std::string(1,Res.back());
        }
        else
        {

            return std::string(1,Res.back()-32);
        }
        return Res;
    }
};

int main()
{
    std::string Good_str;
    std::cin >> Good_str;

    Solution test;
    std::cout << test.greatestLetter(Good_str);
}
