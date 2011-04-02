/* 
 * File:   Stack.h
 * Author: doghmen
 *
 * Created on 31 mars 2011, 16:55
 */

#ifndef STACK_H
#define	STACK_H

template <class ItemType>
struct StackNode {
    ItemType data;
    StackNode<ItemType> *next;
};

template <class ItemType>
class Stack {

public:
    Stack();
    Stack(const Stack& orig);
    virtual ~Stack();
    void push(const ItemType);
    ItemType pop();
    ItemType top() const;
    void clear();
    bool isEmpty() const;
    bool isFull() const;
    int count() const;

private:

    StackNode<ItemType> *head;
    int counter;
};

#endif	/* STACK_H */

