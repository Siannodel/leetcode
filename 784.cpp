#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    void helper(vector<string> &ans, string &S, string &cur_s, int i)
    {
        if (i >= S.size())
        {
            ans.push_back(cur_s);
            return;
        }

        cur_s.push_back(S[i]);
        helper(ans, S, cur_s, i+1);
        cur_s.pop_back();
        if (S[i] >= 'a' && S[i] <= 'z')
        {
            cur_s.push_back(S[i]-'a'+'A');
            helper(ans, S, cur_s, i+1);
            cur_s.pop_back();
        }
        else if (S[i] >= 'A' && S[i] <= 'Z')
        {
            cur_s.push_back(S[i]-'A'+'a');
            helper(ans, S, cur_s, i+1);
            cur_s.pop_back();
        }
        return;
    }

    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        string cur_s;
        helper(ans, S, cur_s, 0);
        return ans;
    }
};

class Solution {
public:

    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        int count = 1;
        for(auto c: S)
        {
            if ((c >= 'a' && c <='z') ||(c >= 'A' && c <= 'Z'))
            {
                count <<= 1;
            }
        }

        for (int i = 0; i < count; ++i)
        {
            string tmp_str = "";
            int id = i;
            for(auto c: S)
            {
                if ((c >= 'a' && c <='z') ||(c >= 'A' && c <= 'Z'))
                {
                    if (c >= 'A' && c <= 'Z')
                        c = c - 'A' + 'a';
                    if (id & 1)
                    {
                        tmp_str.push_back(c);
                    }
                    else
                    {
                        tmp_str.push_back(c - 'a' + 'A');
                    }
                    id >>= 1;
                }
                else
                {
                    tmp_str.push_back(c);
                } 
            }
            ans.push_back(tmp_str);
        }

        return ans;
    }
};