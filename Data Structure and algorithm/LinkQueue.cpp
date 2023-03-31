//
//  LinkQueue.cpp
//  Data Structure and algorithm
//
//  Created by Hongyu Chen on 2023/3/31.
//

#include "LinkQueue.hpp"

Status InitQueue(LinkQueue &Q) {
    // 构造一个空队列Q
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front)
        exit(OVERFLOW);
    Q.front->next = NULL;
    return OK;
}

Status DestoryQueue(LinkQueue &Q) {
    // 销毁队列Q
    while (Q.front) {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
    return OK;
}

Status EnQueue(LinkQueue &Q, QElemType e) {
    // 插入元素e为Q的新的队尾元素
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
        exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}
