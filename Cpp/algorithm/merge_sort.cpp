struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* merge(ListNode* l1, ListNode* l2){
    ListNode* p1 = l1;
    ListNode* p2 = l2;

    ListNode* head = nullptr;
    ListNode* p3 = head;

    while (p1 != nullptr && p2 != nullptr){
        if (p1->val < p2->val){
            if (head == nullptr){
                head = p1;
                p1 = p1->next;
                p3 = head;
                continue;
            }
            p3->next = p1;
            p1 = p1->next;
        }else {
            if (head == nullptr){
                head = p2;
                p2 = p2->next;
                p3 = head;
                continue;
            }
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    if (p1 == nullptr)
        p3->next = p2;
    if (p2 == nullptr)
        p3->next = p1;
    return head;
}
ListNode* merge_sort(ListNode* head){
    if (head == nullptr || head->next == nullptr)
        return;
    ListNode* p1 = head;
    ListNode* p2 = head;
    while (p2 != nullptr && p2->next != nullptr){
        p1 = p1->next;
        if (p2->next)
            p2 = p2->next->next;
    }
    ListNode* l1 = head;
    ListNode* l2 = p1->next;
    p1->next = nullptr;
    merge_sort(l1);
    merge_sort(l2);
    return merge(l1, l2);
}
int main(){
    
}