/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Piece.h
 * Author: Levy David<davidl@onehourtranslation.com>
 *
 * Created on August 28, 2019, 8:59 AM
 */

#ifndef PATERN_H
#define PATERN_H

using namespace std;

#include <iostream>

#include "Point.h"

class Pattern {
    Point point[5];
    int width;
    int height;
public:
    static const int PATERN_LEN = 5;

    Pattern() {

    }

    Pattern(const Pattern& patern) {
        for (int i = 0; i < PATERN_LEN; i++) {
            point[i] = patern[i];
        }
    }

    Point& operator[](int x) {
        return point[x];
    }
    
    Point operator[](int x) const{
        return point[x];
    }

    inline int getHeight() const {
        return height;
    }

    inline int getWidth() const {
        return width;
    }

    void normalize() {
        int minX = point[0].getX();
        int minY = point[0].getY();
        int maxX = point[0].getX();
        int maxY = point[0].getY();
        for (int i = 1; i < PATERN_LEN; i++) {
            minX = minX > point[i].getX() ? point[i].getX() : minX;
            minY = minY > point[i].getY() ? point[i].getY() : minY;
            maxX = maxX < point[i].getX() ? point[i].getX() : maxX;
            maxY = maxY > point[i].getY() ? point[i].getY() : maxY;
        }
        Point p(-minX, -minY);
        for (int i = 0; i < PATERN_LEN; i++) {
            point[i] += p;
        }
        width = maxX-minX +1;
        height = maxY-minY +1;
    }

    long toBitMap(int width = PATERN_LEN) const {
        long result = 0;
        for (int i = 0; i < PATERN_LEN; i++) {
            result |= (1 << point[i].getX() + point[i].getY() * width);
        }
        return result;
    }

    Pattern& operator*=(const int m[2][2]) {
        for (int i = 0; i < PATERN_LEN; i++) {
            point[i] *= m;
        }
        normalize();
        return *this;
    }
    void print(int width = PATERN_LEN) const{
        int i = 0;
        int bitmap = toBitMap(width);
        while (bitmap) {
            cout << ((bitmap & 1) ? "⬜" : " ");
            bitmap >>= 1;
            if ((++i % width) == 0) {
                cout << endl;
            }
        }
        cout << endl;
    }
    
};

#endif /* PATERN_H */

