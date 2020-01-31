/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PaternGroups.h
 * Author: Levy David<davidl@onehourtranslation.com>
 *
 * Created on September 4, 2019, 4:00 PM
 */

#ifndef PATERNSGROUPS_H
#define PATERNSGROUPS_H

#include "Pattern.h"
#include "GeneratePatterns.h"

class PatternsGroups {
    int *groups;
    int groupCount;
    const Pattern*(*groupsTable)[9]; // 8+1, extra cell for terminating null
    const GeneratePatterns& paterns;

    void findGroups() {
        const int trans[8][2][2] = {
            {
                {1, 0},
                {0, 1}
            },
            {
                {-1, 0},
                {0, 1}
            },
            {
                {1, 0},
                {0, -1}
            },
            {
                {-1, 0},
                {0, -1}
            },
            // -----------------------------------
            {
                {0, 1},
                {1, 0}
            },
            {
                {0, 1},
                {-1, 0}
            },
            {
                {0, -1},
                {1, 0}
            },
            {
                {0, -1},
                {-1, 0}
            },
        };
        groupCount = 0;
        for (int i = 0; i < paterns.getPaternCount(); i++) {
            if (groups[i] != -1) {
                continue; // already in a group
            }
            const Pattern& cpatern = paterns[i];
            //cout << "---------------------------" << endl;
            //cpatern.print();
            //cout << "---------------------------" << endl;
            groupCount++;
            for (int m = 0; m < 8; m++) {
                Pattern p(cpatern);
                p *= trans[m];
                const PatternsHash::Hash& h = paterns[p];
                //p.print();
                groups[h.id] = i;
                //     cout << " " << h.id << " belongs to group of " << i << endl;
            }
        }

    }

    void sortPaterns() {
        groupsTable = new const Pattern*[groupCount][9];

        int *groupMap = new int[ paterns.getPaternCount()];
        int *groupPos = new int[groupCount];
        int currGroup = 0;
        for (int i = 0; i < groupCount; i++) {
            groupPos[i] = 0;
        }
        for (int i = 0; i < paterns.getPaternCount(); i++) {

            if (groups[i] == i) {
                groupMap[i] = currGroup++;
            } else {
                groupMap[i] = groupMap[groups[i]];
            }
            groupsTable[groupMap[i]][groupPos[groupMap[i]]++] = &paterns[i];
        }
        for (int i = 0; i < groupCount; i++) {
            groupsTable[i][groupPos[i]] = NULL;
        }

        delete[] groupPos;
        delete[] groupMap;
    }
public:

    PatternsGroups(GeneratePatterns& paterns) : groupsTable(NULL), groups(NULL), groupCount(0), paterns(paterns) {
        groups = new int[paterns.getPaternCount()];
        for (int i = 0; i < paterns.getPaternCount(); i++) {
            groups[i] = -1;
        }
        findGroups();
        sortPaterns();
        for (int i = 0; i < groupCount; i++) {
            cout << "------------------\n";
            int pos = 0;
            while (groupsTable[i][pos]) {
                groupsTable[i][pos++]->print();
                cout << "........\n";
            }
        }
        cout << paterns.getPaternCount() << " " << groupCount << endl;


    }

    int getGroupCount() const {
        return groupCount;
    }

    const Pattern** operator[](int index) const {
        return groupsTable[index];
    }

    ~PatternsGroups() {
        delete[] groups;
        delete[] groupsTable;
    }
};

#endif /* PATERNGROUPS_H */

