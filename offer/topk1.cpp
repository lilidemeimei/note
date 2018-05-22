#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int random (int start, int end) {
        return rand()%(end - start) + start;
    }
public:
    void swap(int &x, int &y) {
        int tmp;
        tmp = x;
        x = y;
        y = tmp;
    }
public: 
        int Partion(vector<int> &data, int start, int end) {
            if (start == end) {
                return start;
            }
            int index = random(start, end);
            int small = start;
            swap(data[index], data[end]);
            for (int i = start; i < end ; i++){
                if (data[i] < data[end]) {
                    if (i != small) {
                        swap(data[i], data[small]);
                    }
                    small++;
                }
            }
            swap(data[small], data[end]);
            return small;
        }
public:
    bool check(vector<int> input, int num) {
        bool flag = false;
        int time = 0;
        int len = input.size();
        for(int i=0; i< len ; i++)
        {
            if (input[i] == num) {
                time++;
            }
        }
        if (time > len/2) {
            flag = true;
        }
        return flag;
    }
public:
    int MoreThanHalfNum_Solution(vector<int> input) {
        vector<int> res;
        int len = input.size();
        if (len == 1) {
            return input[0];
        }
        int k = len/2;
        int start = 0;
        int end = len - 1;
        int index = Partion(input, start, end);
        while (index != k) {
            if (index > k) {
                end = index - 1;
                index = Partion(input, start, end);
            } else {
                start = index + 1;
                index = Partion(input, start, end);
            }
        }
        if (!check(input, input[k])) {
            return 0;
        }
        return input[k];
    }
};
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(2);
    v.push_back(9);
    v.push_back(5);
    v.push_back(5);
    v.push_back(4);
    v.push_back(0);
    Solution so;
    int res;
    res = so.MoreThanHalfNum_Solution(v);
    cout<<res;
    //for(int i =0 ; i< 4; i++) {
        //cout<<res[i]<<" ";
    //}
}
