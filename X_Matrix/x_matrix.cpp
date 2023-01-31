#include<iostream>
#include<vector>
/*
题目: 判断矩阵是否是一个 X 矩阵

难度:easy

如果一个正方形矩阵满足下述 全部 条件，则称之为一个 X 矩阵 ：

矩阵对角线上的所有元素都 不是 0
矩阵中所有其他元素都是 0

给你一个大小为 n x n 的二维整数数组 grid ，表示一个正方形矩阵。如果 grid 是一个 X 矩阵 ，返回 true ；否则，返回 false 。

链接: https://leetcode.cn/problems/check-if-matrix-is-x-matrix/description/
*/

class Solution
{
public:
    bool checkXMatrix(std::vector<std::vector<int>> &grid)
    {
        for (int Row = 0; Row < grid.size(); Row++)
        {
            for (int Line = 0; Line < grid[Row].size(); Line++)
            {
                if (Line == Row || Line == grid[Row].size()-1-Row) //如果对角线有0 返回false
                {
                    if(grid[Row][Line] == 0)
                    {
                        return false;
                    }
                }
                else if( grid[Row][Line] != 0)  //其他地方没 0 返回false
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    std::vector<std::vector<int>> test(4);
    test = {{2, 0, 0, 1}
          , {0, 3, 1, 0}
          , {0, 5, 2, 0}
          , {4, 0, 0, 2}
          };

    Solution temp;
    std::cout << temp.checkXMatrix(test)<<"\n";
    return 0;
}

/*
//测试用例
[[2,0,0,1],[0,3,1,0],[0,5,2,0],[4,0,0,2]]
*/