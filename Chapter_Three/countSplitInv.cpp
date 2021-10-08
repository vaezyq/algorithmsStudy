//
// Created by 22126 on 2021/10/6.
//
//completed

#define main03 main03

#include <vector>
#include <random>
#include <iostream>

using namespace std;


void merge_countSplitInv(vector<int> &a, int start_index, int end_index, int &count);

void countSplitInv(vector<int> &a, int &count);

int main03() {
    int count_merge = 0;
    int count = 0;
    vector<int> a;
    for (int i = 0; i < 10; ++i) {
        a.push_back(rand() % 100);
    }


//    第二个的结果是0，因为第一个已经排序了，如果单独运行，结果也是18
    merge_countSplitInv(a, 0, a.size() - 1, count_merge);
    countSplitInv(a, count);
    cout << count_merge << endl;
    cout << count;
    return 0;


}


void countSplitInv(vector<int> &a, int &count) {
    for (int i = 0; i < a.size() - 1; ++i) {
        for (int j = i + 1; j < a.size(); ++j) {
            if (a[i] > a[j]) {
                count++;

            }

        }
    }

}


void merge_countSplitInv(vector<int> &a, int start_index, int end_index, int &count) {
    if (start_index >= end_index) {
        return;
    }
    int mid = (start_index + end_index) >> 1;
    merge_countSplitInv(a, start_index, mid, count);
    merge_countSplitInv(a, mid + 1, end_index, count);

    vector<int> d;

    int k = 0, i = start_index, j = mid + 1;
    while (i <= mid && j <= end_index) {
        if (a[i] <= a[j]) {
            d.push_back(a[i++]);
        } else {
            d.push_back(a[j++]);
            count += mid - i + 1;
        }
    }

    while (i <= mid) {
        d.push_back(a[i++]);
    }
    while (j <= end_index) {
        d.push_back(a[j++]);
    }

    for (int k = start_index, j = 0; k <= end_index; k++, j++) {
        a[k] = d[j];
    }
}