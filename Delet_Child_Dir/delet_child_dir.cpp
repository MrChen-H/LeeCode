/*
2023.2.8: 删除子目录

难度: Medium

你是一位系统管理员，手里有一份文件夹列表 folder，你的任务是要删除该列表中的所有 子文件夹，并以 任意顺序 返回剩下的文件夹。

如果文件夹 folder[i] 位于另一个文件夹 folder[j] 下，那么 folder[i] 就是 folder[j] 的 子文件夹 。

文件夹的「路径」是由一个或多个按以下格式串联形成的字符串：'/' 后跟一个或者多个小写英文字母。

例如，"/leetcode" 和 "/leetcode/problems" 都是有效的路径，而空字符串和 "/" 不是。

链接: https://leetcode.cn/problems/remove-sub-folders-from-the-filesystem/description/
*/

#include<iostream>
#include<vector>
#include<algorithm>

class Solution
{
public:
    std::vector<std::string> removeSubfolders(std::vector<std::string> &folder)
    {
        std::sort(folder.begin(),folder.end());

        std::vector<std::string> res={folder[0]};

        for(const auto it : folder)
        {
            std::string temp;
            for (int i = 0; i < it.size(); i++)
            {
 
                temp += it[i];
                if (temp.size() < res.back().size())
                {
                    continue;
                }
                if(it[i] == '/')
                {
                    temp.pop_back();
                    break;
                }
            }

            if(res.back() != temp)
            {
                res.push_back(it);
            }
        }
        return res;
    }
};

int main()
{
    std::vector<std::string> folder{"/a/b/c","/a/b/ca","/a/b/d"};

    Solution test;

    folder = test.removeSubfolders(folder);

    for(const auto it : folder)
    {
        std::cout << it<<" \n";
    }
}