/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GeneratePieces.h
 * Author: Levy David<davidl@onehourtranslation.com>
 *
 * Created on September 2, 2019, 12:15 PM
 */

#ifndef GENERATEPIECES_H
#define GENERATEPIECES_H

#include <iostream>
#include "Pattern.h"
#include "PatternsHash.h"
using namespace std;

class GeneratePatterns {
    static const int PADDING = Pattern::PATERN_LEN - 1;
    bool map[(PADDING * 2 + 1) * (PADDING * 2 + 1)]; // 9 * 9
    PatternsHash paternsHash;
public:

       void generate() {
        Pattern p;
        int x = 0;
        int y = 0;
        p[0].setX(x).setY(y);
        map[mapPos(p[0])] = true;
        searchNext(p, 1);
        cout << getPaternCount() << endl;

    }

    int getPaternCount() const {
        return paternsHash.count();
    }

    const Pattern& operator[](int index) const {
        return paternsHash[index];
    }

    const PatternsHash::Hash& operator[](const Pattern& patern) const {
        return paternsHash[patern];
    }

private:

    inline static int mapPos(const Point& p) {
        return p.getX() + PADDING + (p.getY() + PADDING)* (PADDING * 2 + 1);
    }

    void searchNext(Pattern& piece, int pos) {
        static const Point offset[Pattern::PATERN_LEN - 1] = {Point(-1, 0), Point(0, 1), Point(1, 0), Point(0, -1)};
        if (pos == Pattern::PATERN_LEN) {
            paternsHash.insert(piece);
            return;
        }
        for (int cpos = 0; cpos < pos; cpos++) {
            for (int i = 0; i < Pattern::PATERN_LEN - 1; i++) {
                Point p = piece[cpos] + offset[i];
                int mpos = mapPos(p);
                if (!map[mpos]) {
                    map[mpos ] = true;
                    piece[pos] = p;
                    searchNext(piece, pos + 1);
                    map[mpos] = false;
                }
            }
        }
    }


};


#endif /* GENERATEPIECES_H */

