/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Levy David<davidl@onehourtranslation.com>
 *
 * Created on August 28, 2019, 7:50 AM
 */

#include <cstdlib>
#include "Point.h"
#include "Pattern.h"
#include "GeneratePatterns.h"
#include "PatternsGroups.h"
#include "PatternPos.h"
#include "PazzleResolver.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    GeneratePatterns gen;
    gen.generate();
    PatternsGroups groups(gen);
    

    return 0;
}

