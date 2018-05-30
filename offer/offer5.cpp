#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <stack>
using namespace std;
struct ListNode {
     int val;
     struct ListNode *next;
};
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        stack<ListNode> q;
        while(head != NULL) {
            q.push(*head);
            head = head->next;
        }
        while (!q.empty()) {
            ListNode now = q.top();
            q.pop();
            res.push_back(now.val);
        }
        return res;
    }
public:
    void addToTail(ListNode **pHead, int value)
    {
        ListNode *pNew = new ListNode();
        pNew->val = value;
        pNew->next = NULL;
        if (*pHead == NULL) {
            *pHead = pNew;
        } else {
            ListNode *now = *pHead;
            while(now->next != NULL) {
                now = now->next;
            }
            now->next = pNew;
        }
    }
};
int main()
{
    vector<int> v, res;
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);
    v.push_back(0);
    v.push_back(9);
    v.push_back(5);
    v.push_back(5);
    v.push_back(4);
    v.push_back(0);
    Solution so;
    int len = v.size();
    ListNode *node = NULL;
    for(int i = 0 ; i < len; i++) {
        so.addToTail(&node, v[i]);
    }
    res = so.printListFromTailToHead(node);

    //cout<<res;
    for(int i =0 ; i< len; i++) {
        cout<<res[i]<<" ";
    }
}
