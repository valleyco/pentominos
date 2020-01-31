/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PatternPos.h
 * Author: Levy David<davidl@onehourtranslation.com>
 *
 * Created on September 5, 2019, 3:58 PM
 */

#ifndef PATTERNPOS_H
#define PATTERNPOS_H

#include "Pattern.h"

class PatternPos {
    int width;
    int height;
    int stepsX;
    int stepsY;
    int offsetX;
    int offsetY;
    const Pattern* cpattern;
    long bm;
    long cbm;

    /**
     * 
     * @param width
     * @param height
     * @param pattern
     */
    PatternPos(int width, int height, const Pattern* pattern[]) : width(width), height(height), offsetX(0), offsetY(0) {
        cpattern = pattern[0];
        stepsX = width - cpattern->getWidth();
        stepsY = height - cpattern->getHeight();
        bm = cpattern->toBitMap(width);
    }

    operator long() {
        return cbm;
    }

    inline int count() {
        
        return (stepsX<0 || stepsY<0) ? 0 : stepsX * stepsY;
    }

    long operator++() {
        if (++offsetX == stepsX) {
            cbm <<= width;
        } else {
            cbm <<= 1;
        }
    }
};

#endif /* PATTERNPOS_H */

