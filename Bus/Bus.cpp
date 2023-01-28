/*
环形公交路线上有 n 个站，按次序从 0 到 n - 1 进行编号。我们已知每一对相邻公交站之间的距离，distance[i] 表示编号为 i 的车站和编号为 (i + 1) % n 的车站之间的距离。

环线上的公交车都可以按顺时针和逆时针的方向行驶。

返回乘客从出发点 start 到目的地 destination 之间的最短距离。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/distance-between-bus-stops
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using std::vector;
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int Bsum = 0;
        int sum = 0;
        for (int i = 0; i < distance.size(); i++)
        {
            Bsum += distance[i];
        }
        /*for (int i=start;i<destination;i++)//顺时针路径
        {
            sum += distance[i];
        }*/
        if (start < destination)//当起点不需要越过0点时
        {
            for (int i = start; i < destination; i++)//顺时针路径
            {
                sum += distance[i];
            }
        }
        else if (start > destination)//当起点需要越过0点
        {
            for (int i = start; i < distance.size(); i++)
            {
                sum += distance[i];
            }
            for (int i = 0; i < destination; i++)
            {
                sum += distance[i];
            }
        }
        Bsum -= sum;
        return sum > Bsum ? Bsum : sum;
        
    }
};
int main()
{
    Solution So;
    vector<int> Array={ 7,10,1,12,11,14,5,0 };
    std::cout << So.distanceBetweenBusStops(Array, 7, 2);
}
/*
[7,10,1,12,11,14,5,0]
7
2

17
*/