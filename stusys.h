//
// Created by 邱添爽 on 2017/12/25.
//

#ifndef DSEXP4_STUSYS_H
#define DSEXP4_STUSYS_H


#include "HashTable.h"

class stusys {
private:
    HashTable* hs;
public:
    stusys();
    void Insert();
    void Find();
    void Add();
    void Delete();
    void Print();
    void Save();
};


#endif //DSEXP4_STUSYS_H
