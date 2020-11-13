
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode* p1 = head;
        ListNode* p2 = head->next;

        ListNode* even_head = p2;
        ListNode* odd_tail = head;
        int count = 0;
        while (p2 != nullptr){
            p1->next = p1->next->next;
            p1 = p2;
            p2 = p2->next;
            count++;
            if (count % 2 && odd_tail->next)
                odd_tail = odd_tail->next;
        }
        odd_tail->next = even_head;
        return head;
    }
};