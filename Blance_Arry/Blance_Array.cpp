#include<iostream>
#include<vector>

class Solution
{
public:
    int waysToMakeFair(std::vector<int> &nums)
    {
        int Res_sum = 0;                //返回的结果数

        int Odd_Sum = 0;                //单数下标和
        int Even_Sum = 0;                //双数下标和

        int Odd_Sum2 = 0; 
        int Even_Sum2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 != 0)
            {
                Odd_Sum += nums[i];
            }
            else
            {
                Even_Sum += nums[i];
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 != 0)
            {
                Odd_Sum -= nums[i];
            }
            else
            {
                Even_Sum -= nums[i];
            }

            if (Odd_Sum + Even_Sum2 == Odd_Sum2 + Even_Sum)
            {
                Res_sum++;
            }

            if (i % 2 != 0)
            {
                Odd_Sum2 += nums[i];
            }
            else
            {
                Even_Sum2 += nums[i];
            }
        }
        return Res_sum;
    }
};

int main()
{
    Solution arr;
    std::vector<int> test{2, 1, 6, 4};
    std::cout << arr.waysToMakeFair(test)<<std::endl;

    return 0;
}