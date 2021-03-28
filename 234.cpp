
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
    ListNode *left;
    bool traverse(ListNode *right)
    {
        if (right == nullptr)
            return true;
        if (!traverse(right->next))
            return false;
        if (left->val != right->val)
            return false;
        left = left->next;
        return true;
    }
    bool isPalindrome(ListNode *head)
    {
        left = head;
        return traverse(head);
    }
};

class Solution2 {
public:

    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr)
        {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
    ListNode* find_mid_node(ListNode *head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;
        ListNode* mid = find_mid_node(head);
        ListNode* head2 = reverse(mid->next);

        ListNode* p1 = head;
        ListNode* p2 = head2;
        bool res = true;
        while(res && p1 != nullptr && p2 != nullptr)
        {
            if (p1->val != p2->val)
                res = false;
            p1 = p1->next;
            p2 = p2->next;
        }
        mid->next = reverse(head2);
        return res;
    }
};