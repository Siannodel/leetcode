#include <string>

using namespace std;

class Solution {
public:

    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; ++i)
        {
            string new_s = "";
            int count = 0;
            char cur_c = s[0];
            for (auto c : s)
            {
                if (cur_c == c)
                {
                    ++count;
                }
                else
                {
                    new_s += to_string(count);
                    new_s.push_back(cur_c);
                    cur_c = c;
                    count = 1;
                } 
            }
            new_s += to_string(count);
            new_s.push_back(cur_c);

            s = new_s;
        }
        return s;
    }
};