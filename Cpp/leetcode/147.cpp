#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* p = head;
        ListNode* p_next = nullptr;
        ListNode* p_pre = nullptr;
        if (head != nullptr){
            p_next = p->next;
        }
        while (p_next != nullptr){
            p_pre = p;
            p = p_next;
            //cout << p->val << endl;
            if (p != nullptr)
                p_next = p->next;
            if (head->val > p->val){
                p_pre->next = p->next;
                p->next = head;
                head = p;
                p = p_pre;
                continue;
            }
            ListNode* q = head;
            while (q->next && q->next != p && q->next->val < p->val){
                q = q->next;
                //cout << q->val << endl;
            }
            if (q == p_pre)
                continue;
            p_pre->next = p->next;
            p->next = q->next;
            q->next = p;
            p = p_pre;
        }
        return head;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        
        ListNode* ret = Solution().insertionSortList(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}