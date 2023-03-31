//
//  LinkList.hpp
//  Data Structure and algorithm
//
//  Created by Hongyu Chen on 2023/3/21.
//

#include "Header.h"

#ifndef LinkList_hpp
#define LinkList_hpp

typedef int ElemType;

typedef struct Lnode
{
    ElemType data;
    struct Lnode *next;
} Lnode, *LinkList;

Status GetElem_L(LinkList L, int i, ElemType &e);

Status ListInsert_L(LinkList L, int i, ElemType e);

Status ListDelete_L(LinkList L, int i, ElemType &e);

void CreateList_L1(LinkList &L, int n);
void CreateList_L2(LinkList &L, int n);

LinkList LocateElem_L(LinkList L, ElemType e);

void ListReverse_L1(LinkList L);
void ListReverse_L2(LinkList L);

void PrintList_L(LinkList L);

void DeleteElem_L(LinkList L, ElemType e);

LinkList MergeList_L(LinkList L1, LinkList L2);

void RangeDelete(LinkList L, ElemType mink, ElemType maxk);

int call_LinkList(int argc, const char *argv[]);

#endif /* LinkList_hpp */
