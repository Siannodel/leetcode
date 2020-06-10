#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

class Solution
{
public:
    int racecar(int target)
    {      
        int x = 0;
        int pre_x = 0;
        int v = 1;
        int t = 0;
        while (x < target)
        {
            pre_x = x;
            x += v;
            v *= 2;
            ++t;
        }
        if (x == target)
            return t;
        else
        {
            return min(racecar(x-target)+1, racecar(target-pre_x)+2);
        }
    }
};