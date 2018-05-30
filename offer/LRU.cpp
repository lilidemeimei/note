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
class LRUCache {
public:
    LRUCache(int capacity) {
        
    }
    
    int get(int key) {
        
    }
    
    void put(int key, int value) {
        
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
