/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PazzleResolver.h
 * Author: Levy David<davidl@onehourtranslation.com>
 *
 * Created on September 6, 2019, 7:44 AM
 */

#ifndef PAZZLERESOLVER_H
#define PAZZLERESOLVER_H
#include "Pattern.h"
#include "PatternsGroups.h"
#include"PatternPos.h"

class PazzleResolver {
    const int bWidth;
    const int bHeight;
    const PatternsGroups& groups;
    const Pattern*(*groupsTable)[9]; // will hold only relevant pattern (according to width/height)
    PatternPos** pp;
    int* posInGroup;

    Pattern* getNext(int groupId) {
        PatternPos* ppos = pp[groupId];
        if (!ppos) {
            posInGroup[groupId]++;
            const Pattern* pattern = groups[groupId][posInGroup[groupId]];
            if (!pattern) {
                return NULL;
            }
            delete pp[groupId];
            pp[groupId] = new PatternPos(bWidth, bHeight, *pattern);
            return getNext(groupId);
        }
    }
public:

    PazzleResolver(int bWidth, int bHeight, const PatternsGroups& groups) : bWidth(bWidth), bHeight(bHeight), groups(groups) {
        pp = new PatternPos*[groups.getGroupCount()];
        posInGroup = new int[groups.getGroupCount()];
        for (int i = 0; i < groups.getGroupCount(); i++) {
            posInGroup[i] = 0;
         //   pp[i] = new PatternPos();
        }
    }

    void getGroupsPatterns() {
        for (int g = 0; g < groups.getGroupCount(); g++) {
            const Pattern ** pattern = groups[g][0];
            while (*pattern) {
                if((*pattern)->getHeight()<= bHeight  && (*pattern)->getWidth()<=bWidth){
                    
                }
                pattern++;
            }
        }
    }

    ~PazzleResolver() {
        delete [] pp;
        delete [] posInGroup;
    }

    void resolve() {


    }

};


#endif /* PAZZLERESOLVER_H */

