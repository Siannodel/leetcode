#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
struct comp
{
    bool operator()(ListNode* a, ListNode* b) 
    {
        return a->val > b->val;
    }
};

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<ListNode*, vector<ListNode*>, comp> q;
        for (size_t i = 0; i < lists.size(); ++i)
        {
            if (lists[i] != NULL)
                q.push(lists[i]);
        }

        ListNode root(-1);
        ListNode* tmp = &root;
        while(!q.empty())
        {
            tmp->next = q.top();
            tmp = tmp->next;
            q.pop();
            if (tmp->next != NULL)
            {
                q.push(tmp->next);
            }
        }
        return root.next;
    }
};