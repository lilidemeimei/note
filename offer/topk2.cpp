#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
using namespace std;
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input,int k) {
        int len = input.size();
        vector<int> v;
        if (len <= 0 || k > len) return v;
        multiset<int, greater<int>> greaterHeap;
        multiset<int, greater<int>>::iterator theMax;
        for (int i=0; i < len; i++) {
            if (i < k) {
                greaterHeap.insert(input[i]);
            } else {
                theMax = greaterHeap.begin();
                if (input[i] < *theMax) {
                    greaterHeap.erase(theMax);
                    greaterHeap.insert(input[i]);
                }
            }
        }
        return vector<int>(greaterHeap.begin(), greaterHeap.end());
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
    res = so.GetLeastNumbers_Solution(v, 4);
    //cout<<res;
    //for(int i =0 ; i< 4; i++) {
        //cout<<res[i]<<" ";
    //}
}
