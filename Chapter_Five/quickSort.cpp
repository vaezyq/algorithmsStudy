//
// Created by 22126 on 2021/10/8.
// completed

#include <iostream>
#include <random>

#define main06 main06
using namespace std;

#define random(a, b) (rand()%(b-a)+a)

void pivotQuickSort(int *array, int startIndex, int endIndex);

int main06() {
    int a[20] = {13, 12, 11, 1, 16, 5, 13, 20, 19, 20, 20, 10, 11, 19, 3, 17, 11, 20, 17, 17};
    //       随机数种子
//    srand((int) time(0));
//    cout << "test";
//    for (int i = 0; i < 20; ++i) {
//        a[i] = random(1, 21);
//    }


    pivotQuickSort(a, 0, 20);


    for (int i = 0; i < 20; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}


void pivotQuickSort(int *array, int startIndex, int endIndex) {

    if (startIndex >= endIndex) {
        return;
    } else {
        int index = random(startIndex, endIndex);
//    将基准元素放在首位
        swap(array[startIndex], array[index]);

//        int i = startIndex, j = endIndex - 1;
//        while (i < j) {
//            while (array[j] >= array[startIndex] && i < j)
//                j--;
//            while (array[i] <= array[startIndex] && i < j)
//                i++;
//            if (i < j) {
//                swap(array[i], array[j]);
//            }
//        }




        int i = startIndex + 1, j = startIndex + 1;
        while (j < endIndex) {
            if (array[j] < array[startIndex]) {
                swap(array[j], array[i]);
                i++;
            }
            j++;
        }
        swap(array[startIndex], array[i - 1]);
//        注意这两个递归的范围

        pivotQuickSort(array, startIndex, i - 1);
        pivotQuickSort(array, i, endIndex);

    }

}