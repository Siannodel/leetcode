#include <vector>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        ListNode* node = head;
        while(node)
        {
            if (set.count(node) == 1) return true;
            set.insert(node);
            node = node->next;
        }
        return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast && slow)
        {
            if (fast == slow) return true;
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }
        return false;
    }
};