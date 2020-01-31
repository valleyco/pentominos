/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Point.h
 * Author: Levy David<davidl@onehourtranslation.com>
 *
 * Created on August 28, 2019, 7:51 AM
 */

#ifndef POINT_H
#define POINT_H

class Point {
    int x;
    int y;

public:

    Point() : x(0), y(0) {
    };

    Point(int x, int y) : x(x), y(y) {
    }

    inline int getX() const {
        return x;
    }

    inline int getY() const {
        return y;
    }

    inline Point& setX(const int v) {
        this->x = v;
        return *this;
    }

    inline Point& setY(const int v) {
        y = v;
        return *this;
    }

    inline Point operator+(const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    inline Point& operator=(const Point& p) {
        x = p.getX();
        y = p.getY();
        return *this;
    }

    inline Point& operator+=(const Point& p) {
        x += p.getX();
        y += p.getY();
        return *this;
    }

    inline Point& operator*=(const int m[2][2]) {
        int tx = getX() * m[0][0] + getY() * m[1][0];
        int ty = getX() * m[0][1] + getY() * m[1][1];
        x = tx;
        y = ty;
        return *this;
    }

    inline Point operator*(const int m[2][2]) {
        int px = getX() * m[0][0] + getY() * m[1][0];
        int py = getX() * m[0][1] + getY() * m[1][1];
        return Point(px, py);
    }


};

#endif /* POINT_H */

