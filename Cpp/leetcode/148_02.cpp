#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdlib.h>
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
            return head;
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (p2->next != nullptr && p2->next->next != nullptr){
            p1 = p1->next;
            if (p2->next)
                p2 = p2->next->next;
        }
        ListNode* l1 = head;
        ListNode* l2 = p1->next;
        p1->next = nullptr;
        l1 = merge_sort(l1);
        l2 = merge_sort(l2);
        return merge(l1, l2);
    }
    ListNode* sortList(ListNode* head) {
        return merge_sort(head);
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
        
        ListNode* ret = Solution().sortList(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}