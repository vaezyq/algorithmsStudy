//
// Created by 22126 on 2021/10/8.
//

//存在问题

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

#define random(a, b) (rand()%(b-a)+a)

#define main08 main08
using namespace std;

int dSelectNum(int *array, int startIndex, int endIndex, int num);

int main08() {
    int a[20] = {13, 12, 11, 1, 16, 5, 13, 20, 19, 20, 20, 10, 11, 19, 3, 17, 11, 20, 17, 17};

    cout << dSelectNum(a, 0, 20, 1);
    return 0;

}


int dSelectNum(int *array, int startIndex, int endIndex, int num) {

    if (startIndex >= endIndex) {
        return array[startIndex];
    } else {


//        改变得到基准与元素的方式

        int *c = new int[num / 5];
        for (int i = 0; i < num / 5; ++i) {
            for (int k = 5 * i; k < 5 * (i + 1); ++k) {
                int count = 0;
                for (int j = 5 * i; j < 5 * (i + 1); ++j) {
                    if (array[k] < array[j]) {
                        count++;
                    }
                }
                if (count == 2) {
                    c[i] = array[k];
                    break;
                }
            }
        }

        int p = dSelectNum(c, 0, num / 5, num / 10);

//    将基准元素放在首位



        int middleIdex = 0;
        for (middleIdex = 0; middleIdex < num; ++middleIdex) {
            if (array[middleIdex] == p) {
                break;
            }
        }
        swap(array[startIndex], array[middleIdex]);


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
            dSelectNum(array, i, endIndex, num);
        } else {
            dSelectNum(array, startIndex, i - 1, num);
        }
    }

}
