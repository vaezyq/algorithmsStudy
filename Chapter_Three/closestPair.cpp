//
// Created by 22126 on 2021/10/7.
//

#include "PairNode.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define main04 main
//产生指定范围内的随机数
#define random(a, b) (rand()%(b-a+1)+a)
#define INFINITE_DISTANCE 65535  //最大距离 表示不可达

#define len 10

PairNode pResult[2];

PairNode *closestPair(PairNode *px, PairNode *py, int &index);


float closestPair(PairNode *p, int length, PairNode &a, PairNode &b, PairNode *py);


int main04() {
//    随机生成一百个点的坐标
    PairNode a, b;


    int index = len;
    PairNode p[len];
    for (int i = 0; i < len; ++i) {
        int num1, num2;
        for (int j = 0; j < 1; ++j) {
            num1 = random(10, 50);
            num2 = random(10, 50);
        }
        p[i] = PairNode(num1, num2);
    }


    for (int i = 0; i < len; ++i) {
        cout << p[i].getX() << " " << p[i].getY() << endl;
    }


//复制得到按照x轴排序的px,按照y轴排序的py
    PairNode px[len], py[len];
    copy(p, p + len, px);
    copy(p, p + len, py);

//    得到分别按X轴和Y轴排序的结果
    sort(px, px + len, PairNode::Xcompare);
    sort(py, py + len, PairNode::Ycompare);

//    cout << "***********";
//    for (int i = 0; i < len; ++i) {
//        cout << px[i].getX() << " " << px[i].getY() << endl;
//    }
//
//    cout << "***********";
//    for (int i = 0; i < len; ++i) {
//        cout << py[i].getX() << " " << py[i].getY() << endl;
//    }

    double distance;
    distance = closestPair(px, index, a, b, py);
    cout << sqrt(distance) << endl;

    cout << "********" << endl;
    distance = PairNode::distance(p[0], p[1]);
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            distance = min(distance, PairNode::distance(p[i], p[j]));
        }
    }
    cout << sqrt(distance);

    return 0;


}


float closestPair(PairNode *p, int length, PairNode &a, PairNode &b, PairNode *py) {
    double distance;
    double d1, d2;
    PairNode a1, b1, a2, b2;
    if (length < 2) {
        return INFINITE_DISTANCE;
    } else if (length == 2) {
        a = p[0];
        b = p[1];
        distance = PairNode::distance(a, b);
        return distance;
    } else {
        int divide = length / 2;

        PairNode *Lx = new PairNode[divide];
        PairNode *Ly = new PairNode[length - divide];

        copy(p, p + divide, Lx);
        copy(p + divide, p + length, Ly);

        d1 = closestPair(Lx, divide, a1, b1, py);
        d2 = closestPair(Ly, length - divide, a2, b2, py);

        if (d1 < d2) {
            distance = d1;
            a = a1;
            b = b1;
        }            //记录最近点，最近距离
        else {
            distance = d2;
            a = a2;
            b = b2;
        }

        int i = 0, k = 0;
        double mid = p[(length - 1) / 2].getX();

        PairNode *p3 = new PairNode[length];

        for (i = 0, k = 0; i < length; ++i) {
            if (fabs(py[i].getX() - mid) <= distance) {
                p3[k++] = py[i];
            }
        }

        for (int i = 0; i < k; ++i) {
            for (int j = i + 1; j <= i + 6 && j < k; ++j) {
                if (PairNode::distance(p3[i], p3[j]) < distance) {
                    distance = PairNode::distance(p3[i], p3[j]);
                    a = p3[i];
                    b = p3[j];
                }
            }
        }

        return distance;
    }
}


PairNode *closestPair(PairNode *px, PairNode *py, int &index) {
    if (index <= 3) {
//        用蛮力法返回结果
        double dis = PairNode::distance(px[0], py[0]);
        for (int i = 0; i < index; ++i) {
            for (int j = 0; j < index; ++j) {
                if (PairNode::distance(px[i], py[j]) < dis) {
                    dis = PairNode::distance(px[i], py[j]);
                    pResult[0] = px[i];
                    pResult[1] = py[j];
                }
            }
        }
        return pResult;
    } else {
        int divide = index / 2;

        PairNode *Lx = new PairNode[divide];
        PairNode *Ly = new PairNode[divide];
        PairNode *Rx = new PairNode[divide];
        PairNode *Ry = new PairNode[divide];

        copy(px, px + divide, Lx);
        copy(px + divide, px + index, Rx);


        copy(py, py + divide, Ly);
        copy(py + divide, py + index, Ry);

        PairNode *p1 = closestPair(Lx, Ly, divide);
        PairNode *p2 = closestPair(Rx, Ry, divide);
        double distance = min(PairNode::distance(p1[0], p1[1]), PairNode::distance(p2[0], p2[1]));

// 得到中位元素
        double m = px[divide].getX();
//得到
        vector<PairNode> S;
        for (int i = 0; i < len; ++i) {
            if (fabs(py[i].getX() - m) < sqrt(distance)) {
                S.push_back(py[i]);
            }
        }

        PairNode p3[2];
        pResult[0] = p1[0];
        pResult[1] = p1[1];
        double dminsq = distance;


        for (int i = 0; i < S.size() - 1; ++i) {
            int k = i + 1;

            for (int k = i + 1; k <= i + 6 && k < S.size(); ++k) {
                if (PairNode::distance(S[i], S[k]) < dminsq) {
                    pResult[0] = S[k];
                    pResult[1] = S[i];
                    dminsq = pow((S[k].getY() - S[i].getY()), 2);
                }
            }
        }

        if (PairNode::distance(pResult[0], pResult[1]) == dminsq) {
            return pResult;
        } else if (PairNode::distance(p1[0], p1[1]) == dminsq) {
            return p1;
        } else {
            return p2;
        }

    }


}





