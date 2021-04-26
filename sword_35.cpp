class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        unordered_map<Node*, Node*> d;
        Node* new_head = new Node(head->val);
        d[head] = new_head;
        Node* cur = head->next;
        Node* p = new_head;
        while(cur != nullptr)
        {
            p->next = new Node(cur->val);
            d[cur] = p->next;
            p = p->next;
            cur = cur->next;
        }

        Node* p1 = head;
        Node* p2 = new_head;

        while(p1!=nullptr)
        {
            p2->random = d[p1->random];
            p1 = p1->next;
            p2 = p2->next;
        }
        return new_head;
    }
};

class Solution1 {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* p = head;
        while(p != nullptr)
        {
            Node* tmp = p->next;
            p->next = new Node(p->val);
            p->next->next = tmp;
            p = tmp;
        }

        Node* new_head = head->next;
        Node* p1 = head;
        //Node* p2 = new_head;
        while(p1 != nullptr)
        {
            if (p1->random == nullptr)
                p1->next->random = nullptr;
            else
                p1->next->random = p1->random->next;
            p1 = p1->next->next;
        }

        p1 = head;
        Node* p2 = new_head;
        while(p1 != nullptr)
        {
            p1->next = p2->next;
            if (p1->next == nullptr)
                break;
            p2->next = p1->next->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        return new_head;
    }
};