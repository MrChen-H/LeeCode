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