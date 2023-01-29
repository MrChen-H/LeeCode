/*
    给你一个字符串 s ，每 两个 连续竖线 '|' 为 一对 。换言之，第一个和第二个 '|' 为一对，第三个和第四个 '|' 为一对，以此类推。

    请你返回 不在 竖线对之间，s 中 '*' 的数目。

    注意，每个竖线 '|' 都会 恰好 属于一个对。
*/

#include<iostream>

class Solution
{
public:
    int countAsterisks(std::string s)
    {
        int Star_Number = 0;
        bool Line = true;
        for (auto it : s)
        {
            if (it == '|')
            {
                if (Line == true)
                {
                    Line = false;
                }
                else
                {
                    Line = true;
                }
            }
            else if (it == '*' && Line == true)
            {
                Star_Number++;
            }
        }
        return Star_Number;
    }
};

int main()
{
    Solution test;
    std::cout << test.countAsterisks("l|*e*et|c**o|*de|") << "\n";
    return 0;
}