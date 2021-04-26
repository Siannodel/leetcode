class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;
        int j = 0;
        while(j < popped.size())
        {
            if (!s.empty() && popped[j] == s.top())
            {
                s.pop();
                j++;
                continue;
            }
            if (i < pushed.size())
            {
                s.push(pushed[i]);
                i++;
                continue;
            }
            if (i >= pushed.size())
            {
                break;
            }
        }
        if (s.empty() && j == popped.size())
        {
            return true;
        }
        return false;
    }
};