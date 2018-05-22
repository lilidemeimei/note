#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int random (int start, int end) {
    return rand()%(end - start) + start;
}
void swap(int &x, int &y) {
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}
int Partion(int data[], int length, int start, int end) {
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

void QuickSort(int data[], int length, int start, int end) {
    if (start >= end) return;
    int index = Partion(data, length, start, end);
    if (index > start) 
        QuickSort(data, length, start, index - 1);
    if (index < end) {
        QuickSort(data, length, index + 1, end);
    }
}
int main()
{
    int data[8];
    data[0] = 9;
    data[1] = -4;
    data[2] = 8;
    data[3] = 0;
    data[4] = 34;
    data[5] = 5;
    data[6] = 10;
    data[7] = -10;
    QuickSort(data, 8, 0, 7);
    for(int i=0; i < 8; i++) {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}
