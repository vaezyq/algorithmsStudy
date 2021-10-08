#include<iostream>
#include<vector>

#define main01 main01
//completed

using namespace std;


void sort(vector<int> &, int, int);

void merge_sort(vector<int> &, int, int);


int main01() {
    vector<int> a;
    for (int i = 0; i < 10; ++i) {
        a.push_back(rand() % 100);
    }
    merge_sort(a, 0, a.size() - 1);


    for (int el: a) {
        cout << el << " ";
    }
    return 0;

}


void sort(vector<int> &a, int index_start, int index_end) {

    if (index_start >= index_end) {
        return;
    }

    int mid = (index_start + index_end) / 2;
    sort(a, index_start, mid);
    sort(a, mid + 1, index_end);


    vector<int> d;
    int i = index_start, j = mid + 1;
    for (int k = 0; k < index_end - index_start + 1; k++) {
        if (i <= mid && j <= index_end) {
            if (a[i] > a[j]) {
                d.push_back(a[j]);
                j++;
            } else {
                d.push_back(a[i]);
                i++;
            }
        } else if (i > mid && j <= index_end) {
            d.push_back(a[j]);
            j++;
        } else if (i <= mid && j > index_end) {
            d.push_back(a[i]);
            i++;
        }
    }

    for (int k = index_start; k < index_end; ++k) {
        a[k] = d[k - index_start];
    }
}


void merge_sort(vector<int> &a, int start_index, int end_index) {
    if (start_index >= end_index) {
        return;
    }
    int mid = (start_index + end_index) >> 1;
    merge_sort(a, start_index, mid);
    merge_sort(a, mid + 1, end_index);

    vector<int> d;

    int k = 0, i = start_index, j = mid + 1;
    while (i <= mid && j <= end_index) {
        if (a[i] <= a[j]) {
            d.push_back(a[i++]);
        } else {
            d.push_back(a[j++]);
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

