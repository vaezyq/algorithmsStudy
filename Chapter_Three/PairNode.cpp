//
// Created by 22126 on 2021/10/7.
//

#include "PairNode.h"
#include <cmath>

int PairNode::getX() const {
    return x;
}

void PairNode::setX(int x) {
    PairNode::x = x;
}

int PairNode::getY() const {
    return y;
}

void PairNode::setY(int y) {
    PairNode::y = y;
}

PairNode::PairNode(int x, int y) : x(x), y(y) {}


//这里采用的是距离平方
double PairNode::distance(PairNode p1, PairNode p2) {
    return pow((p1.getX() - p2.getX()), 2) + pow((p1.getY() - p2.getY()), 2);
}

bool PairNode::Xcompare(const PairNode p1, const PairNode p2) {
    return p1.getX() < p2.getX();
}

bool PairNode::Ycompare(PairNode p1, PairNode p2) {
    return p1.getY() < p2.getY();
}


