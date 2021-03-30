
//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head)
    {
        m_head = head;
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        int count = 1;
        ListNode *node = m_head;
        int res = node->val;
        while (node != nullptr)
        {
            if (rand() % count == 1)
            {
                res = node->val;
            }
            node = node->next;
            count++;
        }
        return res;
    }
    ListNode *m_head;
};