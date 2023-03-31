//
//  LinkQueue.hpp
//  Data Structure and algorithm
//
//  Created by Hongyu Chen on 2023/3/31.
//

#ifndef LinkQueue_hpp
#define LinkQueue_hpp

#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

typedef int QElemType;

typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

#endif /* LinkQueue_hpp */
