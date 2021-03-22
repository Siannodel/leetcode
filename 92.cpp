/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* tmp = nullptr;
    ListNode* reverseN(ListNode* head, int n)
    {
        if (n == 1)
        {
            tmp = head->next;
            return head;
        }
        ListNode* last = reverseN(head->next, n-1);
        head->next->next = head;
        head->next = tmp;
        return last;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1)
        {
            return reverseN(head, right);
        }
        ListNode* last = reverseBetween(head->next, left-1, right-1);
        head->next = last;
        return head;
    }
};