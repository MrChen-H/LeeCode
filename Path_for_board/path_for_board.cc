#include<iostream>
/*

2023.2.12: 字母板上的路径

难度:Medium

我们从一块字母板上的位置 (0, 0) 出发，该坐标对应的字符为 board[0][0]。

在本题里，字母板为board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"]，如下所示。

                             'a','b','c','d','e'
                             'f','g','h','i','j'
                             'k','l','m','n','o'
                             'p','q','r','s','t'
                             'u','v','w','x','y'
                             'z'

我们可以按下面的指令规则行动：

如果方格存在，'U' 意味着将我们的位置上移一行；
如果方格存在，'D' 意味着将我们的位置下移一行；
如果方格存在，'L' 意味着将我们的位置左移一列；
如果方格存在，'R' 意味着将我们的位置右移一列；

'!' 会把在我们当前位置 (r, c) 的字符 board[r][c] 添加到答案中。

（注意，字母板上只存在有字母的位置。）

返回指令序列，用最小的行动次数让答案和目标 target 相同。你可以返回任何达成目标的路径。

链接：https://leetcode.cn/problems/alphabet-board-path/description/

本题解思路: 直接模拟

*/
class Solution 
{
    public:
    static std::string alphabetBoardPath(std::string target) 
        {
            std::pair<int,int> index;
            auto &[ row, line ] = index;//机构化绑定两个坐标

            std::pair<int, int> index_2;
            auto &[row_goal, line_goal] = index_2;

            row = 0;//行坐标初始化
            line = 0;//列坐标初始化

            std::string res;//结果字符串
            for (const auto it : target)//遍历目标字符串
            {
                row_goal = (it - 'a') / 5;//获取字符目标行坐标
                line_goal = (it - 'a') % 5;//获取目标列坐标

                if(row == row_goal && line == line_goal)//当目标坐标与当前坐标重叠直接处理优化
                {
                    res += '!';
                    continue;
                }
                if(row == 5 && line == 0)//处理当当前坐标为 'z' 的特殊情况
                {
                    res += 'U';
                    row--;
                }
                if(row == row_goal)//目标字符坐标与当前坐标处于同一行
                {
                    line > line_goal ? res.append(line - line_goal, 'L') : res.append(line_goal - line, 'R');
                    res += '!';
                }
                else if(line == line_goal)//目标字符与当前字符处于同一列
                {
                    row > row_goal ? res.append(row-row_goal,'U'):res.append(row_goal - row,'D');
                    res += '!';
                }
                else//不在一行也不在一列
                {
                    if(line > line_goal)//先将当前坐标移动到和目标坐标同一列
                    {
                        res.append(line - line_goal,'L');
                        row > row_goal ? res.append(row - row_goal, 'U') : res.append(row_goal - row, 'D');//再将当前坐标移动到目标坐标
                        res += '!';
                    }
                    else
                    {
                        res.append(line_goal - line, 'R');
                        row > row_goal ? res.append(row - row_goal, 'U') : res.append(row_goal - row, 'D');
                        res += '!';
                    }
                }
                row = row_goal;//更新当前坐标
                line = line_goal;
            }
            return res;
        }
};


int main()
{
    std::string res=Solution::alphabetBoardPath("zb");
    std::cout << res<<"\n";

    return 0;
}