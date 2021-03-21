#include <vector>
#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;
//运行超时
class Solution 
{
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) 
    {
        vector <int> v(N, -1);
        v[K-1] = 0;
        queue<int> q;
        q.push(K);
        while(!q.empty()) 
        {
            int n1 = q.front();
            q.pop();
            for (auto t : times)
            {
                if (t[0] == n1)
                {
                    int n2 = t[1];
                    if (v[n2-1] == -1 || v[n2-1] > v[n1-1]+t[2])
                    {
                        v[n2-1] = v[n1-1]+t[2];
                        q.push(n2);
                    }
                }
            }
        }
        int result = 0;
        for (auto t : v)
        {
            if (t==-1) return -1;
            if (result < t) result = t;
        }
        return result;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        //创建图
        K = K - 1;
        vector<vector <int> > graph(N, vector<int> (N, INT_MAX));
        for(int i = 0; i<N; ++i) graph[i][i] = 0;
        for(auto e : times) graph[e[0]-1][e[1]-1] = e[2];
        vector<bool> visited(N, false);
        visited[K] = true;

        for(int i = 0; i < N; ++i)
        {
            //遍历每个节点，找出距离最短的节点
            int min_id = 0; min_dis = INT_MAX;
            for(int j = 0; j < N; ++j)
            {
                if(visited[j] == false && graph[K][j] < min_dis)
                {
                    min_dis = graph[K][j];
                    min_id = j;
                }
            }
            visited[min_id] = true;
            //遍历更新最短距离
            for(int j = 0; j < N; ++j)
            {
                if(graph[K][min_id] + graph[min_id][j] < graph[K][j])
                {
                    graph[K][j] = graph[K][min_id] + graph[min_id][j];
                }
            }

        }

        int ans = 0;
        for (int i = 0; i < N; ++i)
        {
            if (graph[K][i] == INT_MAX) return -1;
            ans = max(ans, graph[K][i]);
        }
        return ans;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dis(N+1, -1);
        dis[K] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int,int> > >pq;
        pq.emplace(0,K);

        //创建一个优先队列，每次寻找被处理的终点作为起点的边，检查其是否为最短路径，将其加入到优先队列中
        while(!pq.empty()) 
        {
            auto e = pq.top();
            pq.pop();
            if (e.first > dis[e.second]) continue;
            for(auto edge : times)
            {
                if(edge[0] == e.second)
                {
                    int v = edge[1];
                    int d = e.first + edge[2];
                    if(dis[v] == -1 || dis[v] > d)
                    {
                        dis[v] = d;
                        pq.emplace(d, v);
                    }
                }
            }
        }

        int ans=0;
        for(int i=1;i<=N;i++){
            if(dis[i]==-1) return -1;
            ans=max(ans,dis[i]);
        }
        return ans;
    }
};