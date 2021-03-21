#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    void helper1(vector<string> &ans, int id, int n, int j)
    {
        if (n == 0)
        {
            //
            return;
        }

        helper1(ans, id, n, j);
        helper1(ans, id|(1 >> j), n-1, j);
        return;
    }
    vector<string> readBinaryWatch(int num) {

    }
};