#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int i = 0;
        int j = array[0].size() - 1;
        int len = array.size();
        while (true) {
            if (j >= 0 && i < len) {
                if (target == array[i][j]){
                    return true;
                } else if (target > array[i][j]) {
                    i++;
                } else if (target < array[i][j]) {
                    j--;
                }
            } else {
                return false;
            }
        }
    }
};
int main()
{
    vector<vector<int>> v(4);
    v[0].push_back(1);
    v[0].push_back(2);
    v[0].push_back(8);
    v[0].push_back(9);
    v[1].push_back(2);
    v[1].push_back(4);
    v[1].push_back(9);
    v[1].push_back(12);
    v[2].push_back(4);
    v[2].push_back(7);
    v[2].push_back(10);
    v[2].push_back(13);
    v[3].push_back(6);
    v[3].push_back(8);
    v[3].push_back(11);
    v[3].push_back(15);
    
    Solution so;
    bool res;
    res = so.Find(7, v);
    cout<<res;
    //return 0;
}
