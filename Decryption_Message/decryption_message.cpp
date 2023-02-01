/*
2023.2.1
题目: 解密消息

难度: easy

给你字符串 key 和 message ，分别表示一个加密密钥和一段加密消息。解密 message 的步骤如下：

使用 key 中 26 个英文小写字母第一次出现的顺序作为替换表中的字母 顺序 。
将替换表与普通英文字母表对齐，形成对照表。
按照对照表 替换 message 中的每个字母。
空格 ' ' 保持不变。
例如，key = "happy boy"（实际的加密密钥会包含字母表中每个字母 至少一次），据此，可以得到部分对照表（'h' -> 'a'、'a' -> 'b'、'p' -> 'c'、'y' -> 'd'、'b' -> 'e'、'o' -> 'f'）。
返回解密后的消息。

*/

#include<map>
#include<iostream>

class Solution
{
public:
    std::string decodeMessage(std::string key, std::string message)
    {
        std::map<char,char> Map_Key;        //创建Map对照表
        
        char Key_value='a';                 //May Value 初始值为 a
        
        for(auto it_Key : key)              //遍历 key
        {
            if (it_Key == ' ')              //如果 key 有空格则跳过
            {
                continue;
            }
               
            if (Map_Key.count(it_Key) == 0) 
            {
                Map_Key.insert(std::make_pair(it_Key, Key_value)); 
                Key_value++;
            }

            if (Key_value == 'z' + 1)        //当26个字母都成功插入Map退出该循环
            {
                break;
            }
        }

        for (auto it_Mes = message.begin(); it_Mes != message.end();it_Mes++)   //遍历 Message 准备解密
        {
            if(*it_Mes == ' ')  //为空格跳过
            {
                continue;
            }
            *it_Mes = Map_Key.at(*it_Mes);
        }
        return message;
    }
};

int main()
{
    Solution test;
    std::cout << test.decodeMessage("eljuxhpwnyrdgtqkviszcfmabo", "zwx hnfx lqantp mnoeius ycgk vcnjrdb")<<"\n";
    return 0;
}