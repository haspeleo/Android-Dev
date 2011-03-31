/* 
 * File:   Stack.cpp
 * Author: doghmen
 * 
 * Created on 31 mars 2011, 16:55
 * http://library.thinkquest.org/C005618/text/binarytrees.htm#
 */

#include "Stack.h"

Stack::Stack() {
}

Stack::Stack(const Stack& orig) {
}

Stack::~Stack() {
}

    Stack(const Stack& orig);
    virtual ~Stack();
    void push(const ItemType);
    ItemType pop();
    ItemType top() const;
    void clear();
    bool isEmpty() const;
    bool isFull() const;
    int count() const;
