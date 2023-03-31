//
//  LinkList.cpp
//  Data Structure and algorithm
//
//  Created by Hongyu Chen on 2023/3/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinkList.hpp"

Status GetElem_L(LinkList L, int i, ElemType &e)
{
    LinkList p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i) // 这块是不是条件重复了 都表示的是没找到 是不是写一个就可以了啊
        return ERROR;
    e = p->data;
    return OK;
}

Status ListInsert_L(LinkList L, int i, ElemType e)
{
    LinkList p = L, s;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)
        return ERROR;
    s = (LinkList)malloc(sizeof(Lnode));
    if (!s)
        exit(OVERFLOW);
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete_L(LinkList L, int i, ElemType &e)
{
    LinkList p = L, q;
    int j = 0;
    while (p->next && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (p->next == NULL || j > i - 1)
        return ERROR;
    q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return OK;
}

// 动态建立单链表（头插法）
void CreateList_L1(LinkList &L, int n)
{
    LinkList p;
    L = (LinkList)malloc(sizeof(Lnode));
    if (!L)
        exit(OVERFLOW);
    L->data = 0;
    L->next = NULL;
    printf("Please enter %d elements:\n", n);
    for (int i = n; i > 0; --i)
    {
        p = (LinkList)malloc(sizeof(Lnode));
        if (!p)
            exit(OVERFLOW);
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
}

// 动态建立单链表（尾插法）
void CreateList_L2(LinkList &L, int n)
{
    LinkList p, s;
    L = (LinkList)malloc(sizeof(Lnode));
    if (!L)
        exit(OVERFLOW);
    L->data = 0;
    L->next = NULL;
    s = L;
    printf("Please enter %d elements:\n", n);
    for (int i = 0; i < n; ++i)
    {
        p = (LinkList)malloc(sizeof(Lnode));
        if (!p)
            exit(OVERFLOW);
        scanf("%d", &p->data);
        p->next = NULL;
        s->next = p;
        s = p;
    }
}

LinkList LocateElem_L(LinkList L, ElemType e)
{
    LinkList p = L->next;
    while (p->data != e && p != NULL)
        p = p->next;
    return p;
}

// 单链表原地逆置（头插法）
void ListReverse_L1(LinkList L)
{
    if (L->next)
    {
        LinkList p = L->next, s = p->next;
        p->next = NULL;
        while (s)
        {
            p = s;
            s = s->next;
            p->next = L->next;
            L->next = p;
        }
    }
}

// 单链表原地逆置（尾插法）
void ListReverse_L2(LinkList L)
{
    if (L->next)
    {
        LinkList p, q = L, s = L->next;
        while (s->next)
        {
            p = s;
            while (p->next->next)
                p = p->next;
            q->next = p->next;
            q = p->next;
            p->next = NULL;
        }
        q->next = s;
    }
}

void PrintList_L(LinkList L)
{
    LinkList p = L->next;
    printf("Linked list is:\n");
    while (p)
    {
        if (p->next)
            printf("%d ", p->data);
        else
            printf("%d\n", p->data);
        p = p->next;
    }
}

void DeleteElem_L(LinkList L, ElemType e)
{
    LinkList p = L->next, q = L;
    while (p && p->data != e)
    {
        q = p;
        p = p->next;
    }
    if (p)
    {
        q->next = p->next;
        free(p);
    }
}

LinkList MergeList_L(LinkList L1, LinkList L2)
{
    LinkList p = L1->next, q = L2->next, s;
    L1->next = NULL;
    while (p && q)
    {
        if (p->data > q->data)
        {
            s = q->next;
            q->next = L1->next;
            L1->next = q;
            q = s;
        }
        else
        {
            s = p->next;
            p->next = L1->next;
            L1->next = p;
            p = s;
        }
    }
    while (!p && q)
    {
        s = q->next;
        q->next = L1->next;
        L1->next = q;
        q = s;
    }
    while (!q && p)
    {
        s = p->next;
        p->next = L1->next;
        L1->next = p;
        p = s;
    }
    return L1;
}

void RangeDelete(LinkList L, ElemType mink, ElemType maxk)
{
    LinkList p = L->next, q = L->next, s = L;
    while (p && p->data < mink)
    {
        s = p;
        p = p->next;
    }
    while (p && p->data <= maxk)
        p = p->next;
    q = s->next;
    while (q != p)
    {
        s->next = q->next;
        free(q);
        q = s->next;
    }
}

int call_LinkList(int argc, const char *argv[])
{
    LinkList L_array[10];
    int i = 0, n;
    while (TRUE)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%dth ", j + 1);
            PrintList_L(L_array[j]);
        }
//        printf("Task 0: exit\nTask 1: Create a list\nTask 2: Reverse the list\nTask 3: Delete one element\nTask 4: Merge two lists\nTask 5: Delete elements in the specified range\n");
        printf("You can enter a task number to continue:\n");
        
        int task;
        scanf("%d", &task);
        switch (task)
        {
            case 1:
                LinkList L;
                printf("How many elements would you want in your list?\n");
                scanf("%d", &n);
                CreateList_L2(L, n);
                L_array[i] = L;
                PrintList_L(L_array[i++]);
                break;
                
            case 2:
                printf("Which list do you want to reverse?\n");
                scanf("%d", &n);
                ListReverse_L2(L_array[n - 1]);
                PrintList_L(L_array[n - 1]);
                break;
                
            case 3:
                int e;
                printf("Which list do you want to delete?\n");
                scanf("%d", &n);
                printf("Which element do you want to delete:\n");
                scanf("%d", &e);
                DeleteElem_L(L_array[n - 1], e);
                PrintList_L(L_array[n - 1]);
                break;
                
            case 4:
                int i1, i2;
                printf("Please enter two numbers of the two linked lists needed to merged:\n");
                scanf("%d %d", &i1, &i2);
                PrintList_L(MergeList_L(L_array[i1 - 1], L_array[i2 - 1]));
                break;
                
            case 5:
                ElemType mink, maxk;
                scanf("%d", &n);
                printf("Please the range\n");
                scanf("%d %d", &mink, &maxk);
                RangeDelete(L_array[n - 1], mink, maxk);
                PrintList_L(L_array[n - 1]);
                break;
                
            default:
                break;
        }
        if (task == 0)
            break;
    }
    
    return 0;
}
