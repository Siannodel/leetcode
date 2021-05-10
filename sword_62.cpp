#include <list>
#include <iostream>
using namespace std;

class Solution {
public:
    int lastRemaining(int n, int m) {
        list<int> l;
        for(int i = 0; i < n; i++)
        {
            l.push_back(i);
        }
        auto it = l.begin();
        int tmp = -1;
        while(l.size()>1)
        {
            for (int i = 1; i < m; i++)
            {
                cout << *it << endl;
                it++;
                if (it == l.end())
                {
                    it = l.begin();
                }
            }
            cout << "erase: " << *it << endl;
            it = l.erase(it);
            if (it == l.end())
            {
                it = l.begin();
            }
            cout << "size: " << l.size() << endl;
        }
        return *l.begin();
    }
};

int main()
{
    Solution sol;
    sol.lastRemaining(5,3);
}