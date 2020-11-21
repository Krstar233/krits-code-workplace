#include <algorithm>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr)
            return head;
        vector<int> v;
        ListNode* p = head;
        while (p != nullptr){
            v.push_back(p->val);
            p = p->next;
        }
        sort(v.begin(), v.end());
        head = new ListNode(v[0]);
        p = head;
        for (int i = 1; i < v.size(); i++){
            p->next = new ListNode(v[i]);
            p = p->next;
        }
        return head;
    }
};
int main(){
    
}