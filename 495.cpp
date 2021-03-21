#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.size() == 0) return 0;
        int now = timeSeries[0];
        int sum = 0;
        for (int i = 0; i < timeSeries.size(); ++i){
            if (timeSeries[i] + duration <= now){
                continue;
            }
            else if (timeSeries[i] >= now){
                sum += duration;
                now = timeSeries[i] + duration;
            }
            else{
                sum += timeSeries[i] + duration - now;
                now = timeSeries[i] + duration;
            }
        }
        return sum;
    }
};

int main(){
    Solution s;

    vector<int> t1 = {1,2};
    int d1 = 2;
    cout<< s.findPoisonedDuration(t1,d1) << endl;
    system("pause");
    return 0;
}