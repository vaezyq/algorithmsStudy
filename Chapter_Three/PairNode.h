//
// Created by 22126 on 2021/10/7.
//

#ifndef ALGORITHMSSTUDY_PAIRNODE_H
#define ALGORITHMSSTUDY_PAIRNODE_H


class PairNode {
private:
    int x;
    int y;
public:
    PairNode(int x, int y);

    PairNode() {
        x = 99;
        y = 99;
    };


    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

//    返回两个元素之间的距离

    static double distance(PairNode p1, PairNode p2);

    static bool Xcompare(PairNode p1, PairNode p2);

    static bool Ycompare(PairNode p1, PairNode p2);


};


#endif //ALGORITHMSSTUDY_PAIRNODE_H
