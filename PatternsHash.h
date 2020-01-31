/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PaternsHash.h
 * Author: Levy David<davidl@onehourtranslation.com>
 *
 * Created on September 4, 2019, 1:04 PM
 */

#ifndef PATERNSHASH_H
#define PATERNSHASH_H

#include <iostream>
#include <memory>

#include "Pattern.h"

using namespace std;

class PatternsHash {
public:

    struct Hash {
        int bm;
        int id;
        Pattern* patern;
    };
private:
    const static int HASH_SIZE = 563; // > 4*3*3*3
    int pCount;

    Hash hash[HASH_SIZE];
    Pattern* paterns[HASH_SIZE];
public:

    int count() const {
        return pCount;
    }

    PatternsHash() : pCount(0) {
        for (int i = 0; i < HASH_SIZE; i++) {
            hash[i].bm = 0;
            hash[i].id = -1;
        }

    }
    ~PatternsHash(){
        for (int i = 0; i < pCount; i++) {
            delete paterns[i];
        }
        
    }

    /**
     * Assume that all possible patterns already found
     * @param piece
     * @return index in hash
     */
    const Hash& find(const Pattern& patern) const{
        long bm = patern.toBitMap(5);
        int pos = bm % HASH_SIZE;
        while (true) {
            if (hash[pos].bm == bm) {
                return hash[pos];
            }
            if (hash[pos].bm == 0) {
                cout << "can't find a piece\n";
                patern.print(5);
                exit(-1);
            }
            pos = ++pos % HASH_SIZE;
        }

    }

    /**
     * Will insert a copy of the pattern into the hash
     * In case the pattern exists it will be ignored
     * @param patern
     */
    void insert(const Pattern& patern) {
        Pattern* p = new Pattern(patern);
        p->normalize();
        long bm = p->toBitMap();
        int pos = bm % HASH_SIZE;
        while (true) {
            if (hash[pos].bm == 0) {
                hash[pos].bm = bm;
                hash[pos].patern = p;
                paterns[pCount] = p;
                hash[pos].id = pCount;
                pCount++;
              //  p->print();
              //  cout << "-------------------------" << endl;
                break;
            } else if (hash[pos].bm == bm) {
                delete p;
                break;
            }
            pos = ++pos % HASH_SIZE;
        }
    }

    Pattern& operator[](int index) const {
        return *paterns[index];
    }

    const Hash& operator[](const Pattern& patern) const {
        return find(patern);
    }
};

#endif /* PATERNSHASH_H */

