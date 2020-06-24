#include <string>
#include <queue>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:

    struct comp{
        bool operator() (pair<char, int> a, pair<char, int> b)
        {
            return a.second < b.second;
        }
    };

    string reorganizeString(string S) {
        vector<int> count(26, 0);
        for (auto it = S.begin(); it != S.end(); ++it)
        {
            count[int(*it-'a')] += 1;   
        }

        priority_queue< pair<char, int>, vector<pair<char, int> >, comp> pq;
        
        for (int i = 0; i < count.size(); ++i)
        {
            if (count[i] > 0)
            {
                pq.emplace(char('a' + i), count[i]);
            }
        }

        auto a = pq.top();
        pq.pop();

        if (a.second > (S.size()+1)/2)
        {
            return "";
        }
        string result = "";
        result.append(1, a.first);
        --a.second;

        while(!pq.empty())
        {
            auto b = pq.top();
            pq.pop();
            result.append(1, b.first);
            --b.second;
            a.swap(b);
            if (b.second > 0)
                pq.push(b);
        }
        if (a.second > 0)
            return "";

        return result;
    }
};