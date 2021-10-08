//
// Created by 22126 on 2021/10/7.
//

#define main07 main07

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

#define random(a, b) (rand()%(b-a)+a)

using namespace std;

extern int rSelectNum(int *array, int startIndex, int endIndex, int num);

int main07() {
    int a[20] = {13, 12, 11, 1, 16, 5, 13, 20, 19, 20, 20, 10, 11, 19, 3, 17, 11, 20, 17, 17};

    cout << rSelectNum(a, 0, 20, 1);
    return 0;

}


int rSelectNum(int *array, int startIndex, int endIndex, int num) {

    if (startIndex >= endIndex) {
        return array[startIndex];
    } else {
        int index = random(startIndex, endIndex);
//    将基准元素放在首位
        swap(array[startIndex], array[index]);


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


        if (num == i - 1) {
            return array[i - 1];
        } else if (num > i - 1) {
            rSelectNum(array, i, endIndex, num);
        } else {
            rSelectNum(array, startIndex, i - 1, num);
        }
    }

}








