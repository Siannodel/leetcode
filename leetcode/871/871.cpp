// 871.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
		priority_queue<int, vector<int>, less<int> > pq;
		stations.push_back({ target, 0 });
		int current_fuel = startFuel;
		int current_x = 0;
		int count = 0;
		for (int i = 0; i < stations.size(); ++i)
		{
			current_fuel -= stations[i][0] - current_x;
			while (current_fuel < 0)
			{
				if (pq.empty()) return -1;
				current_fuel += pq.top();
				pq.pop();
				++count;
			}
			pq.push(stations[i][1]);
			current_x = stations[i][0];
		}
		return count;
	}
};
int main()
{
	int target = 100;
	int startFuel = 10;
	vector<vector<int> > stations = { {10,60}, {20,30}, {30,30}, {60,40} };
	Solution s;
	int result = s.minRefuelStops(target, startFuel, stations);
	cout << result << endl;
	system("pause");
    return 0;
}

