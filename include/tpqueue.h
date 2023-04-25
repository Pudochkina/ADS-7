// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <iostream>
#include <string>

template<typename T>
class TPQueue {
 private:
    struct QItem {
        T data;
        QItem * next;
        QItem * prev;
    };
    QItem * head, * tail;
    TPQueue::QItem * create(const T& data) {
        QItem * item = new QItem;
        item -> data = data;
        item -> next = nullptr;
        item -> prev = nullptr;
        return item;
    }
 public:
    T pop() {
        if (head) {
            QItem * temp = head -> next;
            if (temp)
                temp -> prev = nullptr;
            T data = head -> data;
            delete head;
            head = temp;
            return data;
        } else 
            throw std::string ("Empty!");
        
    }
    void push (const T& data) {
        QItem * temp = head;
        QItem * item = create (data);
        while (temp && temp -> data.prior >= data.prior)
            temp = temp -> next;
        if (!temp && head) {
            tail -> next = item;
            tail -> next -> prev = tail;
            tail = item;
        } else if (!temp && !head) 
            head = tail = item;
          else if (!temp -> prev) {
            temp -> prev = item;
            item -> next = temp;
            head = item;
        } else {
            temp -> prev -> next = item;
            item -> prev = temp -> prev;
            item -> next = temp;
            temp -> prev = item;
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
