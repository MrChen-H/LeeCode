#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

/*
2023.2.7: 警告一小时内使用相同员工卡大于等于三次的人

难度: Medium

力扣公司的员工都使用员工卡来开办公室的门。每当一个员工使用一次他的员工卡，安保系统会记录下员工的名字和使用时间。如果一个员工在一小时时间内使用员工卡的次数大于等于三次，这个系统会自动发布一个 警告 。

给你字符串数组 keyName 和 keyTime ，其中 [keyName[i], keyTime[i]] 对应一个人的名字和他在 某一天 内使用员工卡的时间。

使用时间的格式是 24小时制 ，形如 "HH:MM" ，比方说 "23:51" 和 "09:49" 。

请你返回去重后的收到系统警告的员工名字，将它们按 字典序升序 排序后返回。

请注意 "10:00" - "11:00" 视为一个小时时间范围内，而 "23:51" - "00:10" 不被视为一小时内，因为系统记录的是某一天内的使用情况。

链接: https://leetcode.cn/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/description/

*/

class Solution
{
public:
    static std::vector<std::string> alertNames(std::vector<std::string> &keyName, std::vector<std::string> &keyTime)    //static 只是为了方便测试
    {
        std::map<std::string, std::vector<int>> Emp_Map;    //绑定员工和使用时间

        for (int i = 0; i < keyTime.size(); i++)            
        {
            int Use_Time = 0;

            Use_Time = ((keyTime[i][0] - '0') * 10 + (keyTime[i][1] - '0')) * 60 + ((keyTime[i][3] - '0') * 10 + (keyTime[i][4]) - '0');    //将时间换算成对应的分钟数

            Emp_Map[keyName[i]].emplace_back(Use_Time);     //写入表中
        }

        std::vector<std::string> res;//结果

        for(auto &[name,time_list] : Emp_Map)//结构化绑定
        {
            std::sort(time_list.begin(),time_list.end());//进行排序

            for (int i = 2; i < time_list.size();i++)//每当连续三次使用最小值和最大值差值小于或等于60符合条件,将对应员工名字插入结果中    
            {
                //以下三条语句计算差值
                int time_1 = time_list[i - 2];

                int time_2 = time_list[i];

                int res_time = time_2 - time_1;

                if(res_time <= 60)//符合条件退出
                {
                    res.push_back(name);//插入结果

                    break;
                }
            }
        }
        return res;//注: 该程序直接运行使用临时vector会导致段错误
    }
};

int main()
{
    std::vector<std::string> test_name{"daniel", "daniel", "daniel", "luis", "luis", "luis", "luis"};
    std::vector<std::string> test_time{"10:00", "10:40", "11:00", "09:00", "11:00", "13:00", "15:00"};

    std::vector<std::string> Test_Arr= Solution::alertNames(test_name, test_time);

    for(const auto it : Test_Arr)
    {
        std::cout << it << " \n";
    }
    return 0;
}